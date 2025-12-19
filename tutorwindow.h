#ifndef TUTORWINDOW_H
#define TUTORWINDOW_H

#include <QDialog>
#include "chatwindow.h" // <--- 1. Importante para poder crear el chat

namespace Ui {
class TutorWindow;
}

class TutorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TutorWindow(int idTutor, QWidget *parent = nullptr);
    ~TutorWindow();

private slots:
    void on_bntEmitirAlerta_clicked();
    void on_btnContactar_clicked(); // <--- 2. Slot para el nuevo botón
    void on_btnCerrarSesion_clicked();

private:
    Ui::TutorWindow *ui;
    int idTutorLogueado;
    ChatWindow *chatWindow; // <--- 3. Puntero para gestionar la ventana del chat
};

#endif // TUTORWINDOW_H
