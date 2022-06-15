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
    node *item = listado_alumnos->listado_por_edad->generic_list->head;
    while (item != NULL && item->data != NULL) {
        estudiante *alumno = (estudiante *) item->data;
        if (alumno->edad >= desde && alumno->edad <= hasta) {
            ordered_list_add(listado_result, alumno);
        }
        item = item->next;
    }

    return listado_result;
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

void listar_registro(registro *listado_alumnos, int number_records, registro_order_by orderBy)
{
    ordered_list *listado_a_imprimir = NULL;
    switch (orderBy) {
        case Order_By_Edad:
            listado_a_imprimir = listado_alumnos->listado_por_nombre;
            break;
        case Order_By_Nombre:
            listado_a_imprimir = listado_alumnos->listado_por_edad;
            break;
        default:
            printf("No existe listado ordenado por ese tipo para imprimir por pantalla.");
            break;
    }

    if (listado_a_imprimir != NULL)
        ordered_list_print(listado_a_imprimir, function_print_registro, number_records);
}

void function_print_registro(void *data) {
    estudiante *un_estudiante = data;
    printf("############################################################\n");
    printf("Nombre: %s\n", un_estudiante->nombre);
    printf("Apellido: %s\n", un_estudiante->apellido);
    printf("Edad: %d\n", un_estudiante->edad);
    printf("Legajo: %d\n", un_estudiante->legajo);
    printf("____________________________________________________________\n");
//    curada_print(un_estudiante->lista_materias);
}

void registro_destroy(registro *listado_alumnos) {
    ordered_list_destroy(listado_alumnos->listado_por_nombre);
    ordered_list_destroy(listado_alumnos->listado_por_edad);
    free(listado_alumnos);
}
