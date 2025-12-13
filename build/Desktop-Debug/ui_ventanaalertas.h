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

QT_BEGIN_NAMESPACE

class Ui_VentanaAlertas
{
public:
    QLabel *label;
    QTableWidget *tablaAlertas;
    QPushButton *btnGestionar;
    QPushButton *btnVolver;

    void setupUi(QDialog *VentanaAlertas)
    {
        if (VentanaAlertas->objectName().isEmpty())
            VentanaAlertas->setObjectName("VentanaAlertas");
        VentanaAlertas->resize(705, 501);
        label = new QLabel(VentanaAlertas);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 50, 201, 18));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        tablaAlertas = new QTableWidget(VentanaAlertas);
        tablaAlertas->setObjectName("tablaAlertas");
        tablaAlertas->setGeometry(QRect(5, 100, 691, 271));
        btnGestionar = new QPushButton(VentanaAlertas);
        btnGestionar->setObjectName("btnGestionar");
        btnGestionar->setGeometry(QRect(290, 390, 121, 26));
        btnVolver = new QPushButton(VentanaAlertas);
        btnVolver->setObjectName("btnVolver");
        btnVolver->setGeometry(QRect(10, 460, 88, 26));

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
