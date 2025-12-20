#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestorbd.h"
#include "Estudiante.h"
#include "Tutor.h"
#include <QMessageBox> // Para mostrar mensajes de alerta
#include <QHeaderView>
#include "loginwindow.h"
#include <QDebug>
#include <QInputDialog> // <--- Revisa que tengas este
#include <QSqlQuery>
#include <QSqlError>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //CÓDIGO DE TU COMPAÑERO (Asignaciones) ---
    ui->tablaAsignaciones->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    GestorBD gestor;
    QStringList facultades = gestor.obtenerListaFacultades();
    ui->cmbFacultad->addItems(facultades);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCalcular_clicked()
{
    // 1. OBTENER DATOS DE LA BD
    GestorBD gestor;
    QList<Tutor> tutores = gestor.obtenerTutoresDisponibles();
    QList<Estudiante> estudiantes = gestor.obtenerEstudiantesSinTutor();

    // 2. PREPARAR INTERFAZ
    ui->tablaAsignaciones->setRowCount(0);

    // Leer filtros de la pantalla
    QString facultadSeleccionada = ui->cmbFacultad->currentText();
    bool filtrarPorFacultad = (facultadSeleccionada != "--- TODAS LAS FACULTADES ---");


    // Contadores para el resumen final
    int procesados = 0;
    int asignados = 0;
    int fallidos = 0;

    // 3. BUCLE DE ESTUDIANTES
    for (const Estudiante &est : estudiantes) {

        // --- APLICAR FILTROS (Lo que le faltaba a tu código) ---
        if (filtrarPorFacultad && est.titulacion != facultadSeleccionada) continue;


        procesados++;
        bool fueAsignado = false;

        // Crear fila
        int fila = ui->tablaAsignaciones->rowCount();
        ui->tablaAsignaciones->insertRow(fila);

        // Nombre visible
        QString textoEst = QString("%1 (Curso %2 - %3)").arg(est.nombre).arg(est.curso).arg(est.titulacion);
        QTableWidgetItem *itemEst = new QTableWidgetItem(textoEst);
        QTableWidgetItem *itemProm = new QTableWidgetItem(QString::number(est.promedio));
        QTableWidgetItem *itemTut = nullptr;

        // 4. BUSCAR TUTOR
        for (int i = 0; i < tutores.size(); ++i) {
            Tutor &tutor = tutores[i];

            // Comparación robusta (ignora mayúsculas y espacios)
            bool mismaFacultad = (est.titulacion.trimmed().compare(tutor.departamento.trimmed(), Qt::CaseInsensitive) == 0);

            if (mismaFacultad && tutor.tieneCupo()) {
                // Asignar
                tutor.cupoActual++;

                // Mostrar cupo visualmente (Ej: "Prof. Garcia [1/5]")
                QString infoCupo = QString(" [%1/%2]").arg(tutor.cupoActual).arg(tutor.cupoMaximo);
                itemTut = new QTableWidgetItem(tutor.nombre + infoCupo);

                // Guardar ID del Tutor (Oculto)
                itemTut->setData(Qt::UserRole, tutor.id);

                fueAsignado = true;
                break;
            }
        }

        // 5. GESTIÓN DE RESULTADO
        if (fueAsignado) {
            asignados++;
        } else {
            // Marcar en Rojo
            itemTut = new QTableWidgetItem("SIN TUTOR (Lleno/No compatible)");
            itemTut->setForeground(Qt::red);
            QFont f = itemTut->font(); f.setBold(true); itemTut->setFont(f);
            itemTut->setData(Qt::UserRole, 0); // ID 0
            fallidos++;
        }

        // --- CRÍTICO: Guardar el ID del estudiante (Faltaba en tu código) ---
        itemEst->setData(Qt::UserRole, est.id);

        // Insertar en tabla
        ui->tablaAsignaciones->setItem(fila, 0, itemEst);
        ui->tablaAsignaciones->setItem(fila, 1, itemProm);
        ui->tablaAsignaciones->setItem(fila, 2, itemTut);
    }

    // 6. ACTUALIZAR ETIQUETA DE RESUMEN
    ui->lblResumen->setText(QString("Procesados: %1 | Asignados: %2 | Sin Tutor: %3")
                                .arg(procesados).arg(asignados).arg(fallidos));

    // 7. ACTIVAR BOTÓN CONFIRMAR (Solo si hay datos)
    if (ui->tablaAsignaciones->rowCount() > 0) {
        ui->btnConfirmar->setEnabled(true);
    } else {
        QMessageBox::information(this, "Info", "No se encontraron alumnos con esos filtros.");
    }
}
void MainWindow::on_btnConfirmar_clicked()
{
    QMap<int, int> datosParaGuardar;

    for(int i = 0; i < ui->tablaAsignaciones->rowCount(); ++i) {
        int idEst = ui->tablaAsignaciones->item(i, 0)->data(Qt::UserRole).toInt();
        int idTut = ui->tablaAsignaciones->item(i, 2)->data(Qt::UserRole).toInt();

        // --- SEGURIDAD NUEVA ---
        // Si el ID del tutor es 0 (Sin Asignar), saltamos esta fila y no la guardamos
        if (idTut == 0) {
            continue;
        }

        datosParaGuardar.insert(idEst, idTut);
    }

    // ... (El resto del código sigue igual: llamar al gestor y mostrar mensaje)
    GestorBD gestor;
    if (gestor.confirmarAsignaciones(datosParaGuardar)) {
        QMessageBox::information(this, "Éxito", "Se han guardado las asignaciones válidas.");
        ui->tablaAsignaciones->setRowCount(0);
        ui->btnConfirmar->setEnabled(false);
    } else {
        QMessageBox::critical(this, "Error", "No se pudo conectar con la base de datos.");
    }
}


void MainWindow::on_btnCerrarSesion_clicked()
{
    // 1. Cerramos la ventana actual (Coordinador)
    this->close();

    // 2. Creamos una nueva instancia del Login y la mostramos
    LoginWindow *login = new LoginWindow();
    login->setAttribute(Qt::WA_DeleteOnClose); // Para que se borre de la memoria al cerrarse
    login->show();
}


void MainWindow::on_btnReset_clicked()
{
    // Preguntamos antes de borrar para evitar accidentes
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Reiniciar Datos",
                                  "¿Estás seguro?\nEsto borrará todas las asignaciones y dejará a los alumnos libres.",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        GestorBD gestor;
        if (gestor.reiniciarDatos()) {
            QMessageBox::information(this, "Reiniciado", "Base de datos reseteada correctamente.");

            // Limpiamos la interfaz visual
            ui->tablaAsignaciones->setRowCount(0);
            ui->lblResumen->setText("Sistema listo.");
            ui->btnConfirmar->setEnabled(false);

        } else {
            QMessageBox::critical(this, "Error", "No se pudieron reiniciar los datos.");
        }
    }
}



void MainWindow::on_btnVolver_clicked()
{
    this->close(); // Cierra la ventana actual (y dispara la señal de "terminado")
}

