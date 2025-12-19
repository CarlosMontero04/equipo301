#include "menucoordinador.h"
#include "ui_menucoordinador.h"
#include "loginwindow.h"

MenuCoordinador::MenuCoordinador(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuCoordinador)
{
    ui->setupUi(this);
}

MenuCoordinador::~MenuCoordinador()
{
    delete ui;
}
// BOTÓN 1: Asignacion automatica
void MenuCoordinador::on_btnIrAsignacion_clicked()
{
    this->hide();

    MainWindow *w = new MainWindow(this);
    w->setAttribute(Qt::WA_DeleteOnClose);

    // La misma línea mágica para conectar el cierre con la reaparición del menú
    connect(w, &QMainWindow::destroyed, this, &QWidget::show);
    // Nota: Como MainWindow suele ser QMainWindow, a veces usa 'destroyed' o hay que redefinir 'closeEvent',
    // pero prueba primero con &QDialog::finished si hereda de Dialog, o &QWidget::close si no.
    // TRUCO SEGURO PARA MAINWINDOW:
    // Si MainWindow hereda de QMainWindow, usa mejor esto:
    // connect(w, &QWidget::destroyed, this, &QWidget::show);

    w->showFullScreen();
}

// BOTÓN 2: Gestion alertas de riesgos
void MenuCoordinador::on_btnIrAlertas_clicked()
{
    this->hide(); // Ocultamos el menú

    VentanaAlertas *v = new VentanaAlertas(this);
    v->setAttribute(Qt::WA_DeleteOnClose); // Importante para limpiar memoria

    // --- ESTA ES LA LÍNEA MÁGICA ---
    // Significa: "Cuando 'v' termine (se cierre), ejecuta 'this->show()' (muéstrame a mí)"
    connect(v, &QDialog::finished, this, &QWidget::show);

    v->showFullScreen();
}


void MenuCoordinador::on_btnCerrarSesion_clicked()
{
    // 1. Cerramos la ventana actual (El Menú de Coordinador)
    this->close();

    // 2. Creamos una NUEVA ventana de Login
    LoginWindow *login = new LoginWindow();

    // (Opcional) Para que se borre de la memoria al cerrarse
    login->setAttribute(Qt::WA_DeleteOnClose);

    // 3. La mostramos
    login->showFullScreen();;
}

