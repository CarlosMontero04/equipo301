#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QDialog>
#include <QTimer>
#include "gestorbd.h"

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QDialog
{
    Q_OBJECT

public:
    // Constructor modificado para recibir quién habla con quién
    explicit ChatWindow(int miId, QString miRol, int otroId, QString otroRol, QString nombreOtro, QWidget *parent = nullptr);
    ~ChatWindow();

signals:
    void volverMenu(); // Esta es la señal que emitiremos al pulsar "Volver"

private slots:
    void on_btnEnviar_clicked();
    void cargarMensajes(); // Slot para refrescar el chat

    // Necesitas este slot para el botón de volver de tu interfaz (.ui)
    void on_btnVolver_clicked();

private:
    Ui::ChatWindow *ui;
    GestorBD gestor;
    QTimer *timer; // Para actualizar el chat automáticamente

    // Datos de la sesión
    int m_miId;
    QString m_miRol;
    int m_otroId;
    QString m_otroRol;
};

#endif // CHATWINDOW_H
