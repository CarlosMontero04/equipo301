#ifndef GESTORBD_H
#define GESTORBD_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <QDebug>
#include "Estudiante.h"
#include "Tutor.h"
#include <QMap>

class GestorBD
{
public:
    GestorBD();
    bool conectar();
    void cerrar();
    QList<Estudiante> obtenerEstudiantesSinTutor();
    QList<Tutor> obtenerTutoresDisponibles();
    bool confirmarAsignaciones(QMap<int, int> asignaciones);
    QStringList obtenerListaFacultades();
    bool reiniciarDatos();
    bool enviarMensaje(int idEmisor, QString rolEmisor, int idReceptor, QString rolReceptor, QString contenido);
    QList<QPair<QString, QString>> obtenerConversacion(int idEmisor, QString rolEmisor, int idReceptor, QString rolReceptor);

    QString obtenerNombreTutor(int idEstudiante);
    int obtenerIdTutorDeEstudiante(int idEstudiante); // Solo una declaración aquí

private:
    QSqlDatabase db;
};

#endif // GESTORBD_H
