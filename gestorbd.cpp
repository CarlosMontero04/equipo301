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

    // MEJORA H2: Ordenamos por 'curso ASC' (1º primero) y luego nombre
    query.prepare("SELECT id, nombre, titulacion, curso, promedio FROM estudiantes WHERE id_tutor IS NULL ORDER BY curso ASC, nombre ASC");

    if (query.exec()) {
        while (query.next()) {
            lista.append(Estudiante(
                query.value("id").toInt(),
                query.value("nombre").toString(),
                query.value("titulacion").toString(),
                query.value("curso").toInt(), // <--- Leemos el curso
                query.value("promedio").toDouble()
                ));
        }
    }
    return lista;
}

QList<Tutor> GestorBD::obtenerTutoresDisponibles() {
    QList<Tutor> lista;
    // Usamos la conexión inteligente que arreglamos antes
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        conectar();
    }

    if (!db.isOpen()) return lista;

    // --- AQUÍ ESTABA EL ERROR PROBABLE ---
    // Es vital que seleccionemos 'departamento' para poder comparar facultades
    QSqlQuery query("SELECT id, nombre, departamento, cupo_maximo, cupo_actual FROM tutores");

    while (query.next()) {
        lista.append(Tutor(
            query.value("id").toInt(),
            query.value("nombre").toString(),
            query.value("departamento").toString(), // <--- IMPORTANTE: Leer el departamento
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
QStringList GestorBD::obtenerListaFacultades() {
    QStringList lista;
    if (!db.isOpen()) conectar();

    QSqlQuery query("SELECT DISTINCT titulacion FROM estudiantes ORDER BY titulacion ASC");

    // Añadimos una opción por defecto para "Hacerlo todo"
    lista.append("--- TODAS LAS FACULTADES ---");

    while (query.next()) {
        lista.append(query.value(0).toString());
    }
    return lista;
}
bool GestorBD::reiniciarDatos() {
    QSqlQuery query;
    // 1. Borra el historial de uniones (Correcto)
    query.exec("DELETE FROM asignaciones");

    // 2. Libera a los alumnos (Correcto: pone NULL, no borra al alumno)
    query.exec("UPDATE estudiantes SET id_tutor = NULL");

    // 3. Resetea los contadores (Correcto: pone 0, no borra al profesor)
    query.exec("UPDATE tutores SET cupo_actual = 0");

    return true;
}
