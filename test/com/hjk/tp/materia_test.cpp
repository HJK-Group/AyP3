#include <gtest/gtest.h>

extern "C" {

#include <com/hjk/tp/materia/materia.h>
#include <com/hjk/tp/list/list.h>
#include <com/hjk/tp/estudiante/estudiante.h>
}

TEST(PruebasMateria, crear_una_materia) {
    materia *pMateria = new_materia(666, (char *) "Analisis I");
    ASSERT_EQ(pMateria->id, 666);
    ASSERT_STREQ(pMateria->nombre, "Analisis I");
    materia_destroy(pMateria);
}

TEST(PruebasMateria, anadir_correlativa_a_materia) {
    materia *pMateria = new_materia(666, (char *) "Analisis I");
    materia *pCorrelativa = new_materia(777, (char *) "Algebra II");

    materia_add_correlativas(pMateria, pCorrelativa);

    auto *correlativa_almacenada = (materia *) pMateria->pCorrelativas->head->data;
    ASSERT_STREQ(correlativa_almacenada->nombre, "Algebra II");
    materia_destroy(pMateria);
}

TEST(PruebasMateria, anadir_dos_correlativas_de_manera_lineal) {
    materia *pMateria = new_materia(666, (char *) "Analisis I");
    materia *pPrimerCorrelativa = new_materia(777, (char *) "Algebra II");
    materia *pSegundaCorrelativa = new_materia(888, (char *) "Quimica I");

    materia_add_correlativas(pMateria, pPrimerCorrelativa);
    materia_add_correlativas(pPrimerCorrelativa, pSegundaCorrelativa);

    auto *correlativa_almacenada = (materia *) pMateria->pCorrelativas->head->data;
    ASSERT_STREQ(((materia *) correlativa_almacenada->pCorrelativas->head->data)->nombre, "Quimica I");
    materia_destroy(pMateria);
}

TEST(PruebasMateria, no_se_puede_anotar_a_una_materia_que_no_es_correlativa) {
    materia *pAnalisis1 = new_materia(666, (char *) "Analisis I");
    materia *pAnalisis2 = new_materia(777, (char *) "Analisis II");
    materia *pAnalisis3 = new_materia(888, (char *) "Analisis III");

    estudiante *pEstudiante = new_estudiante(123456789, (char *) "Juan", (char *) "Perez", 20);

    materia_add_correlativas(pAnalisis3, pAnalisis2);
    materia_add_correlativas(pAnalisis2, pAnalisis1);

    anotarse_materia(pEstudiante, pAnalisis2);
    anotarse_materia(pEstudiante, pAnalisis3);

    curso *curso_almacenado = ((curso*) pEstudiante->lista_materias->head->data);

    ASSERT_EQ(curso_almacenado, nullptr);
}

TEST(PruebasMateria, no_se_anade_correlativa_ya_anadida) {
    materia *pMateria = new_materia(666, (char *) "Analisis I");
    materia *pCorrelativa = new_materia(777, (char *) "Algebra II");

    materia_add_correlativas(pMateria, pCorrelativa);
    materia_add_correlativas(pMateria, pCorrelativa);

    auto *correlativa_almacenada = (materia *) pMateria->pCorrelativas->head->data;
    ASSERT_EQ(correlativa_almacenada->pCorrelativas->head->data, nullptr);
    ASSERT_EQ(correlativa_almacenada->pCorrelativas->head->next, nullptr);
    materia_destroy(pMateria);
}
