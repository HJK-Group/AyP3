#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/list/numerica.h>
}

void assert_ultimo_nodo_es_nulo(node *nodo);

TEST(PruebasLista, inicalmente_vacia) {
    list *lista = new_empty_list();
    ASSERT_NE(lista, nullptr);
    ASSERT_EQ(list_length(lista), 0);
    assert_ultimo_nodo_es_nulo(lista->head);

    list_destroy(lista);
}

TEST(PruebasLista, inicializada_con_item) {
    list *lista = new_list((void *) "item", sizeof("item"));
    ASSERT_TRUE(lista != nullptr);

    ASSERT_STREQ((char *) list_get_value(lista, 0), "item");

    assert_ultimo_nodo_es_nulo(lista->head->next);

    list_destroy(lista);
}

TEST(PruebasLista, agregar_datos_a_la_lista) {
    list *lista = new_empty_list();

    list_add(lista, (void *) "item", sizeof("item"));
    ASSERT_NE(lista->head->next, nullptr);
    ASSERT_NE(list_get_value(lista, 0), nullptr);
    ASSERT_EQ(list_length(lista), 1);

    ASSERT_STREQ((char *) list_get_value(lista, 0), "item");

    list_add(lista, (void *) "otro", sizeof("otro"));
    ASSERT_NE(lista->head->next->next, nullptr);
    ASSERT_NE(list_get_value(lista, 1), nullptr);
    ASSERT_EQ(list_length(lista), 2);

    ASSERT_STREQ((char *) list_get_value(lista, 1), "otro");

    assert_ultimo_nodo_es_nulo(lista->head->next->next);

    list_destroy(lista);
}

TEST(PruebasLista, obtener_primer_elemento_de_lista) {
    list *test_list = new_empty_list();
    int my_data = 2022;

    list_add(test_list, &my_data, sizeof(my_data));
    int data_returned = *((int *) list_get_value(test_list, 0));
    ASSERT_EQ(data_returned, my_data);

    list_destroy(test_list);
}

TEST(PruebasLista, obtener_dos_elementos_de_lista) {
    list *test_list = new_empty_list();
    int my_first_data = 2022;
    int my_second_data = 2001;

    list_add(test_list, &my_first_data, sizeof(my_first_data));
    list_add(test_list, &my_second_data, sizeof(my_second_data));

    int first_data_returned = *((int *) list_get_value(test_list, 0));
    ASSERT_EQ(first_data_returned, my_first_data);

    int second_data_returned = *((int *) list_get_value(test_list, 1));
    ASSERT_EQ(second_data_returned, my_second_data);

    list_destroy(test_list);
}

TEST(PruebasLista, obtener_elemento_por_data) {
    list *lista = new_empty_list();
    list_add(lista, (void *) "primer_item", sizeof("primer_item"));
    list_add(lista, (void *) "segundo_item", sizeof("segundo_item"));
    list_add(lista, (void *) "tercer_item", sizeof("tercer_item"));
    list_add(lista, (void *) "cuarto_item", sizeof("cuarto_item"));
    list_add(lista, (void *) "quinto_item", sizeof("quinto_item"));

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
    list_add(lista, (void *) "primer_item", sizeof("primer_item"));

    char *segundo = (char *) list_get_data(lista, (void *) "segundo_item", sizeof("segundo_item"));
    ASSERT_EQ(segundo, nullptr);

    list_destroy(lista);
}

TEST(PruebasLista, obtener_elemento_inexistente2) {
    list *lista = new_empty_list();
    list_add(lista, (void *) "primer_item", sizeof("primer_item"));
    list_add(lista, (void *) "tercer_item", sizeof("tercer_item"));

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
    list_add(lista, (void *) "primer_item", sizeof("primer_item"));
    list_add(lista, (void *) "segundo_item", sizeof("segundo_item"));
    list_add(lista, (void *) "tercer_item", sizeof("tercer_item"));

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
    list_add(lista, (void *) "primer_item", sizeof("primer_item"));
    list_add(lista, (void *) "segundo_item", sizeof("segundo_item"));
    list_add(lista, (void *) "tercer_item", sizeof("tercer_item"));
    list_add(lista, (void *) "cuarto_item", sizeof("cuarto_item"));

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
