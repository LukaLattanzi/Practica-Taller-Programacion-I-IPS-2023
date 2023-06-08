// 14) Permitir la carga automática de una matriz de dimensión NxN y mostrarla por pantalla.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 3

int main()
{
    // Variables ----------------------------------------------------------------------------------
    srand(getpid());
    int matriz[N][N], i, j;
    // Carga y Resultado ----------------------------------------------------------------------------------
    printf("La Matriz Es:\n");
    for (i = 0; i < N; i++) // Recorre Filas
    {
        for (j = 0; j < N; j++) // Recorre Columnas
        {
            matriz[i][j] = rand();
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
    // Fin ----------------------------------------------------------------------------------
    return 0;
}