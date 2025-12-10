#include "mainwindow.h"
#include <QApplication>
#include "gestorbd.h" // Incluimos nuestro gestor

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // --- ZONA DE PRUEBA ---
    GestorBD gestor;
    if (gestor.conectar()) {
        QList<Estudiante> est = gestor.obtenerEstudiantesSinTutor();
        qDebug() << "Estudiantes pendientes encontrados:" << est.size();
    }
    // ----------------------

    MainWindow w;
    w.show();
    return a.exec();
}
