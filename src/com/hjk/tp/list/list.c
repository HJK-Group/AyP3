#include "list.h"
#include <stdlib.h>
#include <stdio.h>

node *list_get(list *lista, int index);

list *new_empty_list() {
    list *lista = malloc(sizeof(list));
    lista->data = NULL;
    lista->next = NULL;
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

list *new_list(void *data, size_t data_size) {
    list *lista = new_empty_list();
    list_add(lista, data, data_size);
    return lista;
}

void list_add(list *lista, void *data, size_t data_size) {

    void *item = malloc(data_size);
    for (int i = 0; i < data_size; i++) {
        // char *mi_variable = (char*)item + 1;
        *((char *) item + i) = *((char *) data + i);
    }

    node *aux = lista->head;
    while (aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = malloc(sizeof(list));
    aux->data = item;
    aux->next->next = NULL;
    aux->next->data = NULL;
}

int list_length(list *list) {
    return list->length;
}


void *list_get_value(list *list_parameter, int index) {
    return list_get(list_parameter, index);
}

void list_remove(list *list, int index) {
}


void list_print(list *list_parameter) {
    node *list_pointer = list_parameter;

    while (list_pointer->next != NULL) {
        // Complicado imprimir un genérico.
        printf("%s", "Data.");
        list_pointer = list_pointer->next;
    }
}