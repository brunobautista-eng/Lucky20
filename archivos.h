//
// Created by Bruno on 5/18/2026.
//

#ifndef UNTITLED4_ARCHIVOS_H
#define UNTITLED4_ARCHIVOS_H
#include "variables.h"

void guardarGanador(Ganador ganador);

void mostrarGanadores();

void guardarMovimiento(
    char archivo[],
    Movimiento movimiento
);

void reproducirPartida(char archivo[]);

void generarNombreArchivo(char nombre[]);
#endif //UNTITLED4_ARCHIVOS_H
