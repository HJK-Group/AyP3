#include "menu.h"
#include <stdio.h>

void menu_print_welcome() {
    printf("##############################################\n");
    printf("Bienvenida/o al Sistema de Gestion Estudiantil\n");
    menu_print_main_options();
    printf("______________________________________________\n");
}

void menu_print_main_options() {
    printf("Elija una de las siguientes opciones para continuar:\n\n");
    printf("[1] Realizar consultas al sistema\n");
    printf("[2] Agregar, borrar o modificar registros del sistema\n");
    printf("[3] Salir\n");
}

void menu_print_abm_options() {
    printf("############### ABM Registros ################\n");
    printf("Elija una de las siguientes opciones:\n\n");
    printf("[1] Agregar materia\n");
    printf("[2] Agregar alumno\n");
    printf("[3] Inscribir alumno en materia\n");
    printf("[4] Volver al menu principal\n");
    printf("______________________________________________\n");
}

void menu_print_query_options() {
    printf("############ Consultas del sistema ###########\n");
    printf("Elija una de las siguientes opciones:\n\n");
    printf("[1] Consultar materias\n");
    printf("[2] Consultar estudiantes\n");
    printf("[3] Consultar cursadas\n");
    printf("[4] Volver al menu principal\n");
    printf("______________________________________________\n");
}

//int consultar_estudiantes() {
//    printf("----- Consultar estudiantes -----\n");
//
//    printf("Elija una de las siguientes opciones:\n\n");
//    printf("[1] Consultar estudiantes por nombre\n");
//    printf("[2] Consultar estudiantes por apellido\n");
//    printf("[3] Consultar estudiantes por DNI\n");
//}

//printf("[4] Estudiante rendir Materia\n");
//printf("[5] Imprimir Registro\n");
//printf("[6] Salir\n");
