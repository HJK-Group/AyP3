#include <string.h>
#include <malloc.h>

char *new_string(char const *string) {
    char *new_string = malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(new_string, string);
    return new_string;
}

int *new_integer(int number) {
    int *new_integer = malloc(sizeof(int));
    *new_integer = number;
    return new_integer;
}
