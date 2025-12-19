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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TutorWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboAlumnos;
    QSpacerItem *verticalSpacer;
    QPushButton *btnContactar;
    QPushButton *bntEmitirAlerta;
    QPushButton *btnCerrarSesion;

    void setupUi(QDialog *TutorWindow)
    {
        if (TutorWindow->objectName().isEmpty())
            TutorWindow->setObjectName("TutorWindow");
        TutorWindow->resize(504, 363);
        verticalLayout = new QVBoxLayout(TutorWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(TutorWindow);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(TutorWindow);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        comboAlumnos = new QComboBox(TutorWindow);
        comboAlumnos->setObjectName("comboAlumnos");

        verticalLayout->addWidget(comboAlumnos);

        verticalSpacer = new QSpacerItem(20, 161, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnContactar = new QPushButton(TutorWindow);
        btnContactar->setObjectName("btnContactar");

        verticalLayout->addWidget(btnContactar);

        bntEmitirAlerta = new QPushButton(TutorWindow);
        bntEmitirAlerta->setObjectName("bntEmitirAlerta");

        verticalLayout->addWidget(bntEmitirAlerta);

        btnCerrarSesion = new QPushButton(TutorWindow);
        btnCerrarSesion->setObjectName("btnCerrarSesion");

        verticalLayout->addWidget(btnCerrarSesion);


        retranslateUi(TutorWindow);

        QMetaObject::connectSlotsByName(TutorWindow);
    } // setupUi

    void retranslateUi(QDialog *TutorWindow)
    {
        TutorWindow->setWindowTitle(QCoreApplication::translate("TutorWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TutorWindow", "Panel del Tutor", nullptr));
        label_2->setText(QCoreApplication::translate("TutorWindow", "Elegir alumno:", nullptr));
        btnContactar->setText(QCoreApplication::translate("TutorWindow", "Contactar Alumno", nullptr));
        bntEmitirAlerta->setText(QCoreApplication::translate("TutorWindow", "Emitir Alerta", nullptr));
        btnCerrarSesion->setText(QCoreApplication::translate("TutorWindow", "Cerrar Sesi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TutorWindow: public Ui_TutorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORWINDOW_H
