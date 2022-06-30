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

    estudiante_destroy(pEstudiante);
}

TEST(PruebasEstudiante, estudiante_se_anota_a_dos_materias) {
    estudiante *pEstudiante = new_estudiante(62, (char *) "Hernan", (char *) "Rubio", 21);
    materia *pMateria = new_materia(666, (char *) "Algebra I");
    materia *pOtraMateria = new_materia(777, (char *) "Programacion I");

    anotarse_materia(pEstudiante, pMateria);
    anotarse_materia(pEstudiante, pOtraMateria);
    anotarse_materia(pEstudiante, pOtraMateria);

    auto *primer_curso_almacenado = (curso *) pEstudiante->lista_materias->head->data;
    auto *segundo_curso_almacenado = (curso *) pEstudiante->lista_materias->head->next->data;
    ASSERT_EQ(pEstudiante->lista_materias->head->next->next->data, nullptr);

    ASSERT_STREQ("Algebra I", primer_curso_almacenado->pMateria->nombre);
    ASSERT_EQ(pMateria, primer_curso_almacenado->pMateria);
    ASSERT_STREQ("Programacion I", segundo_curso_almacenado->pMateria->nombre);
    ASSERT_EQ(pOtraMateria, segundo_curso_almacenado->pMateria);

    estudiante_destroy(pEstudiante);
}

TEST(PruebasEstudiante, correlatividad) {
    estudiante *pEstudiante = new_estudiante(62, (char *) "Hernan", (char *) "Rubio", 21);
    materia *algebra1 = new_materia(666, (char *) "Algebra I");
    materia *algebra2 = new_materia(777, (char *) "Algebra II");
    auto *pCurso = (curso *) pEstudiante->lista_materias->head->data;
    materia_add_correlativas(algebra2, algebra1);

    anotarse_materia(pEstudiante, algebra2);
    ASSERT_EQ(pCurso, nullptr);

    anotarse_materia(pEstudiante, algebra1);
    pCurso = (curso *) pEstudiante->lista_materias->head->data;
    ASSERT_EQ(pCurso->pMateria, algebra1);

    anotarse_materia(pEstudiante, algebra2);
    pCurso = (curso *) pEstudiante->lista_materias->head->next->data;
    ASSERT_EQ(pCurso->pMateria, algebra2);

    estudiante_destroy(pEstudiante);
}

TEST(PruebasEstudiante, correlatividad_2) {
    estudiante *pEstudiante = new_estudiante(62, (char *) "Hernan", (char *) "Rubio", 21);
    materia *algo1 = new_materia(666, (char *) "AyP I");
    materia *algo2 = new_materia(777, (char *) "AyP II");
    materia *edd = new_materia(888, (char *) "EDD");
    materia *algo3 = new_materia(999, (char *) "AyP III");
    materia_add_correlativas(algo2, algo1);
    materia_add_correlativas(edd, algo2);
    materia_add_correlativas(algo3, edd);

    anotarse_materia(pEstudiante, algo3);
    anotarse_materia(pEstudiante, edd);
    anotarse_materia(pEstudiante, algo2);
    ASSERT_EQ(pEstudiante->lista_materias->length, 0);

    anotarse_materia(pEstudiante, algo1);
    ASSERT_EQ(cursada_get_curso(pEstudiante->lista_materias, algo1)->pMateria, algo1);

    anotarse_materia(pEstudiante, algo3);
    anotarse_materia(pEstudiante, edd);
    ASSERT_EQ(pEstudiante->lista_materias->length, 1);

    anotarse_materia(pEstudiante, algo2);
    ASSERT_EQ(cursada_get_curso(pEstudiante->lista_materias, algo2)->pMateria, algo2);

    anotarse_materia(pEstudiante, algo3);
    ASSERT_EQ(pEstudiante->lista_materias->length, 2);

    anotarse_materia(pEstudiante, edd);
    ASSERT_EQ(cursada_get_curso(pEstudiante->lista_materias, edd)->pMateria, edd);
    ASSERT_EQ(pEstudiante->lista_materias->length, 3);

    anotarse_materia(pEstudiante, algo3);
    ASSERT_EQ(cursada_get_curso(pEstudiante->lista_materias, algo3)->pMateria, algo3);
    ASSERT_EQ(pEstudiante->lista_materias->length, 4);

    estudiante_destroy(pEstudiante);
}

TEST(PruebasEstudiante, rendir_una_materia_con_nota_10) {
    estudiante *un_estudiante = new_estudiante(62, (char *) "Hernan", (char *) "Rubio", 21);
    materia *una_materia = new_materia(666, (char *) "AyP I");

    anotarse_materia(un_estudiante, una_materia);
    rendir_materia(un_estudiante, una_materia, 10);

    auto *materia_calificada = (curso *) un_estudiante->lista_materias->head->data;

    ASSERT_EQ(materia_calificada->calificacion, 10);

    estudiante_destroy(un_estudiante);
}

TEST(PruebasEstudiante, rendir_segunda_materia_con_nota_7) {
    estudiante *un_estudiante = new_estudiante(62, (char *) "Hernan", (char *) "Rubio", 21);
    materia *una_materia = new_materia(666, (char *) "AyP I");
    materia *otra_materia = new_materia(777, (char *) "Analisis I");

    anotarse_materia(un_estudiante, una_materia);
    anotarse_materia(un_estudiante, otra_materia);

    rendir_materia(un_estudiante, otra_materia, 7);

    auto *segundo_elemento_lista = (node *) un_estudiante->lista_materias->head->next;
    auto *materia_calificada = (curso *) segundo_elemento_lista->data;

    ASSERT_EQ(materia_calificada->calificacion, 7);

    estudiante_destroy(un_estudiante);
}


TEST(PruebasEstudiante, calcular_promedio_materia_8) {
    estudiante *un_estudiante = new_estudiante(62, (char *) "Johnny", (char *) "Allon", 81);
    materia *una_materia = new_materia(666, (char *) "Show and TV");

    anotarse_materia(un_estudiante, una_materia);

    rendir_materia(un_estudiante, una_materia, 8);

    double promedio = calcular_promedio_estudiante(un_estudiante);

    ASSERT_EQ(promedio, 8);

    estudiante_destroy(un_estudiante);
}

TEST(PruebasEstudiante, calcular_promedio_con_dos_7) {
    estudiante *un_estudiante = new_estudiante(62, (char *) "Johnny", (char *) "Allon", 81);
    materia *una_materia = new_materia(666, (char *) "Show and TV");
    materia *otra_materia = new_materia(777, (char *) "Musica popular");

    anotarse_materia(un_estudiante, una_materia);
    anotarse_materia(un_estudiante, otra_materia);

    rendir_materia(un_estudiante, otra_materia, 7);
    rendir_materia(un_estudiante, una_materia, 7);

    double promedio = calcular_promedio_estudiante(un_estudiante);

    ASSERT_EQ(promedio, 7);

    estudiante_destroy(un_estudiante);
}

TEST(PruebasEstudiante, calcular_promedio_materias_1_y_10) {
    estudiante *un_estudiante = new_estudiante(62, (char *) "Johnny", (char *) "Allon", 81);
    materia *una_materia = new_materia(666, (char *) "Show and TV");
    materia *otra_materia = new_materia(777, (char *) "Musica popular");

    anotarse_materia(un_estudiante, una_materia);
    anotarse_materia(un_estudiante, otra_materia);

    rendir_materia(un_estudiante, otra_materia, 1);
    rendir_materia(un_estudiante, una_materia, 10);

    double promedio = calcular_promedio_estudiante(un_estudiante);

    ASSERT_EQ(promedio, 5.5);

    estudiante_destroy(un_estudiante);
}

TEST(PruebasEstudiante, calcular_promedio_sin_materias) {
    estudiante *un_estudiante = new_estudiante(62, (char *) "Johnny", (char *) "Allon", 81);

    double promedio = calcular_promedio_estudiante(un_estudiante);

    ASSERT_EQ(promedio, -1);

    estudiante_destroy(un_estudiante);
}

TEST(PruebasEstudiante, calcular_promedio_con_materia_sin_rendir) {
    estudiante *un_estudiante = new_estudiante(62, (char *) "Johnny", (char *) "Allon", 81);
    materia *una_materia = new_materia(666, (char *) "Show and TV");
    materia *otra_materia = new_materia(777, (char *) "Musica popular");

    anotarse_materia(un_estudiante, una_materia);
    anotarse_materia(un_estudiante, otra_materia);

    rendir_materia(un_estudiante, una_materia, 8);

    double promedio = calcular_promedio_estudiante(un_estudiante);

    ASSERT_EQ(promedio, 8);

    estudiante_destroy(un_estudiante);
}

void comparar_datos(unsigned long legajo, char *pNombre, char *pApellido, int edad, estudiante *estudiante) {
    ASSERT_EQ(estudiante->legajo, legajo);
    ASSERT_STREQ(estudiante->nombre, pNombre);
    ASSERT_STREQ(estudiante->apellido, pApellido);
    ASSERT_EQ(estudiante->edad, edad);
    ASSERT_NE(estudiante->lista_materias, nullptr);
}
