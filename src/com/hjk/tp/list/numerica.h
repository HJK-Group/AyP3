#ifndef core_NUMERICA_H
#define core_NUMERICA_H

#include "list.h"

typedef struct list numeric_list;

numeric_list *new_empty_numeric_list();

numeric_list *new_numeric_list(int number);

void numeric_list_add(numeric_list *lista, void *data, size_t data_size);

int numeric_list_length(numeric_list *lista);

int numeric_list_get(numeric_list *lista, int index);

int numeric_list_remove(numeric_list *lista, int index);

void numeric_list_print(numeric_list *lista);

void numeric_list_destroy(numeric_list *lista);

#endif //core_NUMERICA_H
