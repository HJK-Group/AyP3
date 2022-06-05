#include "curso.h"

curso *new_curso(materia *pMateria, unsigned char calificacion) {
    curso *pCurso = malloc(sizeof(curso));
    if (pCurso == NULL) {
        return NULL;
    }

    pCurso->pMateria = pMateria;
    pCurso->calificacion = calificacion;
    return pCurso;
}
