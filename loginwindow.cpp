#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"      // Se mantiene por compatibilidad si lo usabas
#include "menucoordinador.h" // <--- NECESARIO para abrir el menú de coordinador
#include "gestorbd.h"
#include "tutorwindow.h"
#include "menuestudiante.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QApplication> // <--- NECESARIO para cerrar la aplicación con quit()

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    // Poner el foco en el campo de usuario al iniciar para escribir directo
    ui->txtUsuario->setFocus();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

// --- NUEVO: FUNCION DEL BOTÓN SALIR ---
// Asegúrate de que en tu .ui el botón se llame "btnSalir"
void LoginWindow::on_btnSalir_clicked()
{
    // Cierra la aplicación completamente
    QApplication::quit();
}

// --- LOGICA DE INICIO DE SESIÓN ---
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

    // --- TRUCO: Guardamos si la ventana está maximizada o normal ---
    Qt::WindowStates estadoVentana = this->windowState();

    // ---------------------------------------------------------
    // NIVEL 1: ¿ES COORDINADOR? (Tabla 'coordinadores')
    // ---------------------------------------------------------
    query.prepare("SELECT id FROM coordinadores WHERE email_uco = :u AND password = :p");
    query.bindValue(":u", usuario);
    query.bindValue(":p", pass);

    if (query.exec() && query.next()) {
        // Ocultamos el login
        this->hide();

        // Abrimos el Menú de Coordinador
        MenuCoordinador *menu = new MenuCoordinador(this); // Pasamos 'this' como padre o nullptr
        menu->setAttribute(Qt::WA_DeleteOnClose); // Liberar memoria al cerrar

        // APLICAMOS EL ESTADO VISUAL (Si login estaba maximizado, este también)
        menu->setWindowState(estadoVentana);

        menu->show();
        return;
    }

    // ---------------------------------------------------------
    // NIVEL 2: ¿ES TUTOR? (Tabla 'tutores')
    // ---------------------------------------------------------
    query.prepare("SELECT id, nombre FROM tutores WHERE email_uco = :u AND password = :p");
    query.bindValue(":u", usuario);
    query.bindValue(":p", pass);

    if (query.exec() && query.next()) {
        int idTutor = query.value("id").toInt();
        QString nombreTutor = query.value("nombre").toString();

        this->hide();

        // Abrimos ventana Tutor
        TutorWindow *ventana = new TutorWindow(idTutor, this);
        ventana->setAttribute(Qt::WA_DeleteOnClose);
        ventana->setWindowTitle("Bienvenido, " + nombreTutor);

        // APLICAMOS EL ESTADO VISUAL
        ventana->setWindowState(estadoVentana);

        ventana->show();
        return;
    }

    // ---------------------------------------------------------
    // NIVEL 3: ¿ES ESTUDIANTE? (Tabla 'estudiantes')
    // ---------------------------------------------------------
    query.prepare("SELECT id FROM estudiantes WHERE email_uco = :u AND password = :p");
    query.bindValue(":u", usuario);
    query.bindValue(":p", pass);

    if (query.exec() && query.next()) {
        int idEstudiante = query.value("id").toInt();

        this->hide();

        // Abrimos Menú Estudiante
        MenuEstudiante *menu = new MenuEstudiante(idEstudiante); // Asumiendo constructor con ID
        menu->setAttribute(Qt::WA_DeleteOnClose);

        // APLICAMOS EL ESTADO VISUAL
        menu->setWindowState(estadoVentana);

        menu->show();
        return;
    }

    // ---------------------------------------------------------
    // SI LLEGA AQUÍ -> NO SE ENCONTRÓ EL USUARIO
    // ---------------------------------------------------------
    QMessageBox::warning(this, "Acceso Denegado", "El usuario o la contraseña son incorrectos.");

    // Cerramos la conexión si falló el login (opcional, GestorBD suele manejarlo en su destructor)
    gestor.cerrar();
}
