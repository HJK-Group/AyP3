#include <stdio.h>
#include <com/hjk/tp/list/list.h>

typedef enum { ORO, ESPADA, COPA, BASTO } palo;

typedef struct carta {
    int valor;
    palo palo;
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

void print_carta(void *data) {
    carta *cart = (carta*) data;
    printf("%d de %s\n", cart->valor, get_palo(cart));
}

int main() {
    list *lista = new_empty_list();
    carta algo = {10, COPA};
    carta otra = {1, ESPADA};
    list_add(lista, &algo, sizeof(carta));
    list_add(lista, &otra, sizeof(carta));
    list_print(lista, &print_carta);
    return 0;
}

// TODO Interfaz grafica - anotar materia (Hernan)