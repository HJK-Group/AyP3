#include "cursada.h"
#include "curso.h"

cursada *new_empty_cursada() {
    return (cursada *) new_empty_list();
}

cursada *new_cursada(materia *pMateria) {
    return (cursada *) new_list(new_curso(pMateria, 0));
}

void cursada_add(cursada *lista_materias, materia *pMateria) {
    list_add((list *) lista_materias, new_curso(pMateria, 0));
}

int cursada_length(cursada *lista_materias) {
    return list_length((list *) lista_materias);
}

int buscar_curso(void *pCurso, void *pMateria) {
    return materia_equals(((curso *) pCurso)->pMateria, (materia *) pMateria);
}

curso *cursada_get_curso(cursada *lista_materias, materia *pMateria) {
    return (curso *) list_search_data((list *) lista_materias, &buscar_curso, pMateria);
}

int cursada_contains(cursada *lista_materias, materia *pMateria) {
    return list_contains((list *) lista_materias, &buscar_curso, pMateria);
}

unsigned char cursada_get_calificacion(cursada *lista_materias, materia *pMateria) {
    curso *pCurso = (curso *) list_get_data(lista_materias, pMateria, sizeof(materia));
    if (pCurso == NULL)
        return 0;
    return pCurso->calificacion;
}

int cursada_remove(cursada *lista_materias, int index) {
    return list_remove((list *) lista_materias, index);
}

void print_materia(void *pCurso) {
    if (pCurso == NULL) {
        return;
    }

    materia_print(((curso *) pCurso)->pMateria);
}

void cursada_print(cursada *lista_materias) {
    list_print((list *) lista_materias, &print_materia, 0);
}

void cursada_destroy(cursada *lista_materias) {

    node *pNode = lista_materias->head;
    for (int i = 0; i < lista_materias->length; i++) {
        curso_destroy((curso *) pNode->data);
        pNode = pNode->next;
    }

    list_destroy((list *) lista_materias);
}
