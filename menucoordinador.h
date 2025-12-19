#ifndef MENUCOORDINADOR_H
#define MENUCOORDINADOR_H

#include <QDialog>
#include "mainwindow.h"
#include "ventanaalertas.h"

namespace Ui {
class MenuCoordinador;
}

class MenuCoordinador : public QDialog
{
    Q_OBJECT

public:
    explicit MenuCoordinador(QWidget *parent = nullptr);
    ~MenuCoordinador();

private slots:
    void on_btnIrAsignacion_clicked();

    void on_btnIrAlertas_clicked();

    void on_btnCerrarSesion_clicked();

private:
    Ui::MenuCoordinador *ui;
};

#endif // MENUCOORDINADOR_H
