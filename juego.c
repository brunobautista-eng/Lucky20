//
// Created by Bruno on 5/18/2026.
//

#include "juego.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "variables.h"
#include "funcionesjuego.h"
#include "archivos.h"

void iniciarJuego() //inicializa el juego, pide datos de jugadores, reparte fichas del banco barajado, ejecuta el bucle principal de turnos y determina el ganador al final, el bucle principal itera sobre jugadores activos, procesa su opcion (formar par, pedir fichas o retirarse) y verifica si algun jugador gano o todos se retiraron
{
    Ficha banco[MAX_FICHAS];
    Jugador jugadores[MAX_JUGADORES];

    int cantidadBanco;
    int tope = 0;
    int numJugadores;
    int maximo;
    int i;
    int j;
do {
    printf("Numero de jugadores(1-4): ");
    scanf("%d", &numJugadores);
    if(numJugadores > MAX_JUGADORES) {
        printf("Maximo 4 jugadores, intenta de nuevo");
    }
    else if (numJugadores < 1) {
        printf("Es de 1 minimo, intenta denuevo");
    }
}while (numJugadores<1 || numJugadores>MAX_JUGADORES);
    printf("Tipo domino (6,9,12): ");
    scanf("%d", &maximo);

    for(i = 0; i < numJugadores; i++)
    {
        printf("Nombre jugador %d: ", i + 1);
        scanf("%s", jugadores[i].nombre);
        jugadores[i].cantidadFichas = 0;
        jugadores[i].paresFormados = 0;
        jugadores[i].retirado = 0;
    }

    cantidadBanco = crearDomino(banco, maximo);
    barajar(banco, cantidadBanco);

    for(i = 0; i < numJugadores; i++)
    {
        jugadores[i].cantidadFichas = 6;

        for(j = 0; j < 6; j++)
        {
            jugadores[i].mano[j] = banco[tope];
            tope++;
        }
    }

    char archivoPartida[50];
    generarNombreArchivo(archivoPartida);

    int ganador = -1;

    while(1)
    {
        int activos = 0;

        for(i = 0; i < numJugadores; i++)
        {
            if(jugadores[i].retirado == 0)
            {
                activos++;

                printf("\nTurno de %s\n", jugadores[i].nombre);
                mostrarMano(jugadores[i]);
                printf("\nFichas banco: %d\n", cantidadBanco - tope);
                printf("\n1. Formar par");
                printf("\n2. Pedir 4 fichas");
                printf("\n3. Retirarse\n");

                int opcion;
                scanf("%d", &opcion);

                if(opcion == 1)
                {
                    int a, b;
                    printf("Indice ficha 1: ");
                    scanf("%d", &a);
                    printf("Indice ficha 2: ");
                    scanf("%d", &b);

                    if(a < 0 || b < 0 ||
                       a >= jugadores[i].cantidadFichas ||
                       b >= jugadores[i].cantidadFichas ||
                       a == b)
                    {
                        printf("Indices invalidos.\n");
                        i--;
                        continue;
                    }

                    if(a < b)
                    {
                        int tmp = a;
                        a = b;
                        b = tmp;
                    }

                    if(forman20(jugadores[i].mano[a], jugadores[i].mano[b]))
                    {
                        eliminarFicha(jugadores, i, a);
                        eliminarFicha(jugadores, i, b);
                        jugadores[i].paresFormados++;
                        printf("Par valido.\n");

                        if(jugadores[i].cantidadFichas == 0)
                        {
                            ganador = i;
                        }
                    }
                    else
                    {
                        printf("No suman 20.\n");
                        i--;
                        continue;
                    }
                }
                else if(opcion == 2)
                {
                    int k;

                    for(k = 0; k < 4 && tope < cantidadBanco; k++)
                    {
                        jugadores[i].mano[jugadores[i].cantidadFichas] = banco[tope];
                        jugadores[i].cantidadFichas++;
                        tope++;
                    }
                }
                else
                {
                    jugadores[i].retirado = 1;
                }
            }

            if(ganador != -1)
                break;
        }

        if(ganador != -1 || activos == 0)
            break;
    }

    if(ganador != -1)
    {
        printf("\nGanador: %s\n", jugadores[ganador].nombre);

        Ganador ganadorPartida;
        strcpy(ganadorPartida.nombre, jugadores[ganador].nombre);
        ganadorPartida.pares = jugadores[ganador].paresFormados;

        time_t t = time(NULL);
        strftime(ganadorPartida.fecha, 20, "%d/%m/%Y", localtime(&t));

        guardarGanador(ganadorPartida);
    }
    else
    {
        printf("\nTodos pierden.\n");
    }
}