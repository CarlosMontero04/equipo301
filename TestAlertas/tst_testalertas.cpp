#include <QtTest>
#include <QSqlDatabase>
#include <QDebug>
#include "../gestorbd.h"

class TestAlertas : public QObject
{
    Q_OBJECT

public:
    TestAlertas();
    ~TestAlertas();

private slots:
    void initTestCase();    // Configuración inicial
    void cleanupTestCase(); // Limpieza final

    // --- SOLO ESTOS 2 TESTS ---
    void testConexion();           // ¿El gestor conecta bien?
    void testTablaAlertasExiste(); // ¿Existe la tabla en la BD?

private:
    GestorBD *gestor;
};

TestAlertas::TestAlertas() {}

TestAlertas::~TestAlertas() {}

void TestAlertas::initTestCase()
{
    // Creamos la instancia de tu gestor original
    gestor = new GestorBD();
}

void TestAlertas::cleanupTestCase()
{
    // Cerramos y borramos
    if (gestor) {
        gestor->cerrar();
        delete gestor;
    }
}

void TestAlertas::testConexion()
{
    // PRUEBA 1: Verificar que tu función conectar() devuelve true
    bool conectado = gestor->conectar();

    if (!conectado) {
        qDebug() << "Error: No se pudo conectar a la base de datos.";
    }

    QVERIFY2(conectado, "El GestorBD falló al intentar conectar con la base de datos");
}

void TestAlertas::testTablaAlertasExiste()
{
    // PRUEBA 2: Preguntar a la base de datos si tiene una tabla llamada "alertas"
    // Esto confirma que tu SQL de creación de tablas funcionó en su día.

    QSqlDatabase db = QSqlDatabase::database();
    QStringList tablas = db.tables();

    qDebug() << "Tablas encontradas en la BD:" << tablas;

    bool existe = tablas.contains("alertas", Qt::CaseInsensitive);

    QVERIFY2(existe, "La tabla 'alertas' NO se encuentra en la base de datos. Revisa tu script SQL.");
}

QTEST_APPLESS_MAIN(TestAlertas)

#include "tst_testalertas.moc"
