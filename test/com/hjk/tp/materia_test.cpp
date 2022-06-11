#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/materia/materia.h>
}

TEST(PruebasMateria, crear_una_materia) {
    materia *materia = new_materia(666, (char *) "Analisis I");
    ASSERT_EQ(materia->id, 666);
    ASSERT_STREQ(materia->nombre, "Analisis I");
    free(materia);
}
