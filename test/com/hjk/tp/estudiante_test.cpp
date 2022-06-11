#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/estudiante/estudiante.h>
}

void comparar_datos(unsigned long legajo, char *pNombre, char *pApellido, int edad, estudiante *estudiante);

TEST(PruebasEstudiante, crear_un_estudiante) {
    estudiante *pEstudiante = new_estudiante(123456789, (char *) "Juan", (char *) "Perez", 20);
    comparar_datos(123456789, (char *) "Juan", (char *) "Perez", 20, pEstudiante);
    free(pEstudiante);
}

TEST(PruebasEstudiante, estudiante_con_nombre_extenso) {
    estudiante *pEstudiante = new_estudiante(123456789, (char *) "JuanManuelPerezGarciaOliverosDeLasFuentes", (char *) "Perez", 20);
    comparar_datos(123456789, (char *) "JuanManuelPerezGarciaOliverosDeLasFuentes", (char *) "Perez", 20, pEstudiante);
    free(pEstudiante);
}

TEST(PruebasEstudiante, estudiante_con_apellido_extenso) {
    estudiante *pEstudiante = new_estudiante(123456789, (char *) "Juan", (char *) "PerezGarciaOliverosDeLasFuentesDeMercurio", 20);
    comparar_datos(123456789, (char *) "Juan", (char *) "PerezGarciaOliverosDeLasFuentesDeMercurio", 20, pEstudiante);
    free(pEstudiante);
}

TEST(PruebasEstudiante, nombre_con_espacios) {
    estudiante *pEstudiante = new_estudiante(123456789, (char *) "Juan Marcos", (char *) "Perez", 20);
    comparar_datos(123456789, (char *) "Juan Marcos", (char *) "Perez", 20, pEstudiante);
    free(pEstudiante);
}

TEST(PruebasEstudiante, apellido_con_espacios) {
    estudiante *pEstudiante = new_estudiante(123456789, (char *) "Juan", (char *) "Perez Garcia", 20);
    comparar_datos(123456789, (char *) "Juan", (char *) "Perez Garcia", 20, pEstudiante);
    free(pEstudiante);
}

void comparar_datos(unsigned long legajo, char *pNombre, char *pApellido, int edad, estudiante *estudiante) {
    ASSERT_EQ(estudiante->legajo, legajo);
    ASSERT_STREQ(estudiante->nombre, pNombre);
    ASSERT_STREQ(estudiante->apellido, pApellido);
    ASSERT_EQ(estudiante->edad, edad);
    ASSERT_NE(estudiante->lista_materias, nullptr);
}
