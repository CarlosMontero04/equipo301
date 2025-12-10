#include "gestorbd.h"

GestorBD::GestorBD() {}

bool GestorBD::conectar() {
    db = QSqlDatabase::addDatabase("QMARIADB");
    db.setHostName("localhost");
    db.setDatabaseName("gestion_tutorias");
    db.setUserName("admin");
    db.setPassword("pepe");

    if (!db.open()) {
        qDebug() << "ERROR CONEXION:" << db.lastError().text();
        return false;
    }
    qDebug() << "Conexion Exitosa con la BD";
    return true;
}

void GestorBD::cerrar() {
    db.close();
}

QList<Estudiante> GestorBD::obtenerEstudiantesSinTutor() {
    QList<Estudiante> lista;
    if (!db.isOpen()) conectar();

    QSqlQuery query("SELECT id, nombre, promedio FROM estudiantes WHERE id_tutor IS NULL ORDER BY promedio DESC");
    while (query.next()) {
        lista.append(Estudiante(
            query.value("id").toInt(),
            query.value("nombre").toString(),
            query.value("promedio").toDouble()
            ));
    }
    return lista;
}

QList<Tutor> GestorBD::obtenerTutoresDisponibles() {
    QList<Tutor> lista;
    if (!db.isOpen()) conectar();

    // Nota: Por ahora usamos cupo_actual tal cual está en la BD.
    QSqlQuery query("SELECT id, nombre, cupo_maximo, cupo_actual FROM tutores");
    while (query.next()) {
        lista.append(Tutor(
            query.value("id").toInt(),
            query.value("nombre").toString(),
            query.value("cupo_maximo").toInt(),
            query.value("cupo_actual").toInt()
            ));
    }
    return lista;
}
