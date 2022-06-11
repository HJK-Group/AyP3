#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/materia/materia.h>
}

TEST(PruebasMateria, crear_una_materia) {
    materia *pMateria = new_materia(666, (char *) "Analisis I");
    ASSERT_EQ(pMateria->id, 666);
    ASSERT_STREQ(pMateria->nombre, "Analisis I");
    free(pMateria);
}
