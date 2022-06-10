#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/materia/materia.h>
}

TEST(PruebasMateria, crear_una_materia) {
    materia *materia = new_materia("MAT2022", "Analisis I");
    ASSERT_STREQ(materia->id, "MAT2022");
    ASSERT_STREQ(materia->nombre, "Analisis I");
    free(materia);
}

TEST(PruebasMateria, materia_al_ser_creada_tiene_nota_cero) {
    materia *materia = new_materia("MAT2022", "Analisis I");
    ASSERT_EQ(materia->nota, 0);
}

TEST(PruebasMateria, crear_materia_con_id_mayor_al_maximo_permitido) {
    materia *materia = new_materia("LAMEJORMATERIADELANIO", "Analisis I");
    ASSERT_STREQ(materia->id, "LAMEJORMA");
    ASSERT_STREQ(materia->nombre, "Analisis I");
    free(materia);
}

TEST(PruebasMateria, crear_materia_con_nombre_mayor_al_maximo_permitido) {
    materia *materia = new_materia("MAT2022", "Maestria en Analisis Algebraico con orientacion Multiple en Sociología y aplicativos medicos varios");
    ASSERT_STREQ(materia->id, "MAT2022");
    ASSERT_STREQ(materia->nombre, "Maestria en Analisis Alg");
    free(materia);
}