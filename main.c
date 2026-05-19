#include <stdio.h>

int main(void) {
    //menu principal, utiliza switch case
    int opcion;
    do {
        printf("1. Nueva partida \n 2. Ver ganadores \n 3. Reproducir partida \n");
        scanf("%d",&opcion);
        switch (opcion) {
            case 1:
                //funcion para iniciar juego
                break;
            case 2: break;
                //funcion para ver lista en archivo
            case 3: break;
                //funcion para leer archivo
            case 4: printf("Fin de programa\n");
        }

    }while (opcion != 4);

    return 0;
}