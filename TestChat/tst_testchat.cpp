#include <QtTest>
#include <QCoreApplication>
#include "gestorbd.h"

class TestChat : public QObject
{
    Q_OBJECT

public:
    TestChat();
    ~TestChat();

private slots:
    // Se ejecuta una vez antes de todos los tests
    void initTestCase();
    // Se ejecuta una vez al final
    void cleanupTestCase();

    // --- TUS DOS PRUEBAS UNITARIAS ---
    void testEnviarMensaje();
    void testCargarConversacion();

private:
    GestorBD gestor;
};

TestChat::TestChat() {}

TestChat::~TestChat() {}

void TestChat::initTestCase()
{
    // Intentamos conectar a la BD real para las pruebas
    bool conectado = gestor.conectar();
    QVERIFY2(conectado, "No se pudo conectar a la base de datos. Asegúrate que XAMPP/MariaDB está corriendo.");
}

void TestChat::cleanupTestCase()
{
    // Cerramos conexión al acabar
    gestor.cerrar();
}

/**
 * PRUEBA 1: Enviar Mensaje
 * Objetivo: Verificar que gestor.enviarMensaje inserta correctamente en la BD.
 * Tipo: Caja blanca / Integración (porque toca BD real).
 */
void TestChat::testEnviarMensaje()
{
    // 1. PREPARACIÓN (Arrange)
    // Usamos IDs que sepamos que existen (o IDs seguros).
    // Para no ensuciar, usaremos IDs ficticios altos o los del dump.
    int idEmisor = 9999;
    QString rolEmisor = "EstudianteTest";
    int idReceptor = 8888;
    QString rolReceptor = "TutorTest";
    QString contenidoUnico = "MensajePruebaUnitarias_" + QString::number(QDateTime::currentMSecsSinceEpoch());

    // 2. ACCIÓN (Act)
    bool enviado = gestor.enviarMensaje(idEmisor, rolEmisor, idReceptor, rolReceptor, contenidoUnico);

    // 3. VERIFICACIÓN (Assert)
    QVERIFY2(enviado, "El método enviarMensaje devolvió false.");

    // Verificación doble: Consultamos directamente a la BD para ver si el registro existe
    QSqlQuery query;
    query.prepare("SELECT contenido, leido FROM mensajes WHERE contenido = :cont");
    query.bindValue(":cont", contenidoUnico);
    query.exec();

    QVERIFY2(query.next(), "El mensaje no se encontró en la base de datos tras enviarlo.");
    QCOMPARE(query.value("contenido").toString(), contenidoUnico);
    QCOMPARE(query.value("leido").toInt(), 0); // Debe estar no leído por defecto

    // 4. LIMPIEZA (Cleanup) - Borramos el mensaje de prueba
    QSqlQuery borrado;
    borrado.prepare("DELETE FROM mensajes WHERE contenido = :cont");
    borrado.bindValue(":cont", contenidoUnico);
    borrado.exec();
}

/**
 * PRUEBA 2: Cargar Conversación (Filtrado)
 * Objetivo: Verificar que obtenerConversacion trae solo los mensajes entre A y B,
 * ignorando los de otros usuarios, y los ordena bien.
 */
void TestChat::testCargarConversacion()
{
    // 1. PREPARACIÓN (Arrange)
    int idA = 500; QString rolA = "UserA";
    int idB = 501; QString rolB = "UserB";
    int idC = 502; QString rolC = "UserC"; // Un tercero que no debe salir

    QString msg1 = "Hola B, soy A";
    QString msg2 = "Hola A, soy B";
    QString msgRuido = "Hola C, no deberías salir";

    // Insertamos mensajes manualmente para controlar el escenario exacto
    gestor.enviarMensaje(idA, rolA, idB, rolB, msg1); // A -> B
    QThread::msleep(100); // Pequeña pausa para asegurar orden de tiempo
    gestor.enviarMensaje(idB, rolB, idA, rolA, msg2); // B -> A (respuesta)
    gestor.enviarMensaje(idA, rolA, idC, rolC, msgRuido); // A -> C (Ruido)

    // 2. ACCIÓN (Act)
    // Pedimos la conversación SOLO entre A y B
    QList<QPair<QString, QString>> chat = gestor.obtenerConversacion(idA, rolA, idB, rolB);

    // 3. VERIFICACIÓN (Assert)
    // Deberíamos tener exactamente 2 mensajes, no 3.
    QCOMPARE(chat.size(), 2);

    // Verificamos el contenido y el orden
    QCOMPARE(chat.at(0).second, msg1); // El primero debe ser el de A
    QCOMPARE(chat.at(0).first, rolA);

    QCOMPARE(chat.at(1).second, msg2); // El segundo debe ser el de B
    QCOMPARE(chat.at(1).first, rolB);

    // 4. LIMPIEZA
    QSqlQuery query;
    query.exec("DELETE FROM mensajes WHERE id_emisor IN (500, 501, 502)");
}

QTEST_MAIN(TestChat)

#include "tst_testchat.moc"
