#include <string.h>
#include "estudiante.h"
#include "com/hjk/tp/config.c"
#include "com/hjk/tp/materia/cursada.h"
#include "com/hjk/tp/materia/curso.h"
#include "com/hjk/tp/utils/utils.h"

estudiante *new_estudiante(unsigned long legajo, const char *nombre, const char *apellido, unsigned char edad) {
    if (edad < EDAD_MINIMA || edad > EDAD_MAXIMA) {
        return NULL;
    }

    estudiante *entidad = malloc(sizeof(estudiante));
    entidad->legajo = legajo;
    entidad->nombre = new_string(nombre);
    entidad->apellido = new_string(apellido);
    entidad->edad = edad;
    entidad->lista_materias = new_empty_cursada();

    if (entidad->nombre == NULL || entidad->apellido == NULL) {
        return NULL;
    }

    return entidad;
}

void estudiante_print(estudiante *alumno) {
    if (alumno == NULL) {
        return;
    }

    printf("Nombre: %s", alumno->nombre);
    printf("Apellido: %s", alumno->apellido);
    printf("Edad: %d\n", alumno->edad);
    printf("Legajo: %d\n\n", alumno->legajo);
}

void anotarse_materia(estudiante *pEstudiante, materia *pMateria) {
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
    while (iterador->next != NULL) {
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

int rendir_materia(estudiante *pEstudiante, materia *pMateria, unsigned char calificacion) {
    curso *actual = (curso *) list_search_data(pEstudiante->lista_materias, curso_materia_equals, pMateria);
    if (actual == NULL) {
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

double calcular_promedio(cursada *lista_materias) {
    double total = 0;
    double cantidad_materias_rendidas = 0;
    curso const *pCurso = NULL;
    node *iterador = lista_materias->head;

    if (lista_materias->length <= 0) {
        return -1;
    }

    while (iterador->next != NULL) {
        pCurso = (curso *) iterador->data;
        if (pCurso != NULL && pCurso->calificacion != 0) {
            total += (double) pCurso->calificacion;
            cantidad_materias_rendidas++;
        }
        iterador = iterador->next;
    }

    return total / cantidad_materias_rendidas;
}

double calcular_promedio_estudiante(estudiante *pEstudiante) {
    return calcular_promedio(pEstudiante->lista_materias);
}

/**
 * -1: Si no curso la materia
 *  0: Si no aprobo la materia
 *  1: Si aprobo la materia
 * @return int
 */
int aprobo_materia(estudiante *pEstudiante, materia *pMateria) {
    curso const *pCurso = (curso *) list_search_data(pEstudiante->lista_materias, curso_materia_equals, pMateria);
    if (pCurso == NULL) {
        return -1;
    }

    return pCurso->calificacion >= NOTA_APROBADA;
}
