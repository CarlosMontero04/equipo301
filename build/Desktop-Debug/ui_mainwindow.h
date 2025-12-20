/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *cmbFacultad;
    QPushButton *btnReset;
    QLabel *label_2;
    QTableWidget *tablaAsignaciones;
    QLabel *lblResumen;
    QPushButton *btnCalcular;
    QPushButton *btnConfirmar;
    QPushButton *btnVolver;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(842, 912);
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        cmbFacultad = new QComboBox(centralwidget);
        cmbFacultad->setObjectName("cmbFacultad");

        verticalLayout->addWidget(cmbFacultad);

        btnReset = new QPushButton(centralwidget);
        btnReset->setObjectName("btnReset");

        verticalLayout->addWidget(btnReset);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        tablaAsignaciones = new QTableWidget(centralwidget);
        if (tablaAsignaciones->columnCount() < 3)
            tablaAsignaciones->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablaAsignaciones->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablaAsignaciones->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tablaAsignaciones->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tablaAsignaciones->setObjectName("tablaAsignaciones");

        verticalLayout->addWidget(tablaAsignaciones);

        lblResumen = new QLabel(centralwidget);
        lblResumen->setObjectName("lblResumen");

        verticalLayout->addWidget(lblResumen);

        btnCalcular = new QPushButton(centralwidget);
        btnCalcular->setObjectName("btnCalcular");

        verticalLayout->addWidget(btnCalcular);

        btnConfirmar = new QPushButton(centralwidget);
        btnConfirmar->setObjectName("btnConfirmar");
        btnConfirmar->setEnabled(false);

        verticalLayout->addWidget(btnConfirmar);

        btnVolver = new QPushButton(centralwidget);
        btnVolver->setObjectName("btnVolver");
        QFont font2;
        font2.setPointSize(11);
        btnVolver->setFont(font2);

        verticalLayout->addWidget(btnVolver);

        MainWindow->setCentralWidget(centralwidget);
        tablaAsignaciones->raise();
        label->raise();
        btnCalcular->raise();
        btnConfirmar->raise();
        lblResumen->raise();
        cmbFacultad->raise();
        label_2->raise();
        btnReset->raise();
        btnVolver->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 842, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ASIGNACI\303\223N AUTOM\303\201TICA DE TUTORES", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Seleccione Facultad:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tablaAsignaciones->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Estudiante", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tablaAsignaciones->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Promedio", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tablaAsignaciones->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Tutor Propuesto", nullptr));
        lblResumen->setText(QCoreApplication::translate("MainWindow", "Resumen: Esperando c\303\241lculo...", nullptr));
        btnCalcular->setText(QCoreApplication::translate("MainWindow", "CALCULAR ASIGNACI\303\223N", nullptr));
        btnConfirmar->setText(QCoreApplication::translate("MainWindow", "CONFIRMAR Y GUARDAR", nullptr));
        btnVolver->setText(QCoreApplication::translate("MainWindow", "Volver atras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
