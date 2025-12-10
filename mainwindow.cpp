#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestorbd.h"
#include "Estudiante.h"
#include "Tutor.h"
#include <QMessageBox> // Para mostrar mensajes de alerta
#include <QHeaderView>
#include "loginwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tablaAsignaciones->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCalcular_clicked()
{
    GestorBD gestor;
    QList<Estudiante> estudiantes = gestor.obtenerEstudiantesSinTutor();
    QList<Tutor> tutores = gestor.obtenerTutoresDisponibles();

    ui->tablaAsignaciones->setRowCount(0);
    int alumnosSinAsignar = 0; // Contador para advertencias

    for (const Estudiante &est : estudiantes) {
        bool asignado = false;
        int fila = ui->tablaAsignaciones->rowCount();
        ui->tablaAsignaciones->insertRow(fila);

        // Columnas básicas
        QTableWidgetItem *itemEst = new QTableWidgetItem(est.nombre + " (" + est.titulacion + ")");
        QTableWidgetItem *itemProm = new QTableWidgetItem(QString::number(est.promedio));
        QTableWidgetItem *itemTut = nullptr; // Se decidirá abajo

        // --- LÓGICA DE BÚSQUEDA ---
        for (int i = 0; i < tutores.size(); ++i) {
            Tutor &tutor = tutores[i];

            if (est.titulacion == tutor.departamento && tutor.tieneCupo()) {

                // MEJORA 3: Visualización de Cupos
                // Mostramos [CupoActual / Máximo] para que el coordinador lo vea claro
                tutor.cupoActual++; // Incrementamos temporalmente
                QString infoCupo = QString(" [%1/%2]").arg(tutor.cupoActual).arg(tutor.cupoMaximo);

                itemTut = new QTableWidgetItem(tutor.nombre + infoCupo);
                itemTut->setData(Qt::UserRole, tutor.id); // Guardamos ID Tutor

                asignado = true;
                break;
            }
        }

        // MEJORA 2: Gestión de No Asignados
        if (!asignado) {
            itemTut = new QTableWidgetItem("SIN TUTOR DISPONIBLE");
            // Ponemos el texto en ROJO y Negrita para alertar
            itemTut->setForeground(Qt::red);
            QFont fuente = itemTut->font();
            fuente.setBold(true);
            itemTut->setFont(fuente);

            // Ponemos ID 0 para saber que no es válido
            itemTut->setData(Qt::UserRole, 0);
            alumnosSinAsignar++;
        }

        // Guardamos el ID del estudiante siempre
        itemEst->setData(Qt::UserRole, est.id);

        ui->tablaAsignaciones->setItem(fila, 0, itemEst);
        ui->tablaAsignaciones->setItem(fila, 1, itemProm);
        ui->tablaAsignaciones->setItem(fila, 2, itemTut);
    }

    // Feedback al usuario
    if (alumnosSinAsignar > 0) {
        QMessageBox::warning(this, "Atención",
                             QString("El proceso ha finalizado, pero %1 estudiantes no tienen tutor compatible (por cupo o titulación).").arg(alumnosSinAsignar));
    } else {
        QMessageBox::information(this, "Éxito", "Todos los estudiantes han sido asignados correctamente.");
    }

    if (ui->tablaAsignaciones->rowCount() > 0) {
        ui->btnConfirmar->setEnabled(true);
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

