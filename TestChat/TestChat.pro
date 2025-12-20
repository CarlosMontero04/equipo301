QT += testlib sql
QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# DEFINES para evitar warnings
DEFINES += QT_DEPRECATED_WARNINGS

# --- RUTAS CORREGIDAS (Al estar DENTRO, la ruta es solo "..") ---
INCLUDEPATH += ..
DEPENDPATH += ..

# --- SOURCES ---
# tst_testchat.cpp está en la carpeta actual
# gestorbd.cpp está en la carpeta PADRE (..)
SOURCES += tst_testchat.cpp \
           ../gestorbd.cpp

# --- HEADERS ---
# Los .h también están en la carpeta PADRE (..)
HEADERS += ../gestorbd.h \
           ../Estudiante.h \
           ../Tutor.h
