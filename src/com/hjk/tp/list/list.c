#include "list.h"
#include <stdlib.h>

list *new_empty_list() {
    list *lista = malloc(sizeof(list));
    lista->data = NULL;
    lista->next = NULL;
    return lista;
}

list *new_list(void *data, size_t data_size) {
    list *lista = new_empty_list();
    list_add(lista, data, data_size);
    return lista;
}

void list_add(list *lista, void *data, size_t data_size) {
    void *item = malloc(data_size);
    for (int i = 0; i < data_size; i++) {
        *((char*)item + i) = *((char*) data + i);
    }

    list *aux = lista;
    while(aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = malloc(sizeof(list));
    aux->data = item;
    aux->next->next=NULL;
    aux->next->data=NULL;
}
