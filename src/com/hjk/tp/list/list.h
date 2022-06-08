#ifndef core_LIST_H
#define core_LIST_H

#include <stdio.h>

typedef struct node {
    struct node *next;
    void *data;
} node;

typedef struct list {
    node *head;
    int length;
} list;

list *new_empty_list();

list *new_list(void *data, size_t data_size);

void list_add(list *lista, void *data, size_t data_size);

int list_length(list *lista);

void *list_get_value(list *lista, int index);

void *list_get_by_data(list *lista, void *dato, size_t data_size);

int list_remove(list *lista, int index);

void list_print(list *lista, void (*print_function)(void *data));

void list_destroy(list *lista);

#endif //core_LIST_H
