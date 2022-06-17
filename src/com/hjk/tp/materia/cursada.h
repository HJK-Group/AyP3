#ifndef core_LISTADO_H
#define core_LISTADO_H

#include "../list/list.h"
#include "com/hjk/tp/materia/materia.h"
#include "curso.h"

typedef struct list cursada;

cursada *new_empty_cursada();

cursada *new_cursada(materia *pMateria);

void cursada_add(cursada *lista_materias, materia *pMateria);

int cantidad_de_materias(cursada *lista_materias);

int cursada_length(cursada *lista_materias);

int buscar_curso(void *pCurso, void *pMateria);

int cursada_contains(cursada *lista_materias, materia *pMateria);

curso *cursada_get_curso(cursada *lista_materias, materia *pMateria);

unsigned char cursada_get_calificacion(cursada *lista_materias, materia *pMateria);

int cursada_remove(cursada *lista_materias, int index);

void cursada_print(cursada *lista_materias);

void cursada_destroy(cursada *lista_materias);

#endif //core_LISTADO_H
