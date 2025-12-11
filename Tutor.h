#ifndef TUTOR_H
#define TUTOR_H
#include <QString>

class Tutor {
public:
    // 1. Declaración de variables (EN ESTE ORDEN EXACTO)
    int id;
    QString nombre;
    QString departamento; // <--- AQUÍ ESTÁ LA CLAVE
    int cupoMaximo;
    int cupoActual;

    // 2. Constructor (DEBE SEGUIR EL MISMO ORDEN)
    Tutor(int id, QString nombre, QString dep, int cupoMax, int cupoAct)
        : id(id), nombre(nombre), departamento(dep), cupoMaximo(cupoMax), cupoActual(cupoAct) {}

    // Función auxiliar
    bool tieneCupo() const {
        return cupoActual < cupoMaximo;
    }
};

#endif // TUTOR_H
