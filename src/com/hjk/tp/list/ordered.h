#ifndef core_ORDERED_H
#define core_ORDERED_H

#include "list.h"

typedef struct ordered_list {
    int (*comparador)(void *data, void *other_data);
    list *generic_list;
} ordered_list;

ordered_list *new_empty_ordered_list(int (*comparator)(void *data, void *other_data));

ordered_list *new_ordered_list(void *data, int (*comparator)(void *data, void *other_data));

void ordered_list_add(ordered_list *lista, void *data);

int ordered_list_length(ordered_list *lista);

void *ordered_list_get_value(ordered_list *lista, int index);

void *ordered_list_search_data(ordered_list *lista, int (*search_function)(void *data, void *other_data), void *other_data);

int ordered_list_remove(ordered_list *lista, int index);

int ordered_list_remove_data(ordered_list *lista, void *data, size_t data_size);

void ordered_list_print(ordered_list *lista, void (*print_function)(void *), int number_records);

void ordered_list_destroy(ordered_list *lista);

#endif //core_ORDERED_H
