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
#include "loginwindow.h"

TutorWindow::TutorWindow(int idTutor, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TutorWindow),
    idTutorLogueado(idTutor)
{
    ui->setupUi(this);
    chatWindow = nullptr; // <--- Inicializamos el puntero a nulo

    QSqlQuery query;
    query.prepare("SELECT id, nombre FROM estudiantes WHERE id_tutor = :id");
    query.bindValue(":id", idTutorLogueado);

    if (query.exec()) {
        while (query.next()) {
            QString nombre = query.value("nombre").toString();
            int idAlumno = query.value("id").toInt();
            // Aquí guardamos el ID oculto (UserRole)
            ui->comboAlumnos->addItem(nombre, idAlumno);
        }
    } else {
        QMessageBox::critical(this, "Error", "Error al cargar alumnos:\n" + query.lastError().text());
    }
}

TutorWindow::~TutorWindow()
{
    delete ui;
    // Si la ventana de chat está abierta al cerrar esta, la borramos para liberar memoria
    if(chatWindow) delete chatWindow;
}

// --- NUEVA FUNCIÓN PARA ABRIR EL CHAT ---
void TutorWindow::on_btnContactar_clicked()
{
    // 1. Verificar si hay un alumno seleccionado en el desplegable
    if (ui->comboAlumnos->currentIndex() == -1) {
        QMessageBox::warning(this, "Aviso", "Por favor, selecciona un alumno de la lista primero.");
        return;
    }

    // 2. Recuperar los datos del alumno seleccionado
    // currentText() nos da el nombre visible
    QString nombreAlumno = ui->comboAlumnos->currentText();
    // currentData() nos da el ID oculto que guardamos en el constructor
    int idAlumno = ui->comboAlumnos->currentData().toInt();

    // 3. Crear y mostrar el chat
    // Si ya había una ventana abierta, la cerramos y creamos una nueva
    if (chatWindow) {
        delete chatWindow;
    }

    // Constructor: (miId, miRol, otroId, otroRol, nombreOtro, parent)
    chatWindow = new ChatWindow(idTutorLogueado, "Tutor", idAlumno, "Estudiante", nombreAlumno, this);
    chatWindow->show();
}

void TutorWindow::on_bntEmitirAlerta_clicked()
{
    if (ui->comboAlumnos->currentIndex() == -1) {
        QMessageBox::warning(this, "Aviso", "No tienes alumnos asignados para emitir alertas.");
        return;
    }

    int idEstudiante = ui->comboAlumnos->currentData().toInt();

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

    if (dialogo.exec() == QDialog::Accepted) {
        QString tipo = comboTipo->currentText();
        QString desc = txtDescripcion->toPlainText();

        if (desc.isEmpty()) {
            QMessageBox::warning(this, "Error", "Debes escribir una descripción.");
            return;
        }

        QSqlQuery query;
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

void TutorWindow::on_btnCerrarSesion_clicked()
{
    // 1. Guardar estado actual del Tutor (ej. si está maximizada)
    Qt::WindowStates estadoActual = this->windowState();

    // 2. Cerrar ventana Tutor
    this->close();

    // 3. Crear Login
    LoginWindow *login = new LoginWindow();

    // 4. Aplicar el estado guardado al Login
    login->setWindowState(estadoActual);

    // 5. Mostrar
    login->show();
}
