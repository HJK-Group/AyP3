#include <stdio.h>
#include <com/hjk/tp/list/list.h>
#include "materia/materia.h"
#include "estudiante/registro.h"

// ToDo TODOS Terminar GUI

int realizar_consultas();

int abm_registros();

int agregar_materia();

int agregar_estudiante();

int inscribir_alumno_materia();


int main() {

// ToDo Lista de Materias unívocas.
// Todo Método para añadir Materia a la Lista.
    registro *registro_actual = new_registro(); // TODO Eleminar, solo parra probar el codigo.

//
//    ---------------------------

    printf("Bienvenida/o al Sistema de Gestion Estudiantil SIGIL\n");

    printf("Elija una de las siguientes opciones para continuar:\n\n");
    printf("[1] Realizar consultas al sistema\n\n");
    printf("[2] Agregar, modificar o borrar registros del sistema\n\n");


    printf("Tu opcion: ");
    int option_choose = -1;
    scanf("%i", &option_choose);

//    printf("%d", option_choose);

    switch (option_choose) {
        case 1:
            realizar_consultas(registro_actual);
            break;

        case 2:
            abm_registros(registro_actual);
            break;
        default:
            printf("Ninguna opcion configurada para ese valor.");
    }

    return 0;
}

// TODO Interfaz grafica - anotar materia (Copilot)

int realizar_consultas(registro *registro_actual) {
    printf("----- Consultas del sistema -----\n");

    printf("Elija una de las siguientes opciones:\n\n");
    printf("[1] Consultar materias\n");
    printf("[2] Consultar estudiantes\n");
    printf("[3] Consultar cursadas\n");
    printf("[4] Consultar calificaciones\n");
    printf("[5] Volver al menu principal\n");

}

int abm_registros(registro *registro_actual) {
    printf("----- ABM Registros -----\n");

    printf("Elija una de las siguientes opciones:\n\n");
    printf("[1] Agregar materia\n");
    printf("[2] Agregar alumno\n");
    printf("[3] Inscribir alumno en materia\n");
    printf("[4] Volver al menu principal\n");

    printf("Tu opcion: ");
    int option_choose = -1;
    scanf("%i", &option_choose);

    switch (option_choose) {
        case 1:
            agregar_materia();
            break;
        case 2:
            agregar_estudiante(registro_actual);
            break;
        case 3:
            inscribir_alumno_materia();
            break;
        default:
            printf("Ninguna opcion configurada para ese valor.");
    }

}

// CONSULTAS DEL SISTEMA

int consultar_estudiantes() {
    printf("----- Consultar estudiantes -----\n");

    printf("Elija una de las siguientes opciones:\n\n");
    printf("[1] Consultar estudiantes por nombre\n");
    printf("[2] Consultar estudiantes por apellido\n");
    printf("[3] Consultar estudiantes por DNI\n");
}

// ABM REGISTORS

int agregar_materia() {
    char codigo_materia[10]; // Chequear que no exista un duplicado
    char nombre_materia[25];

    printf("Indique un codigo unico para identificar la materia: ");
    // Este paso podiramos hacerlo interno en el sistema
    scanf("%s", &codigo_materia);

    printf("Indique el nombre de la materia: ");
    scanf("%s", &nombre_materia);

    materia *nueva_materia = new_materia(codigo_materia, nombre_materia);


    printf("Materia agregada con exito!\n");
    //printf("Materia_Name: %s, Materia_Code: %s", materia->nombre, materia->id);

    // TODO Terminar (Juan)
}

int agregar_estudiante(registro *registro_actual) {
    unsigned long legajo;
    char *nombre;
    char *apellido;
    unsigned char edad;

    printf("Indique el legajo del estudiante: ");
    scanf("%lu", &legajo);

    printf("Indique el nombre del estudiante: ");
    scanf("%s", &nombre);

    printf("Indique el apellido del estudiante: ");
    scanf("%s", &apellido);

    printf("Indique la edad del estudiante: ");
    scanf("%hhu", &edad);

    estudiante *nuevo_estudiante = new_estudiante(legajo, nombre, apellido, edad);
    registro_agregar_alumno(registro_actual, nuevo_estudiante);
    return 0;
}