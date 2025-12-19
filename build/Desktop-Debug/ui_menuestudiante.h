/********************************************************************************
** Form generated from reading UI file 'menuestudiante.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUESTUDIANTE_H
#define UI_MENUESTUDIANTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MenuEstudiante
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *lblTutorAsignado;
    QSpacerItem *verticalSpacer;
    QPushButton *btnCerrarSesion;
    QPushButton *btnEscribirMensaje;

    void setupUi(QDialog *MenuEstudiante)
    {
        if (MenuEstudiante->objectName().isEmpty())
            MenuEstudiante->setObjectName("MenuEstudiante");
        MenuEstudiante->resize(400, 300);
        verticalLayout = new QVBoxLayout(MenuEstudiante);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(MenuEstudiante);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        verticalLayout->addWidget(label);

        lblTutorAsignado = new QLabel(MenuEstudiante);
        lblTutorAsignado->setObjectName("lblTutorAsignado");
        QFont font1;
        font1.setPointSize(9);
        lblTutorAsignado->setFont(font1);

        verticalLayout->addWidget(lblTutorAsignado);

        verticalSpacer = new QSpacerItem(20, 162, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnCerrarSesion = new QPushButton(MenuEstudiante);
        btnCerrarSesion->setObjectName("btnCerrarSesion");

        verticalLayout->addWidget(btnCerrarSesion);

        btnEscribirMensaje = new QPushButton(MenuEstudiante);
        btnEscribirMensaje->setObjectName("btnEscribirMensaje");

        verticalLayout->addWidget(btnEscribirMensaje);


        retranslateUi(MenuEstudiante);

        QMetaObject::connectSlotsByName(MenuEstudiante);
    } // setupUi

    void retranslateUi(QDialog *MenuEstudiante)
    {
        MenuEstudiante->setWindowTitle(QCoreApplication::translate("MenuEstudiante", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MenuEstudiante", "Panel de Estudiante", nullptr));
        lblTutorAsignado->setText(QCoreApplication::translate("MenuEstudiante", "Cargando informaci\303\263n del tutor...", nullptr));
        btnCerrarSesion->setText(QCoreApplication::translate("MenuEstudiante", "Cerrar Sesi\303\263n", nullptr));
        btnEscribirMensaje->setText(QCoreApplication::translate("MenuEstudiante", "Contactar con Tutor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuEstudiante: public Ui_MenuEstudiante {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUESTUDIANTE_H
