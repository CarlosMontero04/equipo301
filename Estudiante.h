#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <QString>

class Estudiante {
public:
    int id;
    QString nombre;
    double promedio;
    int idTutor;

    Estudiante(int id, QString nombre, double promedio, int idTutor = 0)
        : id(id), nombre(nombre), promedio(promedio), idTutor(idTutor) {}
};

#endif // ESTUDIANTE_H
