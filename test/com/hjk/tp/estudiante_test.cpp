#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/materia/materia.h>
#include <com/hjk/tp/estudiante/estudiante.h>
}

void comparar_datos(unsigned long legajo, char *pNombre, char *pApellido, int edad, estudiante *estudiante);

TEST(PruebasEstudiante, crear_un_estudiante) {
    estudiante *pEstudiante = new_estudiante(123456789, (char *) "Juan", (char *) "Perez", 20);
    comparar_datos(123456789, (char *) "Juan", (char *) "Perez", 20, pEstudiante);
    estudiante_destroy(pEstudiante);
}

TEST(PruebasEstudiante, estudiante_con_nombre_extenso) {
    estudiante *pEstudiante = new_estudiante(123456789, (char *) "JuanManuelPerezGarciaOliverosDeLasFuentes", (char *) "Perez", 20);
    comparar_datos(123456789, (char *) "JuanManuelPerezGarciaOliverosDeLasFuentes", (char *) "Perez", 20, pEstudiante);
    estudiante_destroy(pEstudiante);
}

TEST(PruebasEstudiante, estudiante_con_apellido_extenso) {
    estudiante *pEstudiante = new_estudiante(123456789, (char *) "Juan", (char *) "PerezGarciaOliverosDeLasFuentesDeMercurio", 20);
    comparar_datos(123456789, (char *) "Juan", (char *) "PerezGarciaOliverosDeLasFuentesDeMercurio", 20, pEstudiante);
    estudiante_destroy(pEstudiante);
}

TEST(PruebasEstudiante, nombre_con_espacios) {
    estudiante *pEstudiante = new_estudiante(123456789, (char *) "Juan Marcos", (char *) "Perez", 20);
    comparar_datos(123456789, (char *) "Juan Marcos", (char *) "Perez", 20, pEstudiante);
    estudiante_destroy(pEstudiante);
}

TEST(PruebasEstudiante, apellido_con_espacios) {
    estudiante *pEstudiante = new_estudiante(123456789, (char *) "Juan", (char *) "Perez Garcia", 20);
    comparar_datos(123456789, (char *) "Juan", (char *) "Perez Garcia", 20, pEstudiante);
    estudiante_destroy(pEstudiante);
}

TEST(PruebasEstudiante, estudiante_se_anota_a_materia) {
    estudiante *pEstudiante = new_estudiante(62, (char *) "Hernan", (char *) "Rubio", 21);
    materia *pMateria = new_materia(666, (char *) "Analisis I");
    anotarse_materia(pEstudiante, pMateria);

    auto *curso_almacenada_en_estudiante = (curso *) pEstudiante->lista_materias->head->data;
    ASSERT_STREQ("Analisis I", curso_almacenada_en_estudiante->pMateria->nombre);
    ASSERT_EQ(666, curso_almacenada_en_estudiante->pMateria->id);
    ASSERT_EQ(pMateria, curso_almacenada_en_estudiante->pMateria);

    materia_destroy(pMateria);
    estudiante_destroy(pEstudiante);
}

TEST(PruebasEstudiante, estudiante_se_anota_a_dos_materias) {
    estudiante *pEstudiante = new_estudiante(62, (char *) "Hernan", (char *) "Rubio", 21);
    materia *pMateria = new_materia(666, (char *) "Algebra I");
    materia *pOtraMateria = new_materia(777, (char *) "Programacion I");

    anotarse_materia(pEstudiante, pMateria);
    // ToDo Solucionar: no almacena la segunda materia.
    anotarse_materia(pEstudiante, pOtraMateria);

    auto *primer_curso_almacenado = (curso *) pEstudiante->lista_materias->head->data;
    auto *segundo_curso_almacenado = (curso *) pEstudiante->lista_materias->head->next->data;

    ASSERT_STREQ("Algebra I", primer_curso_almacenado->pMateria->nombre);
    ASSERT_EQ(pMateria, primer_curso_almacenado->pMateria);

    ASSERT_STREQ("Programacion I", segundo_curso_almacenado->pMateria->nombre);
    ASSERT_EQ(pOtraMateria, segundo_curso_almacenado->pMateria);

    estudiante_destroy(pEstudiante);
    materia_destroy(pMateria);
    materia_destroy(pOtraMateria);
}

void comparar_datos(unsigned long legajo, char *pNombre, char *pApellido, int edad, estudiante *estudiante) {
    ASSERT_EQ(estudiante->legajo, legajo);
    ASSERT_STREQ(estudiante->nombre, pNombre);
    ASSERT_STREQ(estudiante->apellido, pApellido);
    ASSERT_EQ(estudiante->edad, edad);
    ASSERT_NE(estudiante->lista_materias, nullptr);
}
