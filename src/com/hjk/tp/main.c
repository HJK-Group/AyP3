#include <stdlib.h>
#include <stdio.h>
#include "menu/menu.h"
#include "com/hjk/tp/estudiante/registro.h"

int get_menu_option();

void handle_crear_materia(list *pLista_materias);

void handle_crear_estudiante(registro *pRegistro);

void handle_anotar_estudiante(registro *pRegistro, list *pLista_materias);

void handle_estudiante_rendir(registro *pRegistro, list *pLista_materias);

void handle_listar_registro(registro *pRegistro);

int main() {

    registro *pRegistro = new_registro();
    list *pLista_materias = new_empty_list();

    int running = 1;

    while (running) {
        menu_print_welcome();
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
                handle_estudiante_rendir(pRegistro, pLista_materias);
                break;
            case 5:
                handle_listar_registro(pRegistro);
                break;
            case 6:
                running = 0;
                break;
            default:
                printf("Ninguna opcion configurada para ese valor.");
                break;
        }
    }

    return 0;
}

int get_menu_option() {
    printf("Tu opcion: ");
    char *option_choose = malloc(sizeof(char));
    scanf("%s", option_choose);
    return strtol(option_choose, NULL, 10);
}

int comparar_materia(void *item_lista, void *dato) {
    return materia_equals((materia *) item_lista, (materia *) dato);
}

void handle_crear_materia(list *pLista_materias) {
    printf("Indique el nombre de la materia: ");
    char codigo_materia[10];
    char nombre_materia[25];

    scanf("%s", &nombre_materia);

    printf("Ahora indique un codigo unico para identificar la materia: ");
    scanf("%s", &codigo_materia);

    materia *nueva_materia = new_materia(strtol(codigo_materia, NULL, 10), nombre_materia);
    if (!list_contains(pLista_materias, &comparar_materia, nueva_materia)) {
        list_add(pLista_materias, nueva_materia);
    }
}

void handle_crear_estudiante(registro *pRegistro) {
    // TODO: Crear un estudiante
}

void handle_anotar_estudiante(registro *pRegistro, list *pLista_materias) {
    // TODO: Anotar un estudiante a una materia
}

void handle_estudiante_rendir(registro *pRegistro, list *pLista_materias) {
    // TODO: Rendir una materia a un estudiante
}

void handle_listar_registro(registro *pRegistro) {
    // TODO: Listar todos los estudiantes
}
