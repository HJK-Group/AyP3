#include "estudiante.h"
#include "registro.h"
#include "string.h"

int comparar_edad(void *primer_estudiante, void *segundo_estudiante);
int comparar_nombre(void *primer_estudiante, void *segundo_estudiante);

int buscar_nombre(void *data, void *other_data) {
    estudiante *alumno = (estudiante *) data;
    char *nombre = (char *) other_data;
    return strcmp(alumno->nombre, nombre);
}


listado *registro_buscar_por_edad(registro *listado_alumnos, short desde, short hasta) {

    if (listado_alumnos == NULL || listado_alumnos->listado_por_edad->generic_list->length == 0) {
        return NULL;
    }
    if (desde > hasta || desde < 0) {
        return NULL;
    }

    listado *listado_result = new_empty_ordered_list(&comparar_edad);
    ordered_list *listado_ordenado_edad = listado_alumnos->listado_por_edad;
    node *next_estudiante = listado_ordenado_edad->generic_list->head;


    estudiante *estudiante_actual = (estudiante *)next_estudiante->data;

    while (next_estudiante != NULL && estudiante_actual != NULL && estudiante_actual->edad <= hasta) {
        if (estudiante_actual->edad >= desde) {
            ordered_list_add(listado_result, estudiante_actual);
        }
            next_estudiante = next_estudiante->next;
            estudiante_actual = (estudiante *) next_estudiante->data;
    }
    return  listado_result;
}

estudiante *registro_buscar_por_nombre(registro *listado_alumnos, char *nombre) {
    if (listado_alumnos == NULL || nombre == NULL)
        return NULL;

    return (estudiante *) ordered_list_search_data(listado_alumnos->listado_por_nombre, &buscar_nombre,
                                                   (void *) nombre);
}

int comparar_nombre(void *primer_estudiante, void *segundo_estudiante) {
    return strcmp(((estudiante *) primer_estudiante)->nombre, ((estudiante *) segundo_estudiante)->nombre);
}

int comparar_edad(void *primer_estudiante, void *segundo_estudiante) {
    return (((estudiante *) primer_estudiante)->edad > ((estudiante *) segundo_estudiante)->edad);
}

registro *new_registro() {
    registro *listado_estudiantes = malloc(sizeof(registro));
    listado_estudiantes->listado_por_nombre = new_empty_ordered_list(&comparar_nombre);
    listado_estudiantes->listado_por_edad = new_empty_ordered_list(&comparar_edad);
    return listado_estudiantes;
}

void registro_agregar_alumno(registro *listado_alumnos, estudiante *alumno) {
    ordered_list_add((ordered_list *) listado_alumnos->listado_por_nombre, alumno);
    ordered_list_add((ordered_list *) listado_alumnos->listado_por_edad, alumno);
}

int registro_remover_estudiante(registro *listado_alumnos, estudiante *alumno) {
    return ordered_list_remove_data((ordered_list *) listado_alumnos->listado_por_nombre, alumno, sizeof(estudiante));
}

void listar_registro(registro *listado_alumnos) {
    ordered_list *listado_por_nombre = listado_alumnos->listado_por_nombre;
    ordered_list_print(listado_por_nombre, function_print_registro);
}

void function_print_registro(void *data) {
    estudiante *un_estudiante = data;

    printf("%s\n", un_estudiante->nombre);
    printf("%s\n", un_estudiante->apellido);
    printf("Edad: %d\n", un_estudiante->edad);
    printf("Legajo: %d\n", un_estudiante->legajo);
    //curada_print(un_estudiante->lista_materias);
}

void registro_destroy(registro *listado_alumnos) {
    ordered_list_destroy(listado_alumnos->listado_por_nombre);
    ordered_list_destroy(listado_alumnos->listado_por_edad);
    free(listado_alumnos);
}
