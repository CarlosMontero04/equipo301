#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestorbd.h"
#include "Estudiante.h"
#include "Tutor.h"
#include <QMessageBox> // Para mostrar mensajes de alerta

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCalcular_clicked()
{
    // 1. Instanciamos nuestro gestor para hablar con la BD
    GestorBD gestor;

    // 2. Obtenemos los datos (Paso 3 del Escenario)
    QList<Estudiante> estudiantes = gestor.obtenerEstudiantesSinTutor();
    QList<Tutor> tutores = gestor.obtenerTutoresDisponibles();

    // ESCENARIO ALTERNATIVO 3a: No hay alumnos pendientes
    if (estudiantes.isEmpty()) {
        QMessageBox::information(this, "Información", "No hay estudiantes pendientes de asignación.");
        return;
    }

    if (tutores.isEmpty()) {
        QMessageBox::warning(this, "Aviso", "No hay tutores disponibles en la base de datos.");
        return;
    }

    // 3. Preparar la tabla visual (Limpiarla antes de rellenar)
    ui->tablaAsignaciones->setRowCount(0); // Borra filas anteriores

    // 4. Algoritmo de Asignación (Paso 4 del Escenario)
    // Recorremos cada estudiante (ya vienen ordenados por nota desde la BD)
    for (const Estudiante &est : estudiantes) {
        bool asignado = false;

        // Buscamos un tutor con hueco para este estudiante
        for (int i = 0; i < tutores.size(); ++i) {
            // Usamos una referencia (&) para modificar el cupoActual de la lista en memoria
            Tutor &tutor = tutores[i];

            if (tutor.tieneCupo()) {
                // --- ¡ASIGNACIÓN ENCONTRADA! ---

                // A. Insertamos una nueva fila en la tabla visual
                int fila = ui->tablaAsignaciones->rowCount();
                ui->tablaAsignaciones->insertRow(fila);

                // B. Creamos las celdas con el texto visible
                QTableWidgetItem *itemEst = new QTableWidgetItem(est.nombre);
                QTableWidgetItem *itemProm = new QTableWidgetItem(QString::number(est.promedio));
                QTableWidgetItem *itemTut = new QTableWidgetItem(tutor.nombre);

                // C. TRUCO IMPORTANTE: Guardamos los IDs ocultos en las celdas
                // Esto nos servirá luego para el botón "Guardar"
                itemEst->setData(Qt::UserRole, est.id);   // Guardamos ID Estudiante oculto
                itemTut->setData(Qt::UserRole, tutor.id); // Guardamos ID Tutor oculto

                // D. Ponemos las celdas en la tabla
                ui->tablaAsignaciones->setItem(fila, 0, itemEst);
                ui->tablaAsignaciones->setItem(fila, 1, itemProm);
                ui->tablaAsignaciones->setItem(fila, 2, itemTut);

                // E. Actualizamos el cupo del tutor EN MEMORIA (para que no le asignen más de la cuenta)
                tutor.cupoActual++;
                asignado = true;
                break; // Rompemos el bucle de tutores, pasamos al siguiente estudiante
            }
        }

        // Si salimos del bucle y no se asignó (ej. no quedan cupos en ningún tutor)
        if (!asignado) {
            // Opcional: Podríamos mostrarlo en rojo o avisar
            // Por ahora simplemente no lo añadimos a la tabla de "propuestas"
        }
    }

    // 5. Habilitar el botón de confirmar (Paso 5 del Escenario)
    // Solo si se ha generado al menos una asignación
    if (ui->tablaAsignaciones->rowCount() > 0) {
        ui->btnConfirmar->setEnabled(true);
        QMessageBox::information(this, "Cálculo Finalizado",
                                 "Se han calculado las asignaciones óptimas.\nRevise la tabla y pulse 'Confirmar' para guardar.");
    } else {
        QMessageBox::warning(this, "Atención", "No se han podido realizar asignaciones (¿Quizás no hay cupo en los tutores?)");
    }
}

void MainWindow::on_btnConfirmar_clicked()
{
    // 1. Recopilar datos de la tabla visual
    QMap<int, int> datosParaGuardar;

    // Recorremos fila por fila
    for(int i = 0; i < ui->tablaAsignaciones->rowCount(); ++i) {
        // Recuperamos los IDs ocultos (UserRole) de las celdas
        // Columna 0 = Estudiante, Columna 2 = Tutor (según tu diseño)
        int idEst = ui->tablaAsignaciones->item(i, 0)->data(Qt::UserRole).toInt();
        int idTut = ui->tablaAsignaciones->item(i, 2)->data(Qt::UserRole).toInt();

        datosParaGuardar.insert(idEst, idTut);
    }

    // 2. Enviar a la Base de Datos
    GestorBD gestor;
    if (gestor.confirmarAsignaciones(datosParaGuardar)) {
        // ÉXITO (Paso 8 del escenario principal)
        QMessageBox::information(this, "Éxito", "Asignaciones guardadas correctamente en la base de datos.");

        // Limpiamos la interfaz
        ui->tablaAsignaciones->setRowCount(0);
        ui->btnConfirmar->setEnabled(false);

    } else {
        // ERROR (Escenario de excepción 3b o similar)
        QMessageBox::critical(this, "Error", "Hubo un error al guardar en la base de datos.\nSe han deshecho los cambios.");
    }
}

