#include <stdio.h>

int main(void) {
    int opcion;
    do {
        printf("1. Nueva partida \n 2. Ver ganadores \n 3. Reproducir partida \n");
        scanf("%d",&opcion);
    }while (opcion != 4);

    return 0;
}