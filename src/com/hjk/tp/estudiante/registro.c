#include "estudiante.h"
#include "registro.h"
#include "string.h"

estudiante *buscar_estudiante_por_nombre(char *nombre) {

}

listado *buscar_estudiantes_por_edad(registro *listado_alumnos, short desde, short hasta) {

}

int comparar_nombre(void *estudiante1, void *estudiante2) { // TODO Hernan
    estudiante* primer_estudiante = (estudiante*) estudiante1;
    estudiante* segundo_estudiante = (estudiante*) estudiante2;

    return strcmp(primer_estudiante->nombre, segundo_estudiante->nombre);
}

int comparar_edad(void *estudiante1, void *estudiante2) { // TODO Hernan
    estudiante* primer_estudiante = (estudiante*) estudiante1;
    estudiante* segundo_estudiante = (estudiante*) estudiante2;

    return (primer_estudiante->edad > segundo_estudiante->edad);
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

estudiante *registro_buscar_por_nombre(registro *listado_alumnos, char *nombre) {
    return (estudiante *) ordered_list_get_data((ordered_list *) listado_alumnos, nombre, sizeof(char) * (strlen(nombre) + 1));
}

listado *registro_buscar_por_edad(registro *listado_alumnos, short desde, short hasta) {
    if (listado_alumnos == NULL)
        return NULL;

    return listado_alumnos->listado_por_edad;
} //TODO TERMINAR!

int registro_remover_estudiante(registro *listado_alumnos, estudiante *alumno) {
    return ordered_list_remove_data((ordered_list*) listado_alumnos->listado_por_nombre, alumno, sizeof(estudiante));
}

void listar_registro(registro *listado_alumnos) {
    ordered_list* listado_por_nombre = listado_alumnos->listado_por_nombre;
    ordered_list_print(listado_por_nombre, function_print_registro);
}

void function_print_registro(void* data) {
    estudiante* un_estudiante = data;

    printf("%s\n", un_estudiante->nombre);
    printf("%s\n", un_estudiante->apellido);
    printf("Edad: %d\n", un_estudiante->edad);
    printf("Legajo: %d\n", un_estudiante->legajo);
    //curada_print(un_estudiante->lista_materias);
}

void borrar_registro(registro *listado_alumnos) {

}
