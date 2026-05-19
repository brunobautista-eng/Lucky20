#include <stdio.h>
#include "juego.h"
#include "archivos.h"
int main(void) {
    int opcion;
    do {
        printf("1. Nueva partida \n 2. Ver ganadores \n 3. Reproducir partida \n 4. Salir\n");
        scanf("%d",&opcion);
        switch (opcion) {
            case 1:
                //funcion para iniciar juego
                iniciarJuego();
                break;
            case 2: mostrarGanadores();
                //funcion para ver lista en archivo
                break;
            case 3:
                //funcion para leer archivo
            {
                char archivo[50];
                printf("Nombre archivo: ");
                scanf("%s", archivo);
                reproducirPartida(archivo);
                break;
            }
            case 4: printf("Fin de programa\n");
                break;
            default:

                printf("Opcion invalida.\n");
        }
    }while (opcion != 4);
    return 0;
}