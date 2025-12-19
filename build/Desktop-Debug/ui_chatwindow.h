/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *lstMensajes;
    QPushButton *btnEnviar;
    QLineEdit *txtMensaje;
    QPushButton *btnVolver;

    void setupUi(QDialog *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName("ChatWindow");
        ChatWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(ChatWindow);
        verticalLayout->setObjectName("verticalLayout");
        lstMensajes = new QListWidget(ChatWindow);
        lstMensajes->setObjectName("lstMensajes");

        verticalLayout->addWidget(lstMensajes);

        btnEnviar = new QPushButton(ChatWindow);
        btnEnviar->setObjectName("btnEnviar");
        btnEnviar->setAutoDefault(false);

        verticalLayout->addWidget(btnEnviar);

        txtMensaje = new QLineEdit(ChatWindow);
        txtMensaje->setObjectName("txtMensaje");

        verticalLayout->addWidget(txtMensaje);

        btnVolver = new QPushButton(ChatWindow);
        btnVolver->setObjectName("btnVolver");
        btnVolver->setAutoDefault(false);

        verticalLayout->addWidget(btnVolver);


        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QDialog *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "Dialog", nullptr));
        btnEnviar->setText(QCoreApplication::translate("ChatWindow", "Enviar", nullptr));
        btnVolver->setText(QCoreApplication::translate("ChatWindow", "Volver", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
