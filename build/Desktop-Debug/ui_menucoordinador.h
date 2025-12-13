/********************************************************************************
** Form generated from reading UI file 'menucoordinador.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUCOORDINADOR_H
#define UI_MENUCOORDINADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MenuCoordinador
{
public:
    QLabel *label;
    QPushButton *btnIrAsignacion;
    QPushButton *btnIrAlertas;

    void setupUi(QDialog *MenuCoordinador)
    {
        if (MenuCoordinador->objectName().isEmpty())
            MenuCoordinador->setObjectName("MenuCoordinador");
        MenuCoordinador->resize(741, 242);
        label = new QLabel(MenuCoordinador);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 30, 211, 18));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        btnIrAsignacion = new QPushButton(MenuCoordinador);
        btnIrAsignacion->setObjectName("btnIrAsignacion");
        btnIrAsignacion->setGeometry(QRect(50, 80, 161, 26));
        btnIrAlertas = new QPushButton(MenuCoordinador);
        btnIrAlertas->setObjectName("btnIrAlertas");
        btnIrAlertas->setGeometry(QRect(530, 80, 131, 26));

        retranslateUi(MenuCoordinador);

        QMetaObject::connectSlotsByName(MenuCoordinador);
    } // setupUi

    void retranslateUi(QDialog *MenuCoordinador)
    {
        MenuCoordinador->setWindowTitle(QCoreApplication::translate("MenuCoordinador", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MenuCoordinador", "MENU COORDINADOR", nullptr));
        btnIrAsignacion->setText(QCoreApplication::translate("MenuCoordinador", "Asignaci\303\263n autom\303\241tica", nullptr));
        btnIrAlertas->setText(QCoreApplication::translate("MenuCoordinador", "Gesti\303\263n Alertas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuCoordinador: public Ui_MenuCoordinador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCOORDINADOR_H
