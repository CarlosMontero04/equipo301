#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <QString>

class Estudiante {
public:
    int id;
    QString nombre;
    double promedio;
    int idTutor;
    QString titulacion;

    Estudiante(int id, QString nombre, QString titulacion, double promedio, int idTutor = 0)
        : id(id), nombre(nombre), titulacion(titulacion), promedio(promedio), idTutor(idTutor) {}
};

#endif // ESTUDIANTE_H
