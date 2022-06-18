#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/list/numerica.h>
#include <com/hjk/tp/utils/utils.h>
}

void assert_ultimo_nodo_es_nulo(node *nodo);

TEST(PruebasLista, inicialmente_vacia) {
    list *lista = new_empty_list();
    ASSERT_NE(lista, nullptr);
    ASSERT_EQ(list_length(lista), 0);
    assert_ultimo_nodo_es_nulo(lista->head);

    list_destroy(lista);
}

TEST(PruebasLista, inicializada_con_item) {
    list *lista = new_list(new_string((char *) "item"));
    ASSERT_TRUE(lista != nullptr);

    ASSERT_STREQ((char *) list_get_value(lista, 0), "item");

    assert_ultimo_nodo_es_nulo(lista->head->next);

    list_destroy(lista);
}

TEST(PruebasLista, agregar_datos_a_la_lista) {
    list *lista = new_empty_list();

    list_add(lista, new_string((char *) "item"));
    ASSERT_NE(lista->head->next, nullptr);
    ASSERT_NE(list_get_value(lista, 0), nullptr);
    ASSERT_EQ(list_length(lista), 1);

    ASSERT_STREQ((char *) list_get_value(lista, 0), "item");

    list_add(lista, new_string((char *) "otro"));
    ASSERT_NE(lista->head->next->next, nullptr);
    ASSERT_NE(list_get_value(lista, 1), nullptr);
    ASSERT_EQ(list_length(lista), 2);

    ASSERT_STREQ((char *) list_get_value(lista, 1), "otro");

    assert_ultimo_nodo_es_nulo(lista->head->next->next);

    list_destroy(lista);
}

TEST(PruebasLista, obtener_primer_elemento_de_lista) {
    list *test_list = new_empty_list();
    list_add(test_list, new_integer(2022));
    int data_returned = *((int *) list_get_value(test_list, 0));
    ASSERT_EQ(data_returned, 2022);

    list_destroy(test_list);
}

TEST(PruebasLista, obtener_dos_elementos_de_lista) {
    list *test_list = new_empty_list();

    list_add(test_list, new_integer(2022));
    list_add(test_list, new_integer(2001));

    ASSERT_EQ(*((int *) list_get_value(test_list, 0)), 2022);
    ASSERT_EQ(*((int *) list_get_value(test_list, 1)), 2001);

    list_destroy(test_list);
}

TEST(PruebasLista, obtener_elemento_por_data) {
    list *lista = new_empty_list();

    list_add(lista, new_string((char *) "primer_item"));
    list_add(lista, new_string((char *) "segundo_item"));
    list_add(lista, new_string((char *) "tercer_item"));
    list_add(lista, new_string((char *) "cuarto_item"));
    list_add(lista, new_string((char *) "quinto_item"));

    char *primero = (char *) list_get_data(lista, (void *) "primer_item", sizeof("primer_item"));
    ASSERT_STREQ(primero, "primer_item");

    char *segundo = (char *) list_get_data(lista, (void *) "segundo_item", sizeof("segundo_item"));
    ASSERT_STREQ(segundo, "segundo_item");

    char *quinto = (char *) list_get_data(lista, (void *) "quinto_item", sizeof("quinto_item"));
    ASSERT_STREQ(quinto, "quinto_item");

    list_destroy(lista);
}

TEST(PruebasLista, obtener_elemento_inexistente) {
    list *lista = new_empty_list();
    list_add(lista, new_string((char *) "primer_item"));

    char *segundo = (char *) list_get_data(lista, (void *) "segundo_item", sizeof("segundo_item"));
    ASSERT_EQ(segundo, nullptr);

    list_destroy(lista);
}

TEST(PruebasLista, obtener_elemento_inexistente2) {
    list *lista = new_empty_list();
    list_add(lista, new_string((char *) "primer_item"));
    list_add(lista, new_string((char *) "tercer_item"));

    char *segundo = (char *) list_get_data(lista, (void *) "segundo_item", sizeof("segundo_item"));
    ASSERT_EQ(segundo, nullptr);

    list_destroy(lista);
}

TEST(PruebasLista, obtener_elemento_inexistente3) {
    list *lista = new_empty_list();

    char *segundo = (char *) list_get_data(lista, (void *) "segundo_item", sizeof("segundo_item"));
    ASSERT_EQ(segundo, nullptr);

    list_destroy(lista);
}

TEST(PruebasLista, remover_elemento_por_data) {
    list *lista = new_empty_list();
    list_add(lista, new_string((char *) "primer_item"));
    list_add(lista, new_string((char *) "segundo_item"));
    list_add(lista, new_string((char *) "tercer_item"));

    list_remove_data(lista, (void *) "segundo_item", sizeof("segundo_item"));
    list_remove_data(lista, (void *) "tercer_item", sizeof("tercer_item"));

    ASSERT_EQ(list_length(lista), 1);
    ASSERT_NE(list_get_value(lista, 0), nullptr);
    ASSERT_EQ(list_get_value(lista, 1), nullptr);
    ASSERT_EQ(list_get_value(lista, 2), nullptr);

    list_destroy(lista);
}

TEST(PruebasLista, remover_elemento_por_data2) {
    list *lista = new_empty_list();
    list_add(lista, new_string((char *) "primer_item"));
    list_add(lista, new_string((char *) "segundo_item"));
    list_add(lista, new_string((char *) "tercer_item"));
    list_add(lista, new_string((char *) "cuarto_item"));

    list_remove_data(lista, (void *) "segundo_item", sizeof("segundo_item"));
    list_remove_data(lista, (void *) "tercer_item", sizeof("tercer_item"));

    ASSERT_EQ(list_length(lista), 2);
    ASSERT_NE(list_get_value(lista, 0), nullptr);
    ASSERT_NE(list_get_value(lista, 1), nullptr);
    ASSERT_STREQ((char *) list_get_value(lista, 0), "primer_item");
    ASSERT_STREQ((char *) list_get_value(lista, 1), "cuarto_item");
    ASSERT_EQ(list_get_value(lista, 2), nullptr);
    ASSERT_EQ(list_get_value(lista, 3), nullptr);

    list_destroy(lista);
}

TEST(PruebasListaNumerica, agregar_numeros) {
    numeric_list *lista = new_empty_numeric_list();
    numeric_list_add(lista, 0);
    numeric_list_add(lista, 20);
    numeric_list_add(lista, 234);
    numeric_list_add(lista, -2);

    ASSERT_EQ(-2, numeric_list_get(lista, 0));
    ASSERT_EQ(0, numeric_list_get(lista, 1));
    ASSERT_EQ(20, numeric_list_get(lista, 2));
    ASSERT_EQ(234, numeric_list_get(lista, 3));

    numeric_list_destroy(lista);
}

TEST(PruebasListaNumerica, agregar_numeros2) {
    numeric_list *lista = new_empty_numeric_list();
    numeric_list_add(lista, 0);
    numeric_list_add(lista, -20);
    numeric_list_add(lista, -234);
    numeric_list_add(lista, -2);
    numeric_list_add(lista, 10);
    numeric_list_add(lista, 20);
    numeric_list_add(lista, 50);
    numeric_list_add(lista, 0);
    numeric_list_add(lista, -2);

    ASSERT_EQ(-234, numeric_list_get(lista, 0));
    ASSERT_EQ(-20, numeric_list_get(lista, 1));
    ASSERT_EQ(-2, numeric_list_get(lista, 2));
    ASSERT_EQ(-2, numeric_list_get(lista, 3));
    ASSERT_EQ(0, numeric_list_get(lista, 4));
    ASSERT_EQ(0, numeric_list_get(lista, 5));
    ASSERT_EQ(10, numeric_list_get(lista, 6));
    ASSERT_EQ(20, numeric_list_get(lista, 7));
    ASSERT_EQ(50, numeric_list_get(lista, 8));

    numeric_list_destroy(lista);
}

void assert_ultimo_nodo_es_nulo(node *nodo) {
    ASSERT_NE(nodo, nullptr);
    ASSERT_EQ(nodo->data, nullptr);
    ASSERT_EQ(nodo->next, nullptr);
}
