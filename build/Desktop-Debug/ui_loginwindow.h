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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *txtUsuario;
    QLabel *label_2;
    QLineEdit *txtPassword;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnLogin;
    QPushButton *btnSalir;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(730, 500);
        verticalLayout = new QVBoxLayout(LoginWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(LoginWindow);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        txtUsuario = new QLineEdit(LoginWindow);
        txtUsuario->setObjectName("txtUsuario");

        verticalLayout->addWidget(txtUsuario);

        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        txtPassword = new QLineEdit(LoginWindow);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(txtPassword);

        verticalSpacer_2 = new QSpacerItem(20, 303, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btnLogin = new QPushButton(LoginWindow);
        btnLogin->setObjectName("btnLogin");

        verticalLayout->addWidget(btnLogin);

        btnSalir = new QPushButton(LoginWindow);
        btnSalir->setObjectName("btnSalir");

        verticalLayout->addWidget(btnSalir);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "E-mail uco", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Contrase\303\261a", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginWindow", "Entrar", nullptr));
        btnSalir->setText(QCoreApplication::translate("LoginWindow", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
