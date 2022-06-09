#include <stdlib.h>
#include <memory.h>
#include "ordered.h"

ordered_list *new_empty_ordered_list(int (*comparator)(void *data, void *other_data)) {
    ordered_list *lista = malloc(sizeof(ordered_list));
    lista->generic_list = new_empty_list();
    lista->comparador = comparator;
    return lista;
}

ordered_list *new_ordered_list(void *data, size_t data_size, int (*comparator)(void *data, void *other_data)) {
    ordered_list *lista = new_empty_ordered_list(comparator);
    ordered_list_add(lista, data, data_size);
    return lista;
}

int es_menor(ordered_list *lista, node *actual, void *data) {
    return lista->comparador(actual->data, data) <= 0;
}

void ordered_list_add(ordered_list *lista, void *data, size_t data_size) {
    if (data == NULL)
        return;

    node *itr_node = lista->generic_list->head;
    while (itr_node->next != NULL && es_menor(lista, itr_node, data)) {
        itr_node = itr_node->next;
    }

    node *insert_node = malloc(sizeof(node));
    insert_node->next = itr_node->next;
    insert_node->data = itr_node->data;

    itr_node->next = insert_node;
    itr_node->data = malloc(data_size);
    memcpy(itr_node->data, data, data_size);
    lista->generic_list->length++;
}

int ordered_list_length(ordered_list *lista) {
    return list_length(lista->generic_list);
}

void *ordered_list_get_value(ordered_list *lista, int index) {
    return list_get_value(lista->generic_list, index);
}

void *ordered_list_get_data(ordered_list *lista, void *data, size_t data_size) {
    return list_get_data(lista->generic_list, data, data_size);
}

int ordered_list_remove(ordered_list *lista, int index) {
    return list_remove(lista->generic_list, index);
}

void ordered_list_print(ordered_list *lista, void (*print_function)(void *data)) {
    list_print(lista->generic_list, print_function);
}

void ordered_list_destroy(ordered_list *lista) {
    list_destroy(lista->generic_list);
    free(lista);
}
