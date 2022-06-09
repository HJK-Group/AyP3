#include "estudiante.h"
#include "registro.h"

estudiante *buscar_estudiante_por_nombre(char *nombre) {

}

listado *buscar_estudiantes_por_edad(registro *listado_alumnos, short desde, short hasta) {

}

int comparar_nombre(void *estudiante1, void *estudiante2) { // TODO Hernan

}

int comparar_edad(void *estudiante1, void *estudiante2) { // TODO Hernan

}

registro *new_registro() {
    registro *listado_estudiantes = malloc(sizeof(registro));
    listado_estudiantes->listado_por_nombre = new_empty_ordered_list(&comparar_nombre);
    listado_estudiantes->listado_por_edad = new_empty_ordered_list(&comparar_edad);
    return listado_estudiantes;
}

void registro_agregar_alumno(registro *listado_alumnos, estudiante *alumno) {
    ordered_list_add((ordered_list *) listado_alumnos->listado_por_nombre, alumno, sizeof(estudiante));
    ordered_list_add((ordered_list *) listado_alumnos->listado_por_edad, alumno, sizeof(estudiante));
}

estudiante *registro_buscar_por_nombre(registro *listado_alumnos, char *nombre) {
    return ordered_list_get_by_data((ordered_list *) listado_alumnos, nombre, sizeof(nombre));
}

listado *registro_buscar_por_edad(registro *listado_alumnos, short desde, short hasta) {
    if (listado_alumnos == NULL)
        return NULL;

    if (listado_alumnos->listado_por_edad->generic_list->length == 0)
        return listado_alumnos->
} //TODO TERMINAR!

int registro_remover_estudiante(registro *listado_alumnos, estudiante *alumno) {
    ordered_list_remove((ordered_list *) listado_alumnos->listado_por_nombre, index);
}

void listar_registro(registro *listado_alumnos) {

}

void borrar_registro(registro *listado_alumnos) {

}
