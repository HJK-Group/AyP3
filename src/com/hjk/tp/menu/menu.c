#include "menu.h"
#include <stdio.h>

void menu_print_welcome() {
    printf("Bienvenida/o al Sistema de Gestion Estudiantil\n");
    menu_print_main_options();
}

void menu_print_main_options() {
    printf("Elija una de las siguientes opciones para continuar:\n\n");
    printf("[1] Crear nueva Materia\n");
    printf("[2] Crear nuevo Estudiante\n");
    printf("[3] Anotar Estudiante a Materia\n");
    printf("[4] Estudiante rendir Materia\n");
    printf("[5] Imprimir Registro\n");
    printf("[6] Salir\n");
}

void menu_print_crear_materia_options() {

}
