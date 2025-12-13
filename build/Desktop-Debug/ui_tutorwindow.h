/********************************************************************************
** Form generated from reading UI file 'tutorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORWINDOW_H
#define UI_TUTORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TutorWindow
{
public:
    QLabel *label;
    QComboBox *comboAlumnos;
    QPushButton *bntEmitirAlerta;
    QLabel *label_2;

    void setupUi(QDialog *TutorWindow)
    {
        if (TutorWindow->objectName().isEmpty())
            TutorWindow->setObjectName("TutorWindow");
        TutorWindow->resize(504, 363);
        label = new QLabel(TutorWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 50, 141, 18));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        comboAlumnos = new QComboBox(TutorWindow);
        comboAlumnos->setObjectName("comboAlumnos");
        comboAlumnos->setGeometry(QRect(220, 160, 86, 26));
        bntEmitirAlerta = new QPushButton(TutorWindow);
        bntEmitirAlerta->setObjectName("bntEmitirAlerta");
        bntEmitirAlerta->setGeometry(QRect(220, 260, 91, 26));
        label_2 = new QLabel(TutorWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 160, 101, 18));

        retranslateUi(TutorWindow);

        QMetaObject::connectSlotsByName(TutorWindow);
    } // setupUi

    void retranslateUi(QDialog *TutorWindow)
    {
        TutorWindow->setWindowTitle(QCoreApplication::translate("TutorWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TutorWindow", "Panel del Tutor", nullptr));
        bntEmitirAlerta->setText(QCoreApplication::translate("TutorWindow", "Emitir Alerta", nullptr));
        label_2->setText(QCoreApplication::translate("TutorWindow", "Elegir alumno:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TutorWindow: public Ui_TutorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORWINDOW_H
