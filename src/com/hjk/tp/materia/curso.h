#ifndef core_CURSO_H
#define core_CURSO_H

#include <string.h>
#include "materia.h"

typedef struct curso {
    materia *pMateria;
    unsigned char calificacion;
} curso;

curso *new_curso(materia *pMateria, unsigned char calificacion);

void curso_destroy(curso *pCurso);

#endif //core_CURSO_H
