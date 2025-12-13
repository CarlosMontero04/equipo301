#include "ventanaalertas.h"
#include "ui_ventanaalertas.h"
#include "gestorbd.h"     // <--- Necesario para base de datos
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

VentanaAlertas::VentanaAlertas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaAlertas)
{
    ui->setupUi(this);

    // 1. Configurar Tabla
    ui->tablaAlertas->setColumnCount(5);
    ui->tablaAlertas->setHorizontalHeaderLabels({"ID", "Alumno", "Riesgo", "Descripción", "Estado"});
    ui->tablaAlertas->setColumnWidth(3, 250);
    ui->tablaAlertas->setSelectionBehavior(QAbstractItemView::SelectRows); // Seleccionar fila entera

    // 2. Cargar Datos
    QSqlQuery query;
    query.prepare("SELECT a.id, e.nombre, a.tipo_riesgo, a.descripcion, a.estado "
                  "FROM alertas a "
                  "JOIN estudiantes e ON a.id_estudiante = e.id "
                  "WHERE a.estado != 'Resuelta'");

    if (query.exec()) {
        int fila = 0;
        while (query.next()) {
            ui->tablaAlertas->insertRow(fila);
            ui->tablaAlertas->setItem(fila, 0, new QTableWidgetItem(query.value("id").toString()));
            ui->tablaAlertas->setItem(fila, 1, new QTableWidgetItem(query.value("nombre").toString()));
            ui->tablaAlertas->setItem(fila, 2, new QTableWidgetItem(query.value("tipo_riesgo").toString()));
            ui->tablaAlertas->setItem(fila, 3, new QTableWidgetItem(query.value("descripcion").toString()));
            ui->tablaAlertas->setItem(fila, 4, new QTableWidgetItem(query.value("estado").toString()));
            fila++;
        }
    }
}

VentanaAlertas::~VentanaAlertas()
{
    delete ui;
}

// Recuerda hacer: Click derecho en botón -> Go to slot -> clicked()
void VentanaAlertas::on_btnGestionar_clicked()
{
    int fila = ui->tablaAlertas->currentRow();
    if (fila < 0) {
        QMessageBox::warning(this, "Aviso", "Selecciona una alerta primero.");
        return;
    }

    QString idAlerta = ui->tablaAlertas->item(fila, 0)->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmar", "¿Marcar como RESUELTA?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("UPDATE alertas SET estado = 'Resuelta' WHERE id = :id");
        query.bindValue(":id", idAlerta);

        if (query.exec()) {
            ui->tablaAlertas->removeRow(fila);
            QMessageBox::information(this, "Hecho", "Alerta cerrada.");
        }
    }
}

void VentanaAlertas::on_btnVolver_clicked()
{
    this->close(); // Cierra la ventana actual (y dispara la señal de "terminado")
}

