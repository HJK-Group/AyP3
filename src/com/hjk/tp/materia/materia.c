#include "materia.h"
#include "../estudiante/estudiante.c"

lista_correlativas *new_empty_lista_correlativas();

materia* new_materia(unsigned short id, char *nombre) {
    if (nombre == NULL) {
        return NULL;
    }

    materia *pMateria = (materia*) malloc(sizeof(materia));
    pMateria->id = id;
    pMateria->nombre = (char *) malloc(sizeof(char) * (strlen(nombre) + 1));
    strcpy(pMateria->nombre, nombre);
    pMateria->pCorrelativas = new_empty_lista_correlativas();
    return pMateria;
}

lista_correlativas *new_empty_lista_correlativas() {
    return (lista_correlativas *) new_empty_list();
}

void materia_add_correlativas(materia *pMateria, materia *pCorrelativa) {
    list_add(pMateria->pCorrelativas, pCorrelativa);
}
