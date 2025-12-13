#ifndef TUTORWINDOW_H
#define TUTORWINDOW_H

#include <QDialog>

namespace Ui {
class TutorWindow;
}

class TutorWindow : public QDialog
{
    Q_OBJECT

public:
    // Aquí recibimos el ID del tutor
    explicit TutorWindow(int idTutor, QWidget *parent = nullptr);

    // ESTA ES LA LÍNEA QUE TE FALTA (El Destructor)
    ~TutorWindow();

private slots:
    void on_bntEmitirAlerta_clicked();

private:
    Ui::TutorWindow *ui;
    int idTutorLogueado; // Variable para guardar quién ha entrado
};

#endif // TUTORWINDOW_H
