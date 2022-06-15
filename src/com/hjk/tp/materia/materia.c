#include "materia.h"
#include "../estudiante/estudiante.c"

lista_correlativas *new_empty_lista_correlativas();

materia *new_materia(unsigned short id, char *nombre) {
    if (nombre == NULL) {
        return NULL;
    }

    materia *pMateria = (materia *) malloc(sizeof(materia));
    pMateria->id = id;
    pMateria->nombre = new_string(nombre);
    pMateria->pCorrelativas = new_empty_lista_correlativas();
    return pMateria;
}

lista_correlativas *new_empty_lista_correlativas() {
    return (lista_correlativas *) new_empty_list();
}

void materia_add_correlativas(materia *pMateria, materia *pCorrelativa) {
    // TODO verificar que no se agregue una materia ya agregada
    list_add(pMateria->pCorrelativas, pCorrelativa);
}

int materia_equals(materia *pMateria, materia *pOtherMateria) {
    if (pMateria == NULL || pOtherMateria == NULL) {
        return 0;
    }

    if (pMateria == pOtherMateria) {
        return 1;
    }

    int sameId = pMateria->id == pOtherMateria->id;
    int sameName = strcmp(pMateria->nombre, pOtherMateria->nombre) == 0;
    return sameId && sameName;
}

void materia_destroy(materia *pMateria) {
    if (pMateria == NULL) {
        return;
    }

    free(pMateria->nombre);
    list_destroy(pMateria->pCorrelativas);
    free(pMateria);
}
