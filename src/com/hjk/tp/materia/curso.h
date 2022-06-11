#ifndef core_CURSO_H
#define core_CURSO_H

#include "materia.h"

typedef struct curso {
    materia *pMateria;
    unsigned char calificacion;
} curso;

curso *new_curso(materia *pMateria, unsigned char calificacion);

void curso_destroy(curso *pCurso); // ToDo

#endif //core_CURSO_H
