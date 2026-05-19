//
// Created by Bruno on 5/18/2026.
//

#ifndef UNTITLED4_FUNCIONESJUEGO_H
#define UNTITLED4_FUNCIONESJUEGO_H
#include "variables.h"
int crearDomino(Ficha banco[], int maximo);
void barajar(Ficha banco[], int cantidad);
void mostrarFicha(Ficha ficha);
void mostrarMano(Jugador jugador);
int sumaFicha(Ficha ficha);
int forman20(Ficha a, Ficha b);
void eliminarFicha(Jugador jugadores[], int indiceJugador, int posicion);
#endif //UNTITLED4_FUNCIONESJUEGO_H
