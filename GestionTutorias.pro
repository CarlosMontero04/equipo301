QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatwindow.cpp \
    gestorbd.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    menucoordinador.cpp \
    menuestudiante.cpp \
    tutorwindow.cpp \
    ventanaalertas.cpp

HEADERS += \
    Estudiante.h \
    Tutor.h \
    chatwindow.h \
    gestorbd.h \
    loginwindow.h \
    mainwindow.h \
    menucoordinador.h \
    menuestudiante.h \
    tutorwindow.h \
    ventanaalertas.h

FORMS += \
    chatwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    menucoordinador.ui \
    menuestudiante.ui \
    tutorwindow.ui \
    ventanaalertas.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
