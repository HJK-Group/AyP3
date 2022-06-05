#ifndef core_LISTADO_H
#define core_LISTADO_H

#include "../list/list.h"
#include "com/hjk/tp/materia/materia.h"

typedef struct list cursada;

cursada *new_empty_cursada();

cursada *new_cursada(materia *pMateria);

void cursada_add(cursada *lista_materias, materia *pMateria);

int cantidad_de_materias(cursada *lista_materias);

unsigned char cursada_get_calificacion(cursada *lista_materias, materia *pMateria);

int cursada_remove(cursada *lista_materias, int index);

void curada_print(cursada *lista_materias);

void *buscar_curso(void *item, void *dato);

void cursada_destroy(cursada *lista_materias);

// TODO revisar implementacion

#endif //core_LISTADO_H
