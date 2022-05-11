#include <gtest/gtest.h>
extern "C" {
    #include <com/hjk/tp/list/list.h>
}

void assert_ultimo_nodo_es_nulo(list *lista) {
    ASSERT_EQ(lista->data, nullptr);
    ASSERT_EQ(lista->next, nullptr);
}

TEST(PruebasLista, inicalmente_vacia) {
    list *lista = new_empty_list();
    ASSERT_NE(lista, nullptr);
    assert_ultimo_nodo_es_nulo(lista);

    free(lista);
}

TEST(PruebasLista, inicializada_con_item) {
    const char *item = "item";
    list *lista = new_list((void*)item, sizeof("item"));
    ASSERT_TRUE(lista != nullptr);

    const char *item_en_lista = (char*)lista->data;
    ASSERT_EQ('i', *item_en_lista);
    ASSERT_EQ('t', *(item_en_lista + 1));
    ASSERT_EQ('e', *(item_en_lista + 2));
    ASSERT_EQ('m', *(item_en_lista + 3));

    assert_ultimo_nodo_es_nulo(lista->next);

    free(lista);
}

TEST(PruebasLista, agregar_datos_a_la_lista) {
    list *lista = new_empty_list();
    const char *item = "item";
    const char *otro_item = "otro";

    list_add(lista, (void*)item, sizeof("item"));
    ASSERT_NE(lista->next, nullptr);
    ASSERT_NE(lista->data, nullptr);

    const char *item_en_lista = (char*)lista->data;
    ASSERT_EQ('i', *item_en_lista);
    ASSERT_EQ('t', *(item_en_lista + 1));
    ASSERT_EQ('e', *(item_en_lista + 2));
    ASSERT_EQ('m', *(item_en_lista + 3));

    list_add(lista, (void*)otro_item, sizeof("otro"));
    ASSERT_NE(lista->next->next, nullptr);
    ASSERT_NE(lista->next->data, nullptr);

    const char *otro_item_en_lista = (char*)lista->next->data;
    ASSERT_EQ('o', *otro_item_en_lista);
    ASSERT_EQ('t', *(otro_item_en_lista + 1));
    ASSERT_EQ('r', *(otro_item_en_lista + 2));
    ASSERT_EQ('o', *(otro_item_en_lista + 3));

    assert_ultimo_nodo_es_nulo(lista->next->next);

    free(lista);
}
