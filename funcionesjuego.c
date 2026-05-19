//
// Created by Bruno on 5/18/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "variables.h"
int crearDomino(Ficha banco[], int maximo) //genera todas las fichas posibles del domino hasta el valor maximo indicado, las guarda en el arreglo banco y retorna la cantidad generada

{
    int c = 0;

    for(int i = 0; i <= maximo; i++)
    {
        for(int j = i; j <= maximo; j++)
        {
            banco[c].izquierda = i;
            banco[c].derecha = j;
            c++;
        }
    }

    return c;
}

void barajar(Ficha banco[], int cantidad) //mezcla aleatoriamente las fichas del arreglo banco usando srand con la hora actual como semilla

{
    srand(time(NULL));

    for(int i = 0; i < cantidad; i++)
    {
        int r = rand() % cantidad;

        Ficha tmp = banco[i];
        banco[i] = banco[r];
        banco[r] = tmp;
    }
}

void mostrarFicha(Ficha f) //imprime en consola una ficha con el formato [izquierda|derecha]
{
    printf("[%d|%d]", f.izquierda, f.derecha);
}

void mostrarMano(Jugador j) //recorre el arreglo de fichas del jugador e imprime cada una con su indice usando mostrarFicha
{
    for(int i = 0; i < j.cantidadFichas; i++)
    {
        printf("%d: ", i);
        mostrarFicha(j.mano[i]);
        printf("\n");
    }
}

int sumaFicha(Ficha f) //retorna la suma de los valores izquierdo y derecho de una ficha
{
    return f.izquierda + f.derecha;
}

int forman20(Ficha a, Ficha b) //verifica si dos fichas pueden formar un par valido, considera fichas con cero como comodines que se adaptan al valor necesario para completar 20
{
    int sa = sumaFicha(a);
    int sb = sumaFicha(b);

    int esComodinA = (a.izquierda == 0 || a.derecha == 0);
    int esComodinB = (b.izquierda == 0 || b.derecha == 0);

    if(esComodinA && esComodinB)
        return 1;

    if(esComodinA)
        return (sb <= 20);

    if(esComodinB)
        return (sa <= 20);

    return (sa + sb == 20);
}
int eliminarFicha(Jugador jugadores[], int i, int pos) //elimina la ficha en la posicion indicada del arreglo mano del jugador desplazando las fichas siguientes una posicion atras y reduciendo el contador

{
    if(pos < 0 || pos >= jugadores[i].cantidadFichas)
        return 0;

    for(int k = pos; k < jugadores[i].cantidadFichas - 1; k++)
    {
        jugadores[i].mano[k] = jugadores[i].mano[k + 1];
    }

    jugadores[i].cantidadFichas--;

    return 1;
}