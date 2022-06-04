#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/list/numerica.h>
}

void assert_ultimo_nodo_es_nulo(node *nodo);

TEST(PruebasLista, inicalmente_vacia)
{
    list *lista = new_empty_list();
    ASSERT_NE(lista, nullptr);
    ASSERT_EQ(list_length(lista), 0);
    assert_ultimo_nodo_es_nulo(lista->head);

    list_destroy(lista);
}

TEST(PruebasLista, inicializada_con_item)
{
    list *lista = new_list((void *) "item", sizeof("item"));
    ASSERT_TRUE(lista != nullptr);

    const char *item_en_lista = (char *) list_get_value(lista, 0);
    ASSERT_EQ('i', *item_en_lista);
    ASSERT_EQ('t', *(item_en_lista + 1));
    ASSERT_EQ('e', *(item_en_lista + 2));
    ASSERT_EQ('m', *(item_en_lista + 3));

    assert_ultimo_nodo_es_nulo(lista->head->next);

    list_destroy(lista);
}

TEST(PruebasLista, agregar_datos_a_la_lista)
{
    list *lista = new_empty_list();

    list_add(lista, (void *) "item", sizeof("item"));
    ASSERT_NE(lista->head->next, nullptr);
    ASSERT_NE(list_get_value(lista, 0), nullptr);
    ASSERT_EQ(list_length(lista), 1);

    const char *item_en_lista = (char *) list_get_value(lista, 0);
    ASSERT_EQ('i', *item_en_lista);
    ASSERT_EQ('t', *(item_en_lista + 1));
    ASSERT_EQ('e', *(item_en_lista + 2));
    ASSERT_EQ('m', *(item_en_lista + 3));

    list_add(lista, (void *) "otro", sizeof("otro"));
    ASSERT_NE(lista->head->next->next, nullptr);
    ASSERT_NE(list_get_value(lista, 1), nullptr);
    ASSERT_EQ(list_length(lista), 2);

    const char *otro_item_en_lista = (char *) list_get_value(lista, 1);
    ASSERT_EQ('o', *otro_item_en_lista);
    ASSERT_EQ('t', *(otro_item_en_lista + 1));
    ASSERT_EQ('r', *(otro_item_en_lista + 2));
    ASSERT_EQ('o', *(otro_item_en_lista + 3));

    assert_ultimo_nodo_es_nulo(lista->head->next->next);

    list_destroy(lista);
}

TEST(PruebasLista, obtener_primer_elemento_de_lista)
{
    list *test_list = new_empty_list();
    int my_data = 2022;

    list_add(test_list, &my_data, sizeof(my_data));
    int data_returned = *((int *) list_get_value(test_list, 0));
    ASSERT_EQ(data_returned, my_data);

    list_destroy(test_list);
}

TEST(PruebasLista, obtener_dos_elementos_de_lista)
{
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

TEST(PruebasListaNumerica, agregar_numeros) {
    numeric_list *lista = new_empty_numeric_list();

    numeric_list_add(lista, 0);
    ASSERT_EQ(0, numeric_list_get(lista, 0));

    numeric_list_add(lista, 20);
    ASSERT_EQ(0, numeric_list_get(lista, 0));
    ASSERT_EQ(20, numeric_list_get(lista, 1));

    numeric_list_add(lista, 234);
    ASSERT_EQ(0, numeric_list_get(lista, 0));
    ASSERT_EQ(20, numeric_list_get(lista, 1));
    ASSERT_EQ(234, numeric_list_get(lista, 2));

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

void assert_ultimo_nodo_es_nulo(node *nodo)
{
    ASSERT_NE(nodo, nullptr);
    ASSERT_EQ(nodo->data, nullptr);
    ASSERT_EQ(nodo->next, nullptr);
}
