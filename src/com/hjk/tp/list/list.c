#include "list.h"
#include <stdlib.h>
#include <stdio.h>

node *list_get(list *lista, int index);

node *new_empty_node() {
    node *nodo = malloc(sizeof(node));
    nodo->data = NULL;
    nodo->next = NULL;
    return nodo;
}

list *new_empty_list() {
    list *lista = malloc(sizeof(list));
    lista->head = new_empty_node();
    lista->length = 0;
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
    return list_get(list_parameter, index)->data;
}

int list_remove(list *lista, int index) {
    if (index < 0 || index > lista->length - 1) {
        return -1;
    }
    if (index == 0){
        node* head_node = lista->head->next;
        lista->head = head_node;
        return 0;
    }
    node* change_prev_node = list_get(lista, index -1);
    node* node_remove = change_prev_node->next;
    node* change_next_node = node_remove->next;

    change_prev_node->next = change_next_node;
    free(node_remove);
    
    return 0;
}

void list_print(list *list_parameter) {
    node *list_pointer = list_parameter;

    while (list_pointer->next != NULL) {
        // Complicado imprimir un genérico.
        printf("%s", "Data.");
        list_pointer = list_pointer->next;
    }
}