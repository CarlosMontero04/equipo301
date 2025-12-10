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

    QSqlQuery query;
    // CAMBIO CLAVE: ORDER BY nombre ASC (Alfabético A-Z)
    query.prepare("SELECT id, nombre, titulacion, promedio FROM estudiantes WHERE id_tutor IS NULL ORDER BY nombre ASC");

    if (query.exec()) {
        while (query.next()) {
            lista.append(Estudiante(
                query.value("id").toInt(),
                query.value("nombre").toString(),
                query.value("titulacion").toString(), // <--- Leemos titulación
                query.value("promedio").toDouble()
                ));
        }
    }
    return lista;
}

QList<Tutor> GestorBD::obtenerTutoresDisponibles() {
    QList<Tutor> lista;
    if (!db.isOpen()) conectar();

    QSqlQuery query("SELECT id, nombre, departamento, cupo_maximo, cupo_actual FROM tutores");
    while (query.next()) {
        lista.append(Tutor(
            query.value("id").toInt(),
            query.value("nombre").toString(),
            query.value("departamento").toString(), // <--- Leemos departamento
            query.value("cupo_maximo").toInt(),
            query.value("cupo_actual").toInt()
            ));
    }
    return lista;
}
bool GestorBD::confirmarAsignaciones(QMap<int, int> asignaciones) {
    if (!db.isOpen()) conectar();

    // INICIAR TRANSACCIÓN (Paso crítico para seguridad de datos)
    if (!db.transaction()) {
        qDebug() << "Error al iniciar transacción";
        return false;
    }

    QSqlQuery queryInsert;
    QSqlQuery queryUpdate;
    bool error = false;

    // Recorremos el mapa (Key = ID Estudiante, Value = ID Tutor)
    QMapIterator<int, int> i(asignaciones);
    while (i.hasNext()) {
        i.next();
        int idEst = i.key();
        int idTut = i.value();

        // 1. Guardar en Histórico (Tabla asignaciones) - Requisito RI-3
        queryInsert.prepare("INSERT INTO asignaciones (id_estudiante, id_tutor, fecha_inicio, estado, curso_academico) "
                            "VALUES (:est, :tut, NOW(), 'Activa', '2024-2025')");
        queryInsert.bindValue(":est", idEst);
        queryInsert.bindValue(":tut", idTut);

        if (!queryInsert.exec()) {
            qDebug() << "Error insertando asignación:" << queryInsert.lastError().text();
            error = true;
            break;
        }

        // 2. Actualizar Estudiante (Tabla estudiantes) - Para que ya no salga como "pendiente"
        queryUpdate.prepare("UPDATE estudiantes SET id_tutor = :tut WHERE id = :est");
        queryUpdate.bindValue(":tut", idTut);
        queryUpdate.bindValue(":est", idEst);

        if (!queryUpdate.exec()) {
            qDebug() << "Error actualizando estudiante:" << queryUpdate.lastError().text();
            error = true;
            break;
        }
    }

    if (error) {
        db.rollback(); // Si algo falló, deshacemos TODO
        return false;
    } else {
        return db.commit(); // Si todo fue bien, guardamos definitivamente
    }
}
