QT += testlib sql
QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# Evitar warnings
DEFINES += QT_DEPRECATED_WARNINGS

# Rutas para encontrar los archivos
INCLUDEPATH += ..
DEPENDPATH += ..

# Archivos fuente
SOURCES += tst_testalertas.cpp \
           ../gestorbd.cpp

# Cabeceras
HEADERS += ../gestorbd.h
