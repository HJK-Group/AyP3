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
    return materia_equals((materia *) pMateria, ((curso *) pCurso)->pMateria);
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

void print_materia(void *data) {

}

void curada_print(cursada *lista_materias) {
    list_print((list *) lista_materias, &print_materia);
}

void cursada_destroy(cursada *lista_materias) {
    list_destroy((list *) lista_materias);
}
