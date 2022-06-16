#include <stdio.h>
#include <com/hjk/tp/list/list.h>
#include "materia/materia.h"
#include "estudiante/registro.h"

// ToDo TODOS Terminar GUI

int main() {

    int continuar_ejecucion = 1;
    printf("Bienvenida/o al Sistema de Gestion Estudiantil SIGIL\n");

    do {
        printf("Elija una de las siguientes opciones para continuar:\n\n");
        printf("[1] Crear nueva Materia\n");
        printf("[2] Crear nuevo Estudiante\n");

        printf("Tu opcion: ");
        int option_choose = -1;
        scanf("%i", &option_choose);

        switch (option_choose) {
            case 1:
                printf("Indique el nombre de la materia: ");
                char nombre_materia;
                scanf("%s", &nombre_materia);

                printf("Ahora indique un codigo unico para identificar la materia: ");
                unsigned short codigo_materia;
                scanf("%i", &codigo_materia);

                materia* una_materia = new_materia(codigo_materia, nombre_materia);

                printf("Nombre: %s, Codigo: %i", una_materia->nombre, una_materia->id);

                break;
            default:
                printf("Ninguna opcion configurada para ese valor.\n");
        }
    } while (continuar_ejecucion);

    return 0;
}

// TODO Interfaz grafica - anotar materia (Copilot)