#include "chatwindow.h"
#include "ui_chatwindow.h"
#include <QMessageBox>

ChatWindow::ChatWindow(int miId, QString miRol, int otroId, QString otroRol, QString nombreOtro, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatWindow),
    m_miId(miId), m_miRol(miRol),
    m_otroId(otroId), m_otroRol(otroRol)
{
    ui->setupUi(this);

    // --- MEJORAS FUNCIONALES (Sin CSS) ---

    // 1. Saber con quién hablas: Ponemos el nombre en el marco de la ventana
    this->setWindowTitle("Conversación con " + nombreOtro);

    // 2. Texto "fantasma": Aparece "Escribe un mensaje..." y se borra solo al escribir
    ui->txtMensaje->setPlaceholderText("Escribe un mensaje...");

    // 3. Cursor listo: Al abrir la ventana, el cursor ya está en la caja de texto
    ui->txtMensaje->setFocus();

    // 4. Enviar con ENTER: Conectamos la tecla Enter de la caja de texto con el botón de enviar
    connect(ui->txtMensaje, &QLineEdit::returnPressed, this, &ChatWindow::on_btnEnviar_clicked);

    // -------------------------------------

    // Cargar mensajes al iniciar
    cargarMensajes();

    // Configurar el Timer (refresco automático)
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ChatWindow::cargarMensajes);
    timer->start(2000);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::cargarMensajes()
{
    // 1. Obtenemos la conversación de la BD
    QList<QPair<QString, QString>> mensajes = gestor.obtenerConversacion(m_miId, m_miRol, m_otroId, m_otroRol);

    ui->lstMensajes->clear();

    // IMPORTANTE: Esto permite que si el mensaje es muy largo, baje de línea
    ui->lstMensajes->setWordWrap(true);

    for(const auto &msg : mensajes) {
        QString emisor = msg.first;
        QString contenido = msg.second;

        // 2. Creamos el objeto visual del mensaje
        // Añadimos quién habla y el mensaje
        QString textoMostrar;
        if(emisor == m_miRol) {
            textoMostrar = contenido; // Si soy yo, solo pongo el mensaje (queda más limpio)
        } else {
            textoMostrar = m_otroRol + ": " + contenido; // Si es el otro, pongo su nombre
        }

        QListWidgetItem *item = new QListWidgetItem(textoMostrar);

        // 3. LA MAGIA: Decidimos la alineación
        if(emisor == m_miRol) {
            // Mis mensajes a la DERECHA
            item->setTextAlignment(Qt::AlignRight);
        } else {
            // Sus mensajes a la IZQUIERDA
            item->setTextAlignment(Qt::AlignLeft);
        }

        // 4. Añadimos el item ya configurado a la lista
        ui->lstMensajes->addItem(item);
    }

    // Bajamos el scroll al final
    ui->lstMensajes->scrollToBottom();
}
void ChatWindow::on_btnVolver_clicked()
{
    // Emitimos la señal que acabamos de definir en el .h
    emit volverMenu();

    // Cerramos esta ventana
    this->close();
}


void ChatWindow::on_btnEnviar_clicked()
{
    QString texto = ui->txtMensaje->text().trimmed();
    if(texto.isEmpty()) return;

    if(gestor.enviarMensaje(m_miId, m_miRol, m_otroId, m_otroRol, texto)) {
        ui->txtMensaje->clear();
        cargarMensajes(); // Actualizar inmediatamente
    } else {
        QMessageBox::critical(this, "Error", "No se pudo enviar el mensaje.");
    }
}
