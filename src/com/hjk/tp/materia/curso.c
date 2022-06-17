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

//int curso_material_equals(curso *pCurso, materia *pMateria) {
//    if (pCurso == NULL || pMateria == NULL) {
//        return 0;
//    }
//
//    if (pCurso->pMateria == pMateria) {
//        return 1;
//    }
//
//    int sameId = pCurso->pMateria->id == pMateria->id;
//    int sameName = strcmp(pCurso->pMateria->nombre, pMateria->nombre) == 0;
//    return sameId && sameName;
//}

void curso_destroy(curso *pCurso) {
    if (pCurso == NULL) {
        return;
    }

    materia_destroy(pCurso->pMateria);
    free(pCurso);
}
