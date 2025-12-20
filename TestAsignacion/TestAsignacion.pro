QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# --- RUTAS CORREGIDAS SEGÚN TU "TREE" ---

# 1. Subimos un nivel (..) para estar en la raíz de GestionTutorias
INCLUDEPATH += ..
DEPENDPATH += ..

# 2. El código del test
SOURCES += tst_testasignacion.cpp

# 3. Las clases originales (subiendo un nivel)
HEADERS += ../Tutor.h \
           ../Estudiante.h

# NOTA: No añadimos Tutor.cpp porque NO existe en tu árbol (solo tienes el .h)
