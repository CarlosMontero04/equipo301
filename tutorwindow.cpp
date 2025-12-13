#include "tutorwindow.h"
#include "ui_tutorwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QInputDialog>
#include <QDialog>
#include <QFormLayout>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QTextEdit>

// 1. Constructor: Aquí recibimos el ID y lo guardamos
TutorWindow::TutorWindow(int idTutor, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TutorWindow),
    idTutorLogueado(idTutor) // Guardamos el ID en nuestra variable
{
    ui->setupUi(this);

    // --- CÓDIGO NUEVO: CARGAR ALUMNOS ---
    QSqlQuery query;
    // Buscamos alumnos que tengan asignado ESTE tutor (id_tutor = idTutorLogueado)
    query.prepare("SELECT id, nombre FROM estudiantes WHERE id_tutor = :id");
    query.bindValue(":id", idTutorLogueado);

    if (query.exec()) {
        while (query.next()) {
            QString nombre = query.value("nombre").toString();
            int idAlumno = query.value("id").toInt();

            // Truco: Añadimos el nombre visible, pero guardamos el ID oculto
            ui->comboAlumnos->addItem(nombre, idAlumno);
        }
    } else {
        QMessageBox::critical(this, "Error", "Error al cargar alumnos:\n" + query.lastError().text());
    }
}

// 2. Destructor: Limpieza de memoria
TutorWindow::~TutorWindow()
{
    delete ui;
}

void TutorWindow::on_bntEmitirAlerta_clicked()
{
    // 1. Verificar si hay alumnos cargados
    if (ui->comboAlumnos->currentIndex() == -1) {
        QMessageBox::warning(this, "Aviso", "No tienes alumnos asignados para emitir alertas.");
        return;
    }

    // 2. Recuperar el ID del alumno seleccionado (el dato oculto)
    int idEstudiante = ui->comboAlumnos->currentData().toInt();

    // 3. Crear el formulario emergente (Tipo y Descripción)
    QDialog dialogo(this);
    dialogo.setWindowTitle("Nueva Alerta de Riesgo");
    QFormLayout form(&dialogo);

    QComboBox *comboTipo = new QComboBox(&dialogo);
    comboTipo->addItems({"Riesgo Académico", "Faltas de Asistencia", "Problemas Personales", "Otros"});
    form.addRow("Tipo de Riesgo:", comboTipo);

    QTextEdit *txtDescripcion = new QTextEdit(&dialogo);
    txtDescripcion->setPlaceholderText("Describe detalladamente la situación...");
    form.addRow("Descripción:", txtDescripcion);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialogo);
    form.addRow(&buttonBox);
    connect(&buttonBox, SIGNAL(accepted()), &dialogo, SLOT(accept()));
    connect(&buttonBox, SIGNAL(rejected()), &dialogo, SLOT(reject()));

    // 4. Si el usuario pulsa OK, guardamos en la BD
    if (dialogo.exec() == QDialog::Accepted) {
        QString tipo = comboTipo->currentText();
        QString desc = txtDescripcion->toPlainText();

        if (desc.isEmpty()) {
            QMessageBox::warning(this, "Error", "Debes escribir una descripción.");
            return;
        }

        QSqlQuery query;
        // Insertamos usando los nombres de tu tabla 'alertas'
        query.prepare("INSERT INTO alertas (id_estudiante, id_tutor, tipo_riesgo, descripcion, fecha, estado) "
                      "VALUES (:est, :tut, :tipo, :desc, NOW(), 'Pendiente')");

        query.bindValue(":est", idEstudiante);
        query.bindValue(":tut", idTutorLogueado);
        query.bindValue(":tipo", tipo);
        query.bindValue(":desc", desc);

        if (query.exec()) {
            QMessageBox::information(this, "Éxito", "Alerta registrada y enviada a Coordinación.");
        } else {
            QMessageBox::critical(this, "Error SQL", "No se pudo guardar:\n" + query.lastError().text());
        }
    }
}

