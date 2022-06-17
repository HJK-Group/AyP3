#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu/menu.h"
#include "com/hjk/tp/estudiante/registro.h"

int get_menu_option();

void handle_crear_materia(list *pLista_materias);

void handle_crear_estudiante(registro *pRegistro);

void handle_anotar_estudiante(registro *pRegistro, list *pLista_materias);

void handle_estudiante_rendir(registro *pRegistro, list *pLista_materias);

void handle_listar_registro(registro *pRegistro);

void handle_consultar_materias(list *pLista_materias);

void handle_consultar_estudiantes(registro *pRegistro);

void handle_consultar_cursada(registro *pRegistro);

void realizar_consultas(registro *pRegistro, list *pLista_materias);

void abm_registros(registro *pRegistro, list *pLista_materias);

char *solicitar_dato(int longitud);

int solicitar_confirmacion();

estudiante *buscar_estudiante(registro *coleccion);

materia *buscar_materia(list *pLista_materias);

estudiante *solicitar_estudiante(registro *pRegistro);

materia *solicitar_materia(list *pLista_materias);

// Autoincrementales
long siguiente_id_materia = 1;
long siguiente_legajo = 1;

int main() {

    registro *pRegistro = new_registro();
    list *pLista_materias = new_empty_list();

    menu_print_welcome();
    int running = 1;

    while (running) {
        switch (get_menu_option()) {
            case 1:
                realizar_consultas(pRegistro, pLista_materias);
                break;
            case 2:
                abm_registros(pRegistro, pLista_materias);
                break;
            case 3:
                running = 0;
                break;
            default:
                printf("Ninguna opcion configurada para ese valor.\n\n");
                break;
        }
        menu_print_main_options_boxed();
    }
    menu_print_end();
    return 0;
}

int get_menu_option() {
    char *option = malloc(sizeof(char));
    scanf("%s", option);
    int chosen_option = (int) strtol(option, NULL, 10);
    free(option);
    return chosen_option;
}

char *solicitar_dato(int longitud) {
    char *dato = malloc(longitud);
    scanf("%s", dato);
    char *dato_reducido = malloc(strlen(dato));
    strcpy(dato_reducido, dato);
    return dato_reducido;
}

void realizar_consultas(registro *pRegistro, list *pLista_materias) {
    int running = 1;
    while (running) {
        menu_print_query_options();
        switch (get_menu_option()) {
            case 1:
                handle_consultar_materias(pLista_materias);
                break;
            case 2:
                handle_consultar_estudiantes(pRegistro);
                break;
            case 3:
                handle_consultar_cursada(pRegistro);
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("Ninguna opcion configurada para ese valor.\n\n");
        }
    }
}

void abm_registros(registro *pRegistro, list *pLista_materias) {
    int running = 1;
    while (running) {
        menu_print_abm_options();
        switch (get_menu_option()) {
            case 1:
                handle_crear_materia(pLista_materias);
                break;
            case 2:
                handle_crear_estudiante(pRegistro);
                break;
            case 3:
                handle_anotar_estudiante(pRegistro, pLista_materias);
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("Ninguna opcion configurada para ese valor.\n\n");
        }
    }
}

int comparar_materia(void *item_lista, void *dato) {
    return materia_equals((materia *) item_lista, (materia *) dato);
}

void handle_crear_materia(list *pLista_materias) {
    printf("Indique el nombre de la materia: ");
    char *nombre_materia = solicitar_dato(50);

    materia *nueva_materia = new_materia(siguiente_id_materia, nombre_materia);
    if (!list_contains(pLista_materias, &comparar_materia, nueva_materia)) {
        list_add(pLista_materias, nueva_materia);
        printf("Materia agregada con exito!\n");
        siguiente_id_materia++;
        return;
    }

    printf("La Materia ya existia\n");
}

void handle_crear_estudiante(registro *pRegistro) {
    unsigned long legajo = siguiente_id_materia;
    char *nombre;
    char *apellido;
    unsigned char edad;

    printf("Indique el nombre del estudiante: ");
    scanf("%s", &nombre);

    printf("Indique el apellido del estudiante: ");
    scanf("%s", &apellido);

    printf("Indique la edad del estudiante: ");
    scanf("%s", &edad);

    registro_agregar_alumno(pRegistro, new_estudiante(legajo, nombre, apellido, edad));
    siguiente_legajo++;
}


void handle_anotar_estudiante(registro *pRegistro, list *pLista_materias) {
    estudiante *pEstudiante = buscar_estudiante(pRegistro);
    materia *pMateria = buscar_materia(pLista_materias);
    if (pEstudiante != NULL && pMateria != NULL) {
        anotarse_materia(pEstudiante, pMateria);
        printf("Anotacion realizada con exito!\n");
    }
}


estudiante *buscar_estudiante(registro *coleccion) {
    int salir = 0;
    estudiante *pEstudiante = solicitar_estudiante(coleccion);
    while (pEstudiante == NULL || salir == 1) {
        printf("No se encontro el estudiante\n");
        printf("Desea intentar de nuevo? (s/n): ");
        salir = !solicitar_confirmacion();
        if (salir == 0) {
            pEstudiante = solicitar_estudiante(coleccion);
        }
    }
    return pEstudiante;
}


materia *buscar_materia(list *pLista_materias) {
    int salir = 0;
    materia *pMateria = solicitar_materia(pLista_materias);
    while (pMateria == NULL || salir == 1) {
        printf("No se encontro la materia\n");
        printf("Desea intentar de nuevo? (s/n): ");
        salir = !solicitar_confirmacion();
        if (salir == 0) {
            pMateria = solicitar_materia(pLista_materias);
        }
    }
    return pMateria;
}


int solicitar_confirmacion() {
    char *option = malloc(sizeof(char));
    scanf("%s", option);
    int respuesta = (strcmp(option, "s") == 0);
    free(option);
    return respuesta;
}

estudiante *solicitar_estudiante(registro *pRegistro) {
    printf("Indique el nombre del estudiante: ");
    char *nombre_estudiante = solicitar_dato(100);
    return registro_buscar_por_nombre(pRegistro, nombre_estudiante);
}

int buscar_materia_por_nombre(void *data, void *other_data) {
    materia *materia = data;
    char *nombre = (char *) other_data;

    return strcmp(materia->nombre, nombre) == 0;
}

materia *solicitar_materia(list *pLista_materias) {
    printf("Indique el nombre de la materia: ");
    char *nombre_materia = solicitar_dato(100);
    return list_search_data(pLista_materias, &buscar_materia_por_nombre, nombre_materia);
}

void handle_estudiante_rendir(registro *pRegistro, list *pLista_materias) {
    // TODO: Rendir una materia a un estudiante
}

void handle_listar_registro(registro *pRegistro) {
    // TODO: Listar todos los estudiantes
}

void handle_consultar_materias(list *pLista_materias) {
    materia *materia = solicitar_materia(pLista_materias);
    if (materia == NULL) {
        printf("Materia no encontrada\n");
        return;
    }

    materia_print(materia);
}

void handle_consultar_estudiantes(registro *pRegistro) {
    estudiante *pEstudiante = solicitar_estudiante(pRegistro);
    if (pEstudiante == NULL) {
        printf("Estudiante no encontrado\n");
        return;
    }

    estudiante_print(pEstudiante);
}

void handle_consultar_cursada(registro *pRegistro) {
    // TODO: Consultar las cursadas de un estudiante
}
