//
// Created by Bruno on 5/18/2026.
//

#ifndef UNTITLED4_VARIABLES_H
#define UNTITLED4_VARIABLES_H
#define MAX_FICHAS 100
#define MAX_JUGADORES 4
#define MAX_NOMBRE 30
//valores de ambos lados de la ficha, enteros
typedef struct {
    int izquierda;
    int derecha;
} Ficha;
// valores para cada jugador
typedef struct {
    char nombre[30];
    Ficha mano[100]; //arreglo que usa la estructura de una ficha para cada indice de variable
    int cantidadFichas;
    int paresFormados;
    int retirado;
} Jugador;
typedef struct {
    //variables para cada turno
    char nombreJugador[30];
    Ficha ficha1;
    Ficha ficha2;
} Movimiento;
typedef struct {
    char nombre[30];
    int pares;
    char fecha[20];
} Ganador;
#endif //UNTITLED4_VARIABLES_H
