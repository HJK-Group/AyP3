#include <stdlib.h>
#include "numerica.h"

void print_function(void *data);

int number_comparator(void *number, void *other_number);

numeric_list *new_empty_numeric_list() {
    numeric_list *lista = malloc(sizeof(numeric_list));
    lista->generic_ordered_list = new_empty_ordered_list(number_comparator);
    return lista;
}

numeric_list *new_numeric_list(int number) {
    numeric_list *lista = new_empty_numeric_list();
    numeric_list_add(lista, number);
    return lista;
}

int number_comparator(void *number, void *other_number) {
    if (*((int *)number) < *((int *)other_number)) {
        return -1;
    }

    if (*((int *)number) > *((int *)other_number)) {
        return 1;
    }

    return 0;
}

void numeric_list_add(numeric_list *lista, int number) {
    ordered_list_add(lista->generic_ordered_list, &number, sizeof(int));
}

int numeric_list_length(numeric_list *lista) {
    return ordered_list_length(lista->generic_ordered_list);
}

int numeric_list_get(numeric_list *lista, int index) {
    return *((int *) ordered_list_get_value(lista->generic_ordered_list, index));
}

int numeric_list_remove(numeric_list *lista, int index) {
    return ordered_list_remove(lista->generic_ordered_list, index);
}

void print_number(void *data) {
    printf(" %d,", *((int *) data));
}

void numeric_list_print(numeric_list *lista) {
    printf("%s", "{");
    ordered_list_print(lista->generic_ordered_list, &print_number);
    printf("\b %s", "}");
}

void numeric_list_destroy(numeric_list *lista) {
    ordered_list_destroy(lista->generic_ordered_list);
    free(lista);
}
