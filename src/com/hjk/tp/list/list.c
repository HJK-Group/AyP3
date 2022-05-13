#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

node *new_empty_node();
node *list_get(list *lista, int index);

list *new_empty_list() {
    list *lista = malloc(sizeof(list));
    if (lista != NULL) {
        lista->head = new_empty_node();
        lista->length = 0;
    }

    return lista;
}

node *list_get(list *lista, int index) {
    node *aux = lista->head;
    if (index > lista->length) {
        return NULL;
    }
    for (int i = 0; i < index && aux->next != NULL; ++i) {
        aux = aux->next;
    }
    return aux;
}

node *new_empty_node() {
    node *nodo = malloc(sizeof(node));
    if (nodo != NULL) {
        nodo->data = NULL;
        nodo->next = NULL;
    }

    return nodo;
}

list *new_list(void *data, size_t data_size) {
    list *lista = new_empty_list();
    list_add(lista, data, data_size);
    return lista;
}

void list_add(list *lista, void *data, size_t data_size) {

    if (lista == NULL || data == NULL || data_size <= 0)
        return;

    void *item = malloc(data_size);
    memcpy(item, data, data_size);

    node *aux = lista->head;
    while (aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = new_empty_node();
    aux->data = item;
    lista->length += 1;
}

int list_length(list *list) {
    return list->length;
}

void *list_get_value(list *list_parameter, int index) {
    return list_get(list_parameter, index)->data;
}

int list_remove(list *lista, int index) {
    if (index < 0 || index > lista->length - 1) {
        return -1;
    }

    node *node_remove;
    if (index == 0) {
        node_remove = lista->head;
        lista->head = lista->head->next;
    } else {
        node *change_prev_node = list_get(lista, index - 1);
        node_remove = change_prev_node->next;
        change_prev_node->next = node_remove->next;
    }

    free(node_remove);
    lista->length -= 1;
    return 0;
}

void list_print(list *list_parameter) {
    node *list_pointer = list_parameter->head;

    while (list_pointer->next != NULL) {
        // Complicado imprimir un genérico.
        printf("%s", "Data.");
        list_pointer = list_pointer->next;
    }

}

void list_destroy(list *list) {
    node *nodo = list->head;
    free(list);

    node *aux;
    while(nodo != NULL) {
        aux = nodo->next;
        free(nodo);
        nodo = aux;
    }
}
