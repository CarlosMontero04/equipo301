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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MenuCoordinador
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnIrAlertas;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnIrAsignacion;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCerrarSesion;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *MenuCoordinador)
    {
        if (MenuCoordinador->objectName().isEmpty())
            MenuCoordinador->setObjectName("MenuCoordinador");
        MenuCoordinador->resize(741, 242);
        verticalLayout = new QVBoxLayout(MenuCoordinador);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(MenuCoordinador);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        btnIrAlertas = new QPushButton(MenuCoordinador);
        btnIrAlertas->setObjectName("btnIrAlertas");

        verticalLayout->addWidget(btnIrAlertas);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        btnIrAsignacion = new QPushButton(MenuCoordinador);
        btnIrAsignacion->setObjectName("btnIrAsignacion");

        verticalLayout->addWidget(btnIrAsignacion);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        btnCerrarSesion = new QPushButton(MenuCoordinador);
        btnCerrarSesion->setObjectName("btnCerrarSesion");

        verticalLayout->addWidget(btnCerrarSesion);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(MenuCoordinador);

        QMetaObject::connectSlotsByName(MenuCoordinador);
    } // setupUi

    void retranslateUi(QDialog *MenuCoordinador)
    {
        MenuCoordinador->setWindowTitle(QCoreApplication::translate("MenuCoordinador", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MenuCoordinador", "MENU COORDINADOR", nullptr));
        btnIrAlertas->setText(QCoreApplication::translate("MenuCoordinador", "Gesti\303\263n Alertas", nullptr));
        btnIrAsignacion->setText(QCoreApplication::translate("MenuCoordinador", "Asignaci\303\263n autom\303\241tica", nullptr));
        btnCerrarSesion->setText(QCoreApplication::translate("MenuCoordinador", "Cerrar Sesi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuCoordinador: public Ui_MenuCoordinador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCOORDINADOR_H
