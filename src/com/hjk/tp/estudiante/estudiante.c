#include <string.h>
#include "estudiante.h"
#include "com/hjk/tp/materia/cursada.h"
#include "com/hjk/tp/materia/curso.h"
#include "com/hjk/tp/utils/utils.h"

int add_edad(estudiante *dest, short edad);

estudiante *new_estudiante(unsigned long legajo, char *nombre, char *apellido, unsigned char edad) {
    estudiante *entidad = malloc(sizeof(estudiante));
    entidad->legajo = legajo;
    entidad->nombre = new_string(nombre);
    entidad->apellido = new_string(apellido);
    add_edad(entidad, edad);
    entidad->lista_materias = new_empty_cursada();
    return entidad;
}

int add_edad(estudiante *dest, short edad) {
    if (edad < EDAD_MINIMA || edad > EDAD_MAXIMA){
        return -1;
    }

    dest->edad = edad;
    return 0;
}

void estudiante_print(estudiante *alumno) {
    if (alumno == NULL) {
        return;
    }

    printf("##############################################\n");
    printf("Nombre: %s\n", alumno->nombre);
    printf("Apellido: %s\n", alumno->apellido);
    printf("Edad: %d\n", alumno->edad);
    printf("Legajo: %d\n", alumno->legajo);
    printf("______________________________________________\n");
}

void anotarse_materia(estudiante *pEstudiante, materia *pMateria ) {
    if (pEstudiante == NULL || pEstudiante->lista_materias == NULL || pMateria == NULL) {
        return;
    }

    if (cursada_contains(pEstudiante->lista_materias, pMateria)) {
        return;
    }

    if (pMateria->pCorrelativas->length == 0) {
        cursada_add(pEstudiante->lista_materias, pMateria);
        return;
    }

    node *iterador = pMateria->pCorrelativas->head;
    int puede_anotarse = 1;
    while(iterador->next != NULL) {
        puede_anotarse = cursada_contains(pEstudiante->lista_materias, iterador->data);
        if (!puede_anotarse) {
            break;
        }
        iterador = iterador->next;
    }

    if (iterador->data != NULL && !puede_anotarse) {
        return;
    }

    cursada_add(pEstudiante->lista_materias, pMateria);
}

int rendir_materia(estudiante *pEstudiante, materia *pMateria, char calificacion) {
    curso *actual = (curso *) list_search_data(pEstudiante->lista_materias, buscar_curso, pMateria);
    if (actual == NULL) {
        printf(">>> La materia %s no esta registrada en este estudiante\n\n", pMateria->nombre);
        return 0;
    }

    actual->calificacion = calificacion;

    return 1;
}

void estudiante_destroy(estudiante *pEstudiante) {
    if (pEstudiante == NULL) {
        return;
    }

    free(pEstudiante->nombre);
    free(pEstudiante->apellido);
    cursada_destroy(pEstudiante->lista_materias);
    free(pEstudiante);
}
