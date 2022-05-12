#ifndef AYP3_LIST_H
#define AYP3_LIST_H

#include <stdio.h>

typedef struct node {
    struct node *next;
    void *data;
} node;

typedef struct list {
    node* head;
    int length;
} list;

list *new_empty_list();

list *new_list(void *data, size_t data_size);

void list_add(list *list, void *data, size_t data_size);

int list_length(list *list);

void* list_get_value(list* list_parameter, int index);

int list_remove(list *list, int index);

void list_print(list *list);

#endif //AYP3_LIST_H
