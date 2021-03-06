#include "menu.h"
#include <stdio.h>

void menu_print_welcome() {
    printf("##############################################\n");
    printf("Bienvenida/o al Sistema de Gestion Estudiantil\n");
    menu_print_main_options();
    printf("______________________________________________\n");
}

void menu_print_main_options_boxed() {
    printf("############### Menu principal ###############\n");
    menu_print_main_options();
    printf("______________________________________________\n");
}

void menu_print_end(){
    printf("\n\n");
    printf("##############################################\n");
    printf("Gracias por utilizar el Sistema de Gestion Estudiantil\n");
    printf("______________________________________________\n");
}

void menu_print_main_options() {

    printf("Elija una de las siguientes opciones para continuar:\n\n");
    printf("[1] Realizar consultas al sistema\n");
    printf("[2] Agregar, borrar o modificar registros del sistema\n");
    printf("[0] Salir\n");
}

void menu_print_abm_options() {
    printf("############### ABM Registros ################\n");
    printf("Elija una de las siguientes opciones:\n\n");
    printf("[1] Agregar materia\n");
    printf("[2] Agregar estudiante\n");
    printf("[3] Inscribir estudiante en materia\n");
    printf("[4] Registrar nota\n");
    printf("[5] Crear correlatividad\n");
    printf("[6] Eliminar materia\n");
    printf("[7] Eliminar estudiante\n");
    printf("[0] Volver al menu principal\n");
    printf("______________________________________________\n");
}

void menu_print_query_options() {
    printf("############ Consultas del sistema ###########\n");
    printf("Elija una de las siguientes opciones:\n\n");
    printf("[1] Consultar materias\n");
    printf("[2] Consultar estudiantes\n");
    printf("[3] Consultar promedio de estudiante\n");
    printf("[4] Listar registro\n");
    printf("[5] Consultar aprobacion de estudiante\n");
    printf("[0] Volver al menu principal\n");
    printf("______________________________________________\n");
}
