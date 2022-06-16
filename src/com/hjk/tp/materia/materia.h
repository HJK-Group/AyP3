#ifndef core_MATERIA_H
#define core_MATERIA_H

#include <stdlib.h>
#include <memory.h>

typedef struct list lista_correlativas; // TODO Juan
// ToDo Lista de Materias unívocas.
// Todo Método para añadir Materia a la Lista.

typedef struct materia {
    unsigned short id;
    char *nombre;
    lista_correlativas *pCorrelativas;
} materia;

materia *new_materia(unsigned short id, char *nombre);

void materia_add_correlativas(materia *pMateria, materia *pCorrelativa);

int materia_equals(materia *pMateria, materia *pOtherMateria);

void materia_print(materia *pMateria);

void materia_destroy(materia *pMateria);

#endif //core_MATERIA_H
