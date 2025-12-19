#ifndef MENUESTUDIANTE_H
#define MENUESTUDIANTE_H

#include <QDialog> // Cambiado de QWidget a QDialog
#include "gestorbd.h"
#include "chatwindow.h"

namespace Ui {
class MenuEstudiante;
}

class MenuEstudiante : public QDialog // Cambiado de QWidget a QDialog
{
    Q_OBJECT

public:
    explicit MenuEstudiante(int idEst, QWidget *parent = nullptr);
    ~MenuEstudiante();

private slots:
    void on_btnEscribirMensaje_clicked();
    void on_btnCerrarSesion_clicked();
    void alCerrarChat();

private:
    Ui::MenuEstudiante *ui;
    GestorBD *db;
    int idEstudiante;
    int idTutor;
    QString m_nombreTutor; // Variable nueva para guardar el nombre
    ChatWindow *chatWindow;
};

#endif // MENUESTUDIANTE_H
