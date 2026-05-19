//
// Created by Bruno on 5/18/2026.
//
#include <stdio.h>
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

