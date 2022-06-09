#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/estudiante/estudiante.h>
}

TEST(PruebasCrearEstudiante, crear_un_estudiante) {
    estudiante *estudiante = new_estudiante(123456789, (char *) "Juan", (char *) "Perez", 20);
    ASSERT_EQ(estudiante->legajo, 123456789);
    ASSERT_STREQ(estudiante->nombre, "Juan");
    ASSERT_STREQ(estudiante->apellido, "Perez");
    ASSERT_EQ(estudiante->edad, 20);
    ASSERT_NE(estudiante->lista_materias, nullptr);
    free(estudiante);
}

TEST(PruebasCrearEstudiante, estudiante_con_nombre_extenso) {
    estudiante *estudiante = new_estudiante(123456789, (char *) "JuanManuelPerezGarciaOliverosDeLasFuentes", (char *) "Perez", 20);
    ASSERT_EQ(estudiante->legajo, 123456789);
    ASSERT_STREQ(estudiante->nombre, "JuanManuelPerezGarciaOliverosDeLasFuentes");
    ASSERT_STREQ(estudiante->apellido, "Perez");
    ASSERT_EQ(estudiante->edad, 20);
    ASSERT_NE(estudiante->lista_materias, nullptr);
    free(estudiante);
}

TEST(PruebasCrearEstudiante, estudiante_con_apellido_extenso) {
    estudiante *estudiante = new_estudiante(123456789, (char *) "Juan", (char *) "PerezGarciaOliverosDeLasFuentesDeMercurio", 20);
    ASSERT_EQ(estudiante->legajo, 123456789);
    ASSERT_STREQ(estudiante->nombre, "Juan");
    ASSERT_STREQ(estudiante->apellido, "PerezGarciaOliverosDeLasFuentesDeMercurio");
    ASSERT_EQ(estudiante->edad, 20);
    ASSERT_NE(estudiante->lista_materias, nullptr);
    free(estudiante);
}

TEST(PruebasCrearEstudiante, nombre_con_espacios) {
    estudiante *estudiante = new_estudiante(123456789, (char *) "Juan Marcos", (char *) "Perez", 20);
    ASSERT_EQ(estudiante->legajo, 123456789);
    ASSERT_STREQ(estudiante->nombre, "Juan Marcos");
    ASSERT_STREQ(estudiante->apellido, "Perez");
    ASSERT_EQ(estudiante->edad, 20);
    ASSERT_NE(estudiante->lista_materias, nullptr);
    free(estudiante);
}

TEST(PruebasCrearEstudiante, apellido_con_espacios) {
    estudiante *estudiante = new_estudiante(123456789, (char *) "Juan", (char *) "Perez Garcia", 20);
    ASSERT_EQ(estudiante->legajo, 123456789);
    ASSERT_STREQ(estudiante->nombre, "Juan");
    ASSERT_STREQ(estudiante->apellido, "Perez Garcia");
    ASSERT_EQ(estudiante->edad, 20);
    ASSERT_NE(estudiante->lista_materias, nullptr);
    free(estudiante);
}
