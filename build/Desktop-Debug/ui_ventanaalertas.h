/********************************************************************************
** Form generated from reading UI file 'ventanaalertas.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAALERTAS_H
#define UI_VENTANAALERTAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VentanaAlertas
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tablaAlertas;
    QPushButton *btnGestionar;
    QPushButton *btnVolver;

    void setupUi(QDialog *VentanaAlertas)
    {
        if (VentanaAlertas->objectName().isEmpty())
            VentanaAlertas->setObjectName("VentanaAlertas");
        VentanaAlertas->resize(705, 501);
        verticalLayout = new QVBoxLayout(VentanaAlertas);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(VentanaAlertas);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        tablaAlertas = new QTableWidget(VentanaAlertas);
        tablaAlertas->setObjectName("tablaAlertas");

        verticalLayout->addWidget(tablaAlertas);

        btnGestionar = new QPushButton(VentanaAlertas);
        btnGestionar->setObjectName("btnGestionar");

        verticalLayout->addWidget(btnGestionar);

        btnVolver = new QPushButton(VentanaAlertas);
        btnVolver->setObjectName("btnVolver");

        verticalLayout->addWidget(btnVolver);


        retranslateUi(VentanaAlertas);

        QMetaObject::connectSlotsByName(VentanaAlertas);
    } // setupUi

    void retranslateUi(QDialog *VentanaAlertas)
    {
        VentanaAlertas->setWindowTitle(QCoreApplication::translate("VentanaAlertas", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("VentanaAlertas", "GESTI\303\223N DE RIESGOS", nullptr));
        btnGestionar->setText(QCoreApplication::translate("VentanaAlertas", "Resolver Alerta", nullptr));
        btnVolver->setText(QCoreApplication::translate("VentanaAlertas", "Volver atras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaAlertas: public Ui_VentanaAlertas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAALERTAS_H
