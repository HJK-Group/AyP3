#include "cursada.h"
#include "curso.h"

cursada *new_empty_cursada() {
    return new_empty_list();
}

cursada *new_cursada(materia *pMateria) {
    return new_list(new_curso(pMateria, 0));
}

void cursada_add(cursada *lista_materias, materia *pMateria) {
    list_add(lista_materias, new_curso(pMateria, 0));
}

int cursada_length(cursada *lista_materias) {
    return list_length(lista_materias);
}

int curso_materia_equals(void *pCurso, void *pMateria) {
    return materia_equals(((curso *) pCurso)->pMateria, (materia *) pMateria);
}

curso *cursada_get_curso(cursada *lista_materias, materia *pMateria) {
    return (curso *) list_search_data(lista_materias, &curso_materia_equals, pMateria);
}

int cursada_contains(cursada *lista_materias, materia *pMateria) {
    return list_contains(lista_materias, &curso_materia_equals, pMateria);
}

unsigned char cursada_get_calificacion(cursada *lista_materias, materia *pMateria) {
    curso const *pCurso = (curso *) list_get_data(lista_materias, pMateria, sizeof(materia));
    if (pCurso == NULL)
        return 0;
    return pCurso->calificacion;
}

int cursada_remove(cursada *lista_materias, int index) {
    return list_remove(lista_materias, index);
}

void print_materia(void *pCurso) {
    if (pCurso == NULL) {
        return;
    }

    materia_print(((curso *) pCurso)->pMateria);
}

void cursada_print(cursada *lista_materias) {
    list_print(lista_materias, &print_materia, 0);
}

void cursada_destroy(cursada *lista_materias) {

    node *pNode = lista_materias->head;
    for (int i = 0; i < lista_materias->length; i++) {
        curso_destroy((curso *) pNode->data);
        pNode = pNode->next;
    }

    list_destroy(lista_materias);
}
