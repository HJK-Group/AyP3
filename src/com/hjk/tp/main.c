#include <stdio.h>
#include <com/hjk/tp/list/list.h>

typedef enum { ORO, ESPADA, COPA, BASTO } palo;

typedef struct carta {
    palo palo;
    int valor;
} carta;

char *get_palo(carta *carta) {
    switch(carta->palo) {
        case ORO:
            return "Oro";
        case ESPADA:
            return "Espada";
        case COPA:
            return "Copa";
        case BASTO:
            return "Basto";
        default:
            return "";
    }
}

void print_carta(carta *carta) {
    printf("%d de %s", carta->valor, get_palo(carta));
}

int main()
{
    list *lista = new_empty_list();
    carta algo = {10, COPA};
    carta otra = {1, ESPADA};
    list_add(lista, &algo, sizeof(carta));
    list_add(lista, &otra, sizeof(carta));

    carta *element = list_get(lista, 1);
    list_print(lista);
    return 0;
}