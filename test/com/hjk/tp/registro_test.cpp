#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/estudiante/registro.h>
}

TEST(PruebasRegistro, crear_un_registro) {
    registro *un_registro = new_registro();
    estudiante *un_estudiante = new_estudiante(1, (char *) "Hernan", (char *) "Rubio", 18);

    registro_agregar_alumno(un_registro, un_estudiante);

    registro_destroy(un_registro);
}

TEST(PruebasRegistro, elementos_de_ambas_son_identicos) {
    registro *un_registro = new_registro();
    estudiante *un_estudiante = new_estudiante(1, (char *) "Hernan", (char *) "Rubio", 18);

    registro_agregar_alumno(un_registro, un_estudiante);

    auto *data_list_ordered_by_name = (estudiante *) un_registro->listado_por_nombre->generic_list->head->data;
    auto *data_list_ordered_by_age = (estudiante *) un_registro->listado_por_edad->generic_list->head->data;

    ASSERT_STREQ(data_list_ordered_by_name->nombre, data_list_ordered_by_age->nombre);
    ASSERT_STREQ(data_list_ordered_by_name->apellido, data_list_ordered_by_age->apellido);
    ASSERT_EQ(data_list_ordered_by_name->edad, data_list_ordered_by_age->edad);
    ASSERT_EQ(data_list_ordered_by_name->legajo, data_list_ordered_by_age->legajo);

    ASSERT_EQ(data_list_ordered_by_name, data_list_ordered_by_age);

    registro_destroy(un_registro);
}

TEST(PruebasRegistro, dos_estudiantes_ordenados_bien_menor_a_mayor_en_ambas_listas) {
    registro *un_registro = new_registro();
    estudiante *un_estudiante = new_estudiante(1, (char *) "Juan", (char *) "Calvinio", 29);
    estudiante *otro_estudiante = new_estudiante(2, (char *) "Kevin", (char *) "Tubio", 25);

    registro_agregar_alumno(un_registro, un_estudiante);
    registro_agregar_alumno(un_registro, otro_estudiante);

    auto *data_list_ordered_by_name = (estudiante *) un_registro->listado_por_nombre->generic_list->head->data;
    auto *data_list_ordered_by_age = (estudiante *) un_registro->listado_por_edad->generic_list->head->data;

    ASSERT_STREQ(data_list_ordered_by_name->nombre, "Juan");
    ASSERT_EQ(data_list_ordered_by_name->edad, 29);

    ASSERT_STREQ(data_list_ordered_by_age->nombre, "Kevin");
    ASSERT_EQ(data_list_ordered_by_age->edad, 25);

    registro_destroy(un_registro);
}

TEST(PruebasRegistro, obtener_estudiante_registro_por_nombre) {
    registro *pRegistro = new_registro();
    estudiante *pHernan = new_estudiante(1, (char *) "Hernan", (char *) "Rubio", 21);
    estudiante *pJuan = new_estudiante(2, (char *) "Juan", (char *) "Calviño", 29);
    estudiante *pKevin = new_estudiante(3, (char *) "Kevin", (char *) "Tubio", 25);
    registro_agregar_alumno(pRegistro, pHernan);
    registro_agregar_alumno(pRegistro, pJuan);
    registro_agregar_alumno(pRegistro, pKevin);

    estudiante *estudiante_buscado = registro_buscar_por_nombre(pRegistro, (char *) "Juan");
    ASSERT_EQ(estudiante_buscado, pJuan);
    ASSERT_EQ(estudiante_buscado->legajo, 2);
    ASSERT_STREQ(estudiante_buscado->nombre, "Juan");
    ASSERT_STREQ(estudiante_buscado->apellido, "Calviño");
    ASSERT_EQ(estudiante_buscado->edad, 29);

    registro_destroy(pRegistro);
}

TEST(PruebasRegistro, obtener_estudiantes_registro_por_edad_20_a_30) {
    registro *pRegistro = new_registro();
    estudiante *pEstudiante_en_rango_mayor = new_estudiante(1, (char *) "Juan", (char *) "Calvino", 33);
    estudiante *pEstudiante_en_rango_1 = new_estudiante(2, (char *) "Kevin", (char *) "Tubio", 25);
    estudiante *pEstudiante_en_rango_2 = new_estudiante(3, (char *) "Hernan", (char *) "Rubio", 20);

    registro_agregar_alumno(pRegistro, pEstudiante_en_rango_mayor);
    registro_agregar_alumno(pRegistro, pEstudiante_en_rango_1);
    registro_agregar_alumno(pRegistro, pEstudiante_en_rango_2);

    listado *pLista_estudiantes_mayores_de_20 = registro_buscar_por_edad(pRegistro, 20, 30);
    node *iterador = pLista_estudiantes_mayores_de_20->generic_list->head;

    ASSERT_EQ(pLista_estudiantes_mayores_de_20->generic_list->length, 2);
    ASSERT_STREQ(((estudiante *) iterador->data)->nombre, "Hernan");
    ASSERT_EQ(iterador->data, pEstudiante_en_rango_2);

    iterador = iterador->next;
    ASSERT_STREQ(((estudiante *) iterador->data)->nombre, "Kevin");
    ASSERT_EQ(iterador->data, pEstudiante_en_rango_1);

    registro_destroy(pRegistro);
    estudiante_destroy(pEstudiante_en_rango_mayor);
    estudiante_destroy(pEstudiante_en_rango_1);
    estudiante_destroy(pEstudiante_en_rango_2);
    listado_destroy(pLista_estudiantes_mayores_de_20);
}

TEST(PruebasRegistro, obtener_estudiantes_por_edad_solo_devuelve_lo_existente) {
    registro *pRegistro = new_registro();
    estudiante *pEstudiante_en_rango_mayor = new_estudiante(1, (char *) "Juan", (char *) "Calvino", 33);
    registro_agregar_alumno(pRegistro, pEstudiante_en_rango_mayor);

    listado *pLista_estudiantes_mayores_de_20 = registro_buscar_por_edad(pRegistro, 32, 33);
    node *iterador = pLista_estudiantes_mayores_de_20->generic_list->head;

    ASSERT_EQ(pLista_estudiantes_mayores_de_20->generic_list->length, 1);
    ASSERT_STREQ(((estudiante *) iterador->data)->nombre, "Juan");
    ASSERT_EQ(iterador->data, pEstudiante_en_rango_mayor);

    ASSERT_TRUE(iterador->next->data == nullptr);

    registro_destroy(pRegistro);
    estudiante_destroy(pEstudiante_en_rango_mayor);
    listado_destroy(pLista_estudiantes_mayores_de_20);
}
