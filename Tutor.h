#ifndef TUTOR_H
#define TUTOR_H
#include <QString>

class Tutor {
public:
    int id;
    QString nombre;
    int cupoMaximo;
    int cupoActual;

    Tutor(int id, QString nombre, int cupoMax, int cupoAct)
        : id(id), nombre(nombre), cupoMaximo(cupoMax), cupoActual(cupoAct) {}
};

#endif // TUTOR_H
