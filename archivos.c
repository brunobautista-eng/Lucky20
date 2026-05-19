//
// Created by Bruno on 5/18/2026.
//
#include <stdio.h>
#include <time.h>
#include "archivos.h"
#include "funcionesjuego.h"

void guardarGanador(Ganador ganador)
{
    FILE *archivo;

    archivo = fopen("ganadores.bin", "ab");

    if(archivo != NULL)
    {
        fwrite(
            &ganador,
            sizeof(Ganador),
            1,
            archivo
        );

        fclose(archivo);
    }
}
void mostrarGanadores() {
    FILE *archivo;
    Ganador ganador;
    archivo = fopen("ganadores.bin", "rb");
    if(archivo == NULL) {
        printf("No existe este archivo");
        return;
    }
    while (fread(&ganador,sizeof(Ganador),1,archivo)) {
        printf("Jugador: %s\n",ganador.nombre);
        printf("Pares: %d\n",ganador.pares);
        printf("Fecha: %d\n",ganador.fecha);
        fclose(archivo);
    }
}

void guardarMovimiento(
    char archivoNombre[],
    Movimiento movimiento
)
{
    FILE *archivo;

    archivo = fopen(archivoNombre, "ab");

    if(archivo != NULL)
    {
        fwrite(
            &movimiento,
            sizeof(Movimiento),
            1,
            archivo
        );

        fclose(archivo);
    }
}

void reproducirPartida(char archivoNombre[])
{
    FILE *archivo;

    Movimiento movimiento;

    archivo = fopen(archivoNombre, "rb");

    if(archivo == NULL)
    {
        printf("Error: archivo inexistente.\n");

        return;
    }

    while(
        fread(
            &movimiento,
            sizeof(Movimiento),
            1,
            archivo
        )
    )
    {
        printf("\nJugador: %s\n",
               movimiento.nombreJugador);

        mostrarFicha(movimiento.ficha1);

        printf(" + ");

        mostrarFicha(movimiento.ficha2);

        printf(" = 20\n");
    }

    fclose(archivo);
}

void generarNombreArchivo(char nombre[])
{
    time_t t;

    struct tm fecha;

    int contador = 1;

    FILE *archivo;

    t = time(NULL);

    fecha = *localtime(&t);

    sprintf(
        nombre,
        "partida%02d%02d%04d.bin",
        fecha.tm_mday,
        fecha.tm_mon + 1,
        fecha.tm_year + 1900
    );

    archivo = fopen(nombre, "rb");

    while(archivo != NULL)
    {
        fclose(archivo);

        sprintf(
            nombre,
            "partida%02d%02d%04d-%d.bin",
            fecha.tm_mday,
            fecha.tm_mon + 1,
            fecha.tm_year + 1900,
            contador
        );

        contador++;

        archivo = fopen(nombre, "rb");
    }
}

