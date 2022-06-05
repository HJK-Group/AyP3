#ifndef core_CURSO_H
#define core_CURSO_H

#include "materia.h"

typedef struct curso {
    materia *pMateria;
    unsigned char calificacion;
} curso;

curso *new_curso(materia *pMateria, unsigned char calificacion);

// TODO funciones para liberar curso, etc.

#endif //core_CURSO_H
