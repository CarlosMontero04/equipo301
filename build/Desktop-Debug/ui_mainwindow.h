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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTableWidget *tablaAsignaciones;
    QPushButton *btnCalcular;
    QPushButton *btnConfirmar;
    QPushButton *btnCerrarSesion;
    QCheckBox *chkSoloPrimero;
    QLabel *lblResumen;
    QComboBox *cmbFacultad;
    QLabel *label_2;
    QPushButton *btnReset;
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
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 7, 401, 41));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label->setFont(font1);
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
        tablaAsignaciones->setGeometry(QRect(30, 280, 751, 401));
        btnCalcular = new QPushButton(centralwidget);
        btnCalcular->setObjectName("btnCalcular");
        btnCalcular->setGeometry(QRect(120, 770, 211, 26));
        btnConfirmar = new QPushButton(centralwidget);
        btnConfirmar->setObjectName("btnConfirmar");
        btnConfirmar->setEnabled(false);
        btnConfirmar->setGeometry(QRect(410, 770, 201, 26));
        btnCerrarSesion = new QPushButton(centralwidget);
        btnCerrarSesion->setObjectName("btnCerrarSesion");
        btnCerrarSesion->setGeometry(QRect(680, 10, 101, 26));
        chkSoloPrimero = new QCheckBox(centralwidget);
        chkSoloPrimero->setObjectName("chkSoloPrimero");
        chkSoloPrimero->setGeometry(QRect(120, 800, 231, 24));
        lblResumen = new QLabel(centralwidget);
        lblResumen->setObjectName("lblResumen");
        lblResumen->setGeometry(QRect(190, 730, 491, 18));
        cmbFacultad = new QComboBox(centralwidget);
        cmbFacultad->setObjectName("cmbFacultad");
        cmbFacultad->setGeometry(QRect(270, 70, 331, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 80, 161, 18));
        btnReset = new QPushButton(centralwidget);
        btnReset->setObjectName("btnReset");
        btnReset->setGeometry(QRect(660, 70, 88, 26));
        btnVolver = new QPushButton(centralwidget);
        btnVolver->setObjectName("btnVolver");
        btnVolver->setGeometry(QRect(10, 830, 111, 26));
        QFont font2;
        font2.setPointSize(11);
        btnVolver->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        tablaAsignaciones->raise();
        label->raise();
        btnCalcular->raise();
        btnConfirmar->raise();
        btnCerrarSesion->raise();
        chkSoloPrimero->raise();
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
        QTableWidgetItem *___qtablewidgetitem = tablaAsignaciones->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Estudiante", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tablaAsignaciones->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Promedio", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tablaAsignaciones->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Tutor Propuesto", nullptr));
        btnCalcular->setText(QCoreApplication::translate("MainWindow", "CALCULAR ASIGNACI\303\223N", nullptr));
        btnConfirmar->setText(QCoreApplication::translate("MainWindow", "CONFIRMAR Y GUARDAR", nullptr));
        btnCerrarSesion->setText(QCoreApplication::translate("MainWindow", "cerrar sesi\303\263n", nullptr));
        chkSoloPrimero->setText(QCoreApplication::translate("MainWindow", "Priorizar/Solo asignar 1\302\272 Curso", nullptr));
        lblResumen->setText(QCoreApplication::translate("MainWindow", "Resumen: Esperando c\303\241lculo...", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Seleccione Facultad:", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        btnVolver->setText(QCoreApplication::translate("MainWindow", "Volver atras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
