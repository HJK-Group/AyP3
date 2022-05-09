#ifndef AYP3_LIST_H
#define AYP3_LIST_H

#include <stdio.h>

typedef struct list {
    struct list *next;
    void *data;
} list;

list *new_list(void *data, size_t data_size);

void list_add(list *list, void *data, size_t data_size);

int list_length(list *list);

void *list_get(list* list, int index);

void list_remove(list *list, int index);

void list_print(list *);

#endif //AYP3_LIST_H
