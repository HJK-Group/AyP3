#include <stdio.h>
#include <com/hjk/tp/list/list.h>
#include "materia/materia.h"

// TODO revisar gui

int main() {

/*    materia* mi_materia = crear_materia("MAT2022", "Analisis I");

    list *lista = new_empty_list();
    carta algo = {10, COPA};
    carta otra = {1, ESPADA};
    list_add(lista, &algo, sizeof(carta));
    list_add(lista, &otra, sizeof(carta));
    list_print(lista, &print_carta);*/

    printf("Bienvenida/o al Sistema de Gestion Estudiantil SIGIL\n");

    printf("Elija una de las siguientes opciones para continuar:\n\n");
    printf("[1] Crear nueva Materia\n\n");

    printf("Tu opcion: ");
    int option_choose = -1;
    scanf("%i", &option_choose);

//    printf("%d", option_choose);

    switch (option_choose) {
        case 1:
            printf("Indique el nombre de la materia: ");
            char codigo_materia[10];
            char nombre_materia[25];

            scanf("%s", &nombre_materia);

            printf("Ahora indique un codigo unico para identificar la materia: ");
            scanf("%s", &codigo_materia);

            materia *materia = new_materia(codigo_materia, nombre_materia);

            printf("Materia_Name: %s, Materia_Code: %s", materia->nombre, materia->id);

            break;
        default:
            printf("Ninguna opcion configurada para ese valor.");
    }

    return 0;
}

// TODO Interfaz grafica - anotar materia (Copilot)