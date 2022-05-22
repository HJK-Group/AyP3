#ifndef core_NUMERICA_H
#define core_NUMERICA_H

#include "ordered.h"

typedef struct numeric_list {
    ordered_list *generic_ordered_list;
} numeric_list;

numeric_list *new_empty_numeric_list();

numeric_list *new_numeric_list(int number);

void numeric_list_add(numeric_list *lista, int number);

int numeric_list_length(numeric_list *lista);

int numeric_list_get(numeric_list *lista, int index);

int numeric_list_remove(numeric_list *lista, int index);

void numeric_list_print(numeric_list *lista);

void numeric_list_destroy(numeric_list *lista);

#endif //core_NUMERICA_H
