#include "menuestudiante.h"
#include "ui_menuestudiante.h"
#include "loginwindow.h"
#include <QMessageBox>

MenuEstudiante::MenuEstudiante(int idEst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuEstudiante),
    idEstudiante(idEst)
{
    ui->setupUi(this);
    db = new GestorBD();
    chatWindow = nullptr;

    // Obtener datos
    m_nombreTutor = db->obtenerNombreTutor(idEstudiante);
    idTutor = db->obtenerIdTutorDeEstudiante(idEstudiante);

    ui->lblTutorAsignado->setText("Tu tutor asignado es: " + m_nombreTutor);

    // Si no tiene tutor (devuelve -1 o 0), bloqueamos
    if(idTutor <= 0) {
        ui->btnEscribirMensaje->setEnabled(false);
        ui->lblTutorAsignado->setText("No tienes tutor asignado aún.");
    }
}

MenuEstudiante::~MenuEstudiante()
{
    delete ui;
    if(chatWindow) delete chatWindow;
    delete db;
}

// --- IR AL CHAT ---
void MenuEstudiante::on_btnEscribirMensaje_clicked()
{
    // Si la ventana no existe, la creamos
    if (!chatWindow) {
        chatWindow = new ChatWindow(idEstudiante, "Estudiante", idTutor, "Tutor", m_nombreTutor, this);
        // Conectamos la señal de volver
        connect(chatWindow, &ChatWindow::volverMenu, this, &MenuEstudiante::alCerrarChat);
    }

    // 1. IMPORTANTE: Antes de cambiar, capturamos cómo está el menú (Maximized, FullScreen, etc.)
    Qt::WindowStates estadoActual = this->windowState();

    // 2. Se lo aplicamos a la ventana del chat
    chatWindow->setWindowState(estadoActual);

    chatWindow->show();
    this->hide();
}

// --- VOLVER DEL CHAT AL MENÚ ---
void MenuEstudiante::alCerrarChat() {
    // 1. Si el chat sigue existiendo (que debería), capturamos su estado antes de que desaparezca
    if(chatWindow) {
        Qt::WindowStates estadoDelChat = chatWindow->windowState();

        // 2. Aplicamos ese estado a ESTE menú (para que si maximizaste el chat, el menú vuelva maximizado)
        this->setWindowState(estadoDelChat);
    }

    this->show();
}

// --- CERRAR SESIÓN (IR AL LOGIN) ---
void MenuEstudiante::on_btnCerrarSesion_clicked()
{
    // 1. Capturamos el estado actual del menú
    Qt::WindowStates estadoActual = this->windowState();

    // 2. Cerramos el menú
    this->close();

    // 3. Preparamos el login
    LoginWindow *login = new LoginWindow();

    // 4. Le aplicamos el estado (para que no se encoja)
    login->setWindowState(estadoActual);

    login->show();
}
