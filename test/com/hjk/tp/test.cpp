#include <gtest/gtest.h>

extern "C" {
#include <com/hjk/tp/list/list.h>
}

void assert_ultimo_nodo_es_nulo(node *nodo) {
    ASSERT_NE(nodo, nullptr);
    ASSERT_EQ(nodo->data, nullptr);
    ASSERT_EQ(nodo->next, nullptr);
}

TEST(PruebasLista, inicalmente_vacia) {
    list *lista = new_empty_list();
    ASSERT_NE(lista, nullptr);
    ASSERT_EQ(list_length(lista), 0);
    assert_ultimo_nodo_es_nulo(lista->head);

    free(lista);
}

TEST(PruebasLista, inicializada_con_item) {
    list *lista = new_list((void *) "item", sizeof("item"));
    ASSERT_TRUE(lista != nullptr);

    const char *item_en_lista = (char *) list_get_value(lista, 0);
    ASSERT_EQ('i', *item_en_lista);
    ASSERT_EQ('t', *(item_en_lista + 1));
    ASSERT_EQ('e', *(item_en_lista + 2));
    ASSERT_EQ('m', *(item_en_lista + 3));

    assert_ultimo_nodo_es_nulo(lista->head->next);

    free(lista->head->next);
    free(lista->head);
    free(lista);
}

TEST(PruebasLista, agregar_datos_a_la_lista) {
    list *lista = new_empty_list();

    list_add(lista, (void *) "item", sizeof("item"));
    ASSERT_NE(lista->head->next, nullptr);
    ASSERT_NE(lista->head->data, nullptr);
    ASSERT_EQ(list_length(lista), 1);

    const char *item_en_lista = (char *) list_get_value(lista, 0);
    ASSERT_EQ('i', *item_en_lista);
    ASSERT_EQ('t', *(item_en_lista + 1));
    ASSERT_EQ('e', *(item_en_lista + 2));
    ASSERT_EQ('m', *(item_en_lista + 3));

    list_add(lista, (void *) "otro", sizeof("otro"));
    ASSERT_NE(lista->head->next->next, nullptr);
    ASSERT_NE(lista->head->next->data, nullptr);
    ASSERT_EQ(list_length(lista), 2);

    const char *otro_item_en_lista = (char *) list_get_value(lista, 1);
    ASSERT_EQ('o', *otro_item_en_lista);
    ASSERT_EQ('t', *(otro_item_en_lista + 1));
    ASSERT_EQ('r', *(otro_item_en_lista + 2));
    ASSERT_EQ('o', *(otro_item_en_lista + 3));

    assert_ultimo_nodo_es_nulo(lista->head->next->next);

    free(lista->head->next->next);
    free(lista->head->next);
    free(lista->head);
    free(lista);
}
