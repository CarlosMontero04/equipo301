#ifndef VENTANAALERTAS_H
#define VENTANAALERTAS_H

#include <QDialog>

namespace Ui {
class VentanaAlertas;
}

class VentanaAlertas : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaAlertas(QWidget *parent = nullptr);
    ~VentanaAlertas();

private slots:
    // ESTA LÍNEA ES LA QUE TE FALTA Y LA QUE DA EL ERROR:
    void on_btnGestionar_clicked();

    void on_btnVolver_clicked();

private:
    Ui::VentanaAlertas *ui;
};

#endif // VENTANAALERTAS_H
