/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *label;
    QLineEdit *txtUsuario;
    QLabel *label_2;
    QLineEdit *txtPassword;
    QPushButton *btnLogin;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(730, 500);
        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 140, 91, 18));
        txtUsuario = new QLineEdit(LoginWindow);
        txtUsuario->setObjectName("txtUsuario");
        txtUsuario->setGeometry(QRect(220, 160, 281, 26));
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 200, 101, 18));
        txtPassword = new QLineEdit(LoginWindow);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setGeometry(QRect(220, 220, 281, 26));
        txtPassword->setEchoMode(QLineEdit::Password);
        btnLogin = new QPushButton(LoginWindow);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(310, 280, 88, 26));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "E-mail uco", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Contrase\303\261a", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginWindow", "Entrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
