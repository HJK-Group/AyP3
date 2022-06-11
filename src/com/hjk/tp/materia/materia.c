#include "materia.h"
#include "../estudiante/estudiante.c"

lista_correlativas *new_empty_lista_correlativas();

materia* new_materia(unsigned short id, char *nombre) {
    if (nombre == NULL) {
        return NULL;
    }

    materia *pMateria = (materia*) malloc(sizeof(materia));
    pMateria->id = id;
    pMateria->nombre = new_string(nombre);
    pMateria->pCorrelativas = new_empty_lista_correlativas();
    return pMateria;
}

lista_correlativas *new_empty_lista_correlativas() {
    return (lista_correlativas *) new_empty_list();
}

void materia_add_correlativas(materia *pMateria, materia *pCorrelativa) {
    list_add(pMateria->pCorrelativas, pCorrelativa);
}

int materia_equals(materia *pMateria, materia *pOtherMateria) {
    if (pMateria == NULL || pOtherMateria == NULL) {
        return 1;
    }

    int equals = pMateria->id == pOtherMateria->id;
    return equals && strcmp(pMateria->nombre, pOtherMateria->nombre) == 0;
}
