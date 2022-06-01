#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/estudiante/estudiante.h>
}

TEST(PruebasCrearEstudiante, crear_un_estudiante) {
    estudiante *estudiante = crear_estudiante(123456789, "Juan", "Perez", 20);
    ASSERT_EQ(estudiante->legajo, 123456789);
    ASSERT_STREQ(estudiante->nombre, "Juan");
    ASSERT_STREQ(estudiante->apellido, "Perez");
    ASSERT_EQ(estudiante->edad, 20);
    ASSERT_NE(estudiante->lista_materias, nullptr);
    free(estudiante);
}

TEST(PruebasCrearEstudiante, estudiante_con_nombre_mayor_a_tamanio_maximo) {
    estudiante *estudiante = crear_estudiante(123456789, "JuanManuelPerezGarciaOliverosDeLasFuentes", "Perez", 20);
    ASSERT_EQ(estudiante->legajo, 123456789);
    ASSERT_STREQ(estudiante->nombre, "JuanManuelPerezGarciaOli");
    ASSERT_STREQ(estudiante->apellido, "Perez");
    ASSERT_EQ(estudiante->edad, 20);
    ASSERT_NE(estudiante->lista_materias, nullptr);
    free(estudiante);
}

TEST(PruebasCrearEstudiante, estudiante_con_apellido_mayor_a_tamanio_maximo) {
    estudiante *estudiante = crear_estudiante(123456789, "Juan", "PerezGarciaOliverosDeLasFuentesDeMercurio", 20);
    ASSERT_EQ(estudiante->legajo, 123456789);
    ASSERT_STREQ(estudiante->nombre, "Juan");
    ASSERT_STREQ(estudiante->apellido, "PerezGarciaOliverosDeLas");
    ASSERT_EQ(estudiante->edad, 20);
    ASSERT_NE(estudiante->lista_materias, nullptr);
    free(estudiante);
}