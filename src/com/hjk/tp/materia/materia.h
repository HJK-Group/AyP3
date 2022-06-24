#ifndef core_MATERIA_H
#define core_MATERIA_H

#include <stdlib.h>
#include <memory.h>

typedef struct list lista_correlativas;

typedef struct materia {
    unsigned short id;
    char *nombre;
    lista_correlativas *pCorrelativas;
} materia;

materia *new_materia(unsigned short id, char *nombre);

void materia_add_correlativas(materia *pMateria, materia *pCorrelativa);

int materia_equals(materia *pMateria, materia *pOtherMateria);

int wrapper_materia_equals(void *pMateria, void *pCorrelativa);

void materia_print(materia *pMateria);

void materia_destroy(materia *pMateria);

#endif //core_MATERIA_H
