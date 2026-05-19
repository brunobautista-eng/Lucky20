//
// Created by Bruno on 5/18/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "variables.h"
int crearDomino(Ficha banco[], int maximo) {
    //Genera las fichas y asigna valores mediante contador adentro de ciclo for doble y las guarda en el arreglo banco[]
int cantidad = 0;
    int i;
    int j;
    for (i = 0; i <= maximo; i++) {
        for (j = 0; j <= maximo; j++) {
            banco[cantidad].izquierda = i;
            banco[cantidad].derecha = j;
            cantidad++;
        }
    }
    return cantidad;
}

void barajar(Ficha banco[], int cantidad) {
    //Mezcla aleatoriamente las fichas en el banco
    srand(time(nullptr));
    int i;
    for (i = 0; i < cantidad; i++) {
        int r = rand() % cantidad;
        Ficha aux = banco[r];
        banco[i] = banco[r];
        banco[r] = aux;
    }
}

void mostrarFicha(Ficha ficha) {
    //Imprime la ficha en la terminal
    printf("[%d|%d]", ficha.izquierda, ficha.derecha);
}

void mostrarMano(Jugador jugador) {
    //Muestra todas las fichas de un jugador
    int i;
    for (i = 0; i < jugador.cantidadFichas; i++) {
        printf("%d: ", i);
        mostrarFicha(jugador.mano[i]);
        printf("\n");
    }
}

int sumaFicha(Ficha ficha) {
    return ficha.izquierda + ficha.derecha;
}

int forman20(Ficha a, Ficha b) {
    //Verificacion de suma de pares resulte en 20
    int sumA = sumaFicha(a);
    int sumB = sumaFicha(b);
    if (a.izquierda == 0||a.derecha == 0) {
        return 1;
    }
    if (b.izquierda == 0||b.derecha == 0) {
        return 1;
    }
    if (sumA + sumB == 20) {
        return 1;
    }
    return 0;
}
void eliminarFicha(Jugador jugadores[], int indiceJugador, int posicion) {
    int i;
    for (i = posicion; i < jugadores[indiceJugador].cantidadFichas-1; i++) {
        jugadores[indiceJugador].mano[i] =
            jugadores[indiceJugador].mano[i+1];
    }
    jugadores[indiceJugador].cantidadFichas--;
}