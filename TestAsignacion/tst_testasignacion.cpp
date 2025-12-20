#include <QtTest>

// Incluimos tus clases originales
#include "Tutor.h"

class TestAsignacion : public QObject
{
    Q_OBJECT

public:
    TestAsignacion() {}
    ~TestAsignacion() {}

private slots:

    // --- PRUEBA 1: Lógica de Cupos ---
    void testTutorTieneCupo()
    {
        Tutor t(1, "Profe Test", "Ingenieria", 2, 0);

        // Caso A: Vacío
        QVERIFY2(t.tieneCupo() == true, "Fallo: Debería tener cupo estando vacío");

        // Caso B: Medio lleno
        t.cupoActual = 1;
        QVERIFY2(t.tieneCupo() == true, "Fallo: Debería tener cupo con 1/2 plazas");

        // Caso C: Lleno
        t.cupoActual = 2;
        QVERIFY2(t.tieneCupo() == false, "Fallo: No debería tener cupo estando lleno (2/2)");

        // Caso D: Desbordado
        t.cupoActual = 3;
        QVERIFY2(t.tieneCupo() == false, "Fallo: No debería tener cupo si está desbordado");
    }

    // --- PRUEBA 2: Robustez del Texto ---
    void testCoincidenciaFacultad()
    {
        QString depEstudiante = "Ingenieria";

        // Caso A: Exacto
        QString depTutor1 = "Ingenieria";
        QCOMPARE(depEstudiante.compare(depTutor1, Qt::CaseInsensitive), 0);

        // Caso B: Mayúsculas
        QString depTutor2 = "INGENIERIA";
        QCOMPARE(depEstudiante.compare(depTutor2, Qt::CaseInsensitive), 0);

        // Caso C: Diferente
        QString depTutor3 = "Derecho";
        QVERIFY(depEstudiante.compare(depTutor3, Qt::CaseInsensitive) != 0);

        // Caso D: Espacios
        QString depTutorSucio = " Ingenieria ";
        QCOMPARE(depEstudiante.compare(depTutorSucio.trimmed(), Qt::CaseInsensitive), 0);
    }
};

// --- ESTA ES LA LÍNEA QUE FALTABA ---
// Esto crea automáticamente el 'main' para arrancar el test
QTEST_APPLESS_MAIN(TestAsignacion)

#include "tst_testasignacion.moc"
