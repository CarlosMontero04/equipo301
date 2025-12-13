#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h" // Para abrir la ventana del Coordinador
#include "gestorbd.h"   // Para conectar a la BD
#include <QMessageBox>
#include <QSqlQuery>
#include "tutorwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    // Opcional: Poner el foco en el campo de usuario al iniciar
    ui->txtUsuario->setFocus();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

// Esta función se ejecuta al pulsar el botón "Entrar" (btnLogin)
void LoginWindow::on_btnLogin_clicked()
{
    QString usuario = ui->txtUsuario->text();
    QString pass = ui->txtPassword->text();

    // 1. Validar que no estén vacíos
    if (usuario.isEmpty() || pass.isEmpty()) {
        QMessageBox::warning(this, "Aviso", "Por favor, introduzca usuario y contraseña.");
        return;
    }

    // 2. Conectar a la Base de Datos
    GestorBD gestor;
    if (!gestor.conectar()) {
        QMessageBox::critical(this, "Error de Conexión", "No se pudo conectar a la base de datos.");
        return;
    }

    QSqlQuery query;

    // ---------------------------------------------------------
    // NIVEL 1: ¿ES COORDINADOR? (Tabla 'coordinadores')
    // ---------------------------------------------------------
    query.prepare("SELECT id FROM coordinadores WHERE email_uco = :u AND password = :p");
    query.bindValue(":u", usuario);
    query.bindValue(":p", pass);

    if (query.exec() && query.next()) {
        // ¡Es Coordinador!
        this->hide(); // Ocultamos login

        // ABRIMOS EL MENÚ QUE ACABAS DE CREAR
        MenuCoordinador *menu = new MenuCoordinador(this);
        menu->setAttribute(Qt::WA_DeleteOnClose);
        menu->show();

        //gestor.cerrar();-> borrado para la bbdd
        return;
    }

    // ---------------------------------------------------------
    // NIVEL 2: ¿ES TUTOR? (Tabla 'tutores')
    // ---------------------------------------------------------
    query.prepare("SELECT id, nombre FROM tutores WHERE email_uco = :u AND password = :p");
    query.bindValue(":u", usuario);
    query.bindValue(":p", pass);

    if (query.exec() && query.next()) {
        // 1. Guardamos el ID del tutor para usarlo luego
        int idTutor = query.value("id").toInt();
        QString nombreTutor = query.value("nombre").toString();

        // 2. Ocultamos el login
        this->hide();

        // 3. Abrimos la ventana del Tutor
        TutorWindow *ventana = new TutorWindow(idTutor, this);
        ventana->setAttribute(Qt::WA_DeleteOnClose);
        ventana->setWindowTitle("Bienvenido, " + nombreTutor);
        ventana->show();

        //gestor.cerrar();
        return;
    }

    // ---------------------------------------------------------
    // NIVEL 3: ¿ES ESTUDIANTE? (Tabla 'estudiantes')
    // ---------------------------------------------------------
    query.prepare("SELECT id, nombre FROM estudiantes WHERE email_uco = :u AND password = :p");
    query.bindValue(":u", usuario);
    query.bindValue(":p", pass);

    if (query.exec() && query.next()) {
        // ¡Es Estudiante!
        QString nombre = query.value("nombre").toString();
        QMessageBox::information(this, "Acceso Estudiante", "Hola, " + nombre + ".\n(Aquí se abrirá el Chat)");

        // AQUÍ ABRIRÍAS LA VENTANA DE CHAT DE TU COMPAÑERO

        gestor.cerrar();
        return;
    }

    // ---------------------------------------------------------
    // SI LLEGA AQUÍ -> NO SE ENCONTRÓ EL USUARIO
    // ---------------------------------------------------------
    QMessageBox::warning(this, "Acceso Denegado", "El usuario o la contraseña son incorrectos.");
    gestor.cerrar();
}
