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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 7, 401, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
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
        tablaAsignaciones->setGeometry(QRect(80, 70, 631, 381));
        btnCalcular = new QPushButton(centralwidget);
        btnCalcular->setObjectName("btnCalcular");
        btnCalcular->setGeometry(QRect(140, 510, 211, 26));
        btnConfirmar = new QPushButton(centralwidget);
        btnConfirmar->setObjectName("btnConfirmar");
        btnConfirmar->setEnabled(false);
        btnConfirmar->setGeometry(QRect(430, 510, 201, 26));
        MainWindow->setCentralWidget(centralwidget);
        tablaAsignaciones->raise();
        label->raise();
        btnCalcular->raise();
        btnConfirmar->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
