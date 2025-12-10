#ifndef TUTOR_H
#define TUTOR_H
#include <QString>

class Tutor {
public:
    int id;
    QString nombre;
    int cupoMaximo;
    int cupoActual;
    QString departamento;

    Tutor(int id, QString nombre, QString dep, int cupoMax, int cupoAct)
        : id(id), nombre(nombre), departamento(dep), cupoMaximo(cupoMax), cupoActual(cupoAct) {}

    // --- ESTA ES LA FUNCIÓN QUE FALTABA ---
    bool tieneCupo() const {
        return cupoActual < cupoMaximo;
    }
};

#endif // TUTOR_H
