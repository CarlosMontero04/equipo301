#include "gestorbd.h"

GestorBD::GestorBD() {}

bool GestorBD::conectar() {
    // Si ya existe una conexión con este nombre, la usamos
    if(QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QMARIADB");
        db.setHostName("localhost");
        db.setDatabaseName("gestion_tutorias");
        db.setUserName("admin");
        db.setPassword("pepe");
    }

    if (!db.isOpen()) {
        if (!db.open()) {
            qDebug() << "ERROR CONEXION:" << db.lastError().text();
            return false;
        }
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
    query.prepare("SELECT id, nombre, titulacion, curso, promedio FROM estudiantes WHERE id_tutor IS NULL ORDER BY curso ASC, nombre ASC");

    if (query.exec()) {
        while (query.next()) {
            lista.append(Estudiante(
                query.value("id").toInt(),
                query.value("nombre").toString(),
                query.value("titulacion").toString(),
                query.value("curso").toInt(),
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
            query.value("departamento").toString(),
            query.value("cupo_maximo").toInt(),
            query.value("cupo_actual").toInt()
            ));
    }
    return lista;
}

bool GestorBD::confirmarAsignaciones(QMap<int, int> asignaciones) {
    if (!db.isOpen()) conectar();

    if (!db.transaction()) {
        qDebug() << "Error al iniciar transacción";
        return false;
    }

    QSqlQuery queryInsert;
    QSqlQuery queryUpdate;
    bool error = false;

    QMapIterator<int, int> i(asignaciones);
    while (i.hasNext()) {
        i.next();
        int idEst = i.key();
        int idTut = i.value();

        queryInsert.prepare("INSERT INTO asignaciones (id_estudiante, id_tutor, fecha_inicio, estado, curso_academico) "
                            "VALUES (:est, :tut, NOW(), 'Activa', '2024-2025')");
        queryInsert.bindValue(":est", idEst);
        queryInsert.bindValue(":tut", idTut);

        if (!queryInsert.exec()) {
            error = true;
            break;
        }

        queryUpdate.prepare("UPDATE estudiantes SET id_tutor = :tut WHERE id = :est");
        queryUpdate.bindValue(":tut", idTut);
        queryUpdate.bindValue(":est", idEst);

        if (!queryUpdate.exec()) {
            error = true;
            break;
        }
    }

    if (error) {
        db.rollback();
        return false;
    } else {
        return db.commit();
    }
}

QStringList GestorBD::obtenerListaFacultades() {
    QStringList lista;
    if (!db.isOpen()) conectar();

    QSqlQuery query("SELECT DISTINCT titulacion FROM estudiantes ORDER BY titulacion ASC");
    lista.append("--- TODAS LAS FACULTADES ---");

    while (query.next()) {
        lista.append(query.value(0).toString());
    }
    return lista;
}

bool GestorBD::reiniciarDatos() {
    if (!db.isOpen()) conectar();
    QSqlQuery query;
    bool b1 = query.exec("DELETE FROM asignaciones");
    bool b2 = query.exec("UPDATE estudiantes SET id_tutor = NULL");
    bool b3 = query.exec("UPDATE tutores SET cupo_actual = 0");
    return b1 && b2 && b3;
}

bool GestorBD::enviarMensaje(int idEmisor, QString rolEmisor, int idReceptor, QString rolReceptor, QString contenido) {
    if (!db.isOpen()) conectar();

    QSqlQuery query;
    query.prepare("INSERT INTO mensajes (id_emisor, rol_emisor, id_receptor, rol_receptor, contenido, fecha, leido) "
                  "VALUES (:emi, :rolE, :rec, :rolR, :cont, NOW(), 0)");

    query.bindValue(":emi", idEmisor);
    query.bindValue(":rolE", rolEmisor);
    query.bindValue(":rec", idReceptor);
    query.bindValue(":rolR", rolReceptor);
    query.bindValue(":cont", contenido);

    if(query.exec()){
        return true;
    } else {
        qDebug() << "Error enviando mensaje:" << query.lastError().text();
        return false;
    }
}

QList<QPair<QString, QString>> GestorBD::obtenerConversacion(int idA, QString rolA, int idB, QString rolB) {
    QList<QPair<QString, QString>> charla;
    if (!db.isOpen()) conectar();

    QSqlQuery query;
    QString sql = "SELECT rol_emisor, contenido FROM mensajes WHERE "
                  "((id_emisor = :idA AND rol_emisor = :rolA) AND (id_receptor = :idB AND rol_receptor = :rolB)) "
                  "OR "
                  "((id_emisor = :idB AND rol_emisor = :rolB) AND (id_receptor = :idA AND rol_receptor = :rolA)) "
                  "ORDER BY fecha ASC";

    query.prepare(sql);
    query.bindValue(":idA", idA);
    query.bindValue(":rolA", rolA);
    query.bindValue(":idB", idB);
    query.bindValue(":rolB", rolB);

    if (query.exec()) {
        while(query.next()){
            QString emisor = query.value("rol_emisor").toString();
            QString texto = query.value("contenido").toString();
            charla.append(qMakePair(emisor, texto));
        }
    } else {
        qDebug() << "Error cargando chat:" << query.lastError().text();
    }
    return charla;
}

QString GestorBD::obtenerNombreTutor(int idEstudiante) {
    if (!db.isOpen()) conectar();
    QSqlQuery query;
    query.prepare("SELECT t.nombre FROM tutores t "
                  "JOIN estudiantes e ON t.id = e.id_tutor "
                  "WHERE e.id = :id");
    query.bindValue(":id", idEstudiante);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }
    return "Sin tutor asignado";
}

int GestorBD::obtenerIdTutorDeEstudiante(int idEstudiante) {
    if (!db.isOpen()) conectar();
    QSqlQuery query;
    query.prepare("SELECT id_tutor FROM estudiantes WHERE id = :id");
    query.bindValue(":id", idEstudiante);

    if (query.exec() && query.next()) {
        // Verifica si es nulo
        if(query.value(0).isNull()) return -1;
        return query.value(0).toInt();
    }
    return -1;
}
