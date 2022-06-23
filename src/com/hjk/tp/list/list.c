#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#define MAX_NUMBER_RECORDS 25

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

list *new_list(void *data) {
    list *lista = new_empty_list();
    list_add(lista, data);
    return lista;
}

void list_add(list *lista, void *data) {

    if (lista == NULL || data == NULL)
        return;

    node *aux = lista->head;
    while (aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = new_empty_node();
    aux->data = data;
    lista->length += 1;
}

int list_length(list *lista) {
    return lista->length;
}

void *list_get_value(list *lista, int index) {
    node *pNode = list_get(lista, index);
    if (pNode == NULL)
        return NULL;

    return pNode->data;
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

void *list_search_data(list *lista, int (*search_function)(void *data, void *other_data), void *other_data) {
    if (lista == NULL || lista->head == NULL || search_function == NULL || other_data == NULL)
        return NULL;

    node *itr_node = lista->head;
    while (itr_node != NULL && itr_node->data != NULL && !search_function(itr_node->data, other_data)) {
        itr_node = itr_node->next;
    }

    if (itr_node != NULL && itr_node->data != NULL && search_function(itr_node->data, other_data))
        return itr_node->data;

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

int list_contains(list *lista, int (*search_function)(void *data, void *other_data), void *other_data) {
    if (lista == NULL || lista->head == NULL || lista->length == 0 || search_function == NULL || other_data == NULL) {
        return 0;
    }

    return list_search_data(lista, search_function, other_data) != NULL;
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

int list_remove_data(list *lista, void *data, size_t data_size) {
    if (lista == NULL || lista->head == NULL || lista->length == 0 || data == NULL || data_size <= 0) {
        return -1;
    }

    node **pNode = &lista->head;
    while ((*pNode)->next != NULL && memcmp((*pNode)->data, data, data_size) != 0) {
        pNode = &(*pNode)->next;
    }

    node *node_remove = *pNode;
    *pNode = (*pNode)->next;
    free(node_remove);
    lista->length -= 1;
    return 0;
}

void list_print(list *lista, void (*print_function)(void *), int number_records)
{
    if (number_records == 0) {
        number_records = MAX_NUMBER_RECORDS;
    }

    int volver_a_imprimir = 0;
    node *nodo = lista->head;

    do {
        volver_a_imprimir = 0;
        int decrementer = number_records;

        while (nodo->next != NULL && decrementer > 0) {
            print_function(nodo->data);
            printf("\n");
            decrementer--;
            nodo = nodo->next;
        }

        // ToDo NO URGENTE: Mejorar este mensaje.
        printf("Desea continuar con la siguiente pagina? Si (1), No (0):");
        scanf("%i", &volver_a_imprimir);

        switch (volver_a_imprimir) {
            case 0:
                break;
            case 1:
                if (nodo->next == NULL) {
                    printf(">>> No hay mas datos\n\n");
                    volver_a_imprimir = 0;
                }
                break;
            default:
                printf(">>> Ninguna opcion correcta elegida\n\n");
                volver_a_imprimir = 0;
                break;
        }
    } while (volver_a_imprimir);
}

void list_destroy(list *lista) {
    node *nodo = lista->head;
    free(lista);

    while (nodo != NULL) {
        node *aux = nodo->next;
        free(nodo);
        nodo = aux;
    }
}
