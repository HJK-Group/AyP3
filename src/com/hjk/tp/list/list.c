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

int list_length(list *lista) {
    return lista->length;
}

void *list_get_value(list *lista, int index) {
    return list_get(lista, index)->data;
}

void *list_get_data(list *lista, void *data, size_t data_size) {
    if (lista == NULL || lista->head == NULL || lista->length == 0 || data == NULL || data_size <= 0) {
        return NULL;
    }

    node *pNode = NULL;
    node *actual = lista->head;
    while (actual != NULL && actual->data != NULL) {
        if (memcmp(actual->data, data, data_size) == 0) {
            pNode = actual;
            break;
        }

        actual = actual->next;
    }

    if (pNode != NULL) {
        return pNode->data;
    }

    return NULL;
}

node *list_get(list *lista, int index) {
    if (lista == NULL || lista->head == NULL || lista->length == 0 || index < 0 || index >= lista->length) {
        return NULL;
    }

    node *aux = lista->head;
    for (int i = 0; i < index && aux->next != NULL; ++i) {
        aux = aux->next;
    }
    return aux;
}

int list_remove(list *lista, int index) {
    if (lista == NULL || lista->head == NULL || lista->length == 0 || index < 0 || index >= lista->length) {
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

void list_print(list *lista, void (*print_function)(void *data)) {
    node *nodo = lista->head;
    while(nodo->next != NULL){
        print_function(nodo->data);
        nodo = nodo->next;
    }
}

void list_destroy(list *lista) {
    node *nodo = lista->head;
    free(lista);

    while(nodo != NULL) {
        node *aux = nodo->next;
        free(nodo);
        nodo = aux;
    }
}
