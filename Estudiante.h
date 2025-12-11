#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <QString>

class Estudiante {
public:
    // 1. Declaración de variables (EN ESTE ORDEN)
    int id;
    QString nombre;
    QString titulacion; // <--- Titulacion va aqui
    int curso;          // <--- Curso va despues
    double promedio;
    int idTutor;

    // 2. Constructor (DEBE SEGUIR EL MISMO ORDEN EXACTO)
    Estudiante(int id, QString nombre, QString titulacion, int curso, double promedio, int idTutor = 0)
        : id(id), nombre(nombre), titulacion(titulacion), curso(curso), promedio(promedio), idTutor(idTutor) {}
};

#endif // ESTUDIANTE_H
