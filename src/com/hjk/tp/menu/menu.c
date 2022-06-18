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
    printf("[2] Agregar alumno\n");
    printf("[3] Inscribir alumno en materia\n");
    printf("[4] Registrar nota\n");

    printf("[0] Volver al menu principal\n");
    printf("______________________________________________\n");
}

void menu_print_query_options() {
    printf("############ Consultas del sistema ###########\n");
    printf("Elija una de las siguientes opciones:\n\n");
    printf("[1] Consultar materias\n");
    printf("[2] Consultar estudiantes\n");
    printf("[3] Consultar cursadas\n");
    printf("[4] Listar registro\n");
    printf("[0] Volver al menu principal\n");
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

// int realizar_consultas(registro *registro_actual) {
//     printf("----- Consultas del sistema -----\n");

//     printf("Elija una de las siguientes opciones:\n\n");
//     printf("[1] Consultar materias\n");
//     printf("[2] Consultar estudiantes\n");
//     printf("[3] Consultar cursadas\n");
//     printf("[4] Consultar calificaciones\n");
//     printf("[5] Volver al menu principal\n");
// }

// int consultar_estudiantes() {
//     printf("----- Consultar estudiantes -----\n");

//     printf("Elija una de las siguientes opciones:\n\n");
//     printf("[1] Consultar estudiantes por nombre\n");
//     printf("[2] Consultar estudiantes por edad\n");
//     printf("[3] Volver al menu principal\n");

//     printf("Tu opcion: ");
//     int option_choose = -1;
//     scanf("%i", &option_choose);

//     switch (option_choose) {
//         case 1:

//             break;
//         case 2:

//             break;
//         default:
//             printf("Ninguna opcion configurada para ese valor.");
//     }


// int agregar_materia(estudiante *registro_actual) {
//     char codigo_materia[10];
//     char nombre_materia[25];

//     if(existe_materia(registro_actual, codigo_materia)) {
//         printf("La materia ya existe.");
//     } else {
//         printf("Ingrese el codigo de la materia: ");
//         scanf("%s", codigo_materia);
//         printf("Ingrese el nombre de la materia: ");
//         scanf("%s", nombre_materia);
//         materia *materia_nueva = new_materia(codigo_materia, nombre_materia);


//         printf("Materia agregada con exito!\n");
//         //printf("Materia_Name: %s, Materia_Code: %s", materia->nombre, materia->id);

//     }