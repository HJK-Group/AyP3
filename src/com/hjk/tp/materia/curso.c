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

void curso_destroy(curso *pCurso) {
    if (pCurso == NULL) {
        return;
    }

    materia_destroy(pCurso->pMateria);
    free(pCurso);
}
