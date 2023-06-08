// 15) Dadas dos matrices de dimensión NxN, llamadas X e Y, mostrar por pantalla la suma de las mismas.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 3

int main()
{
    // Variables ----------------------------------------------------------------------------------
    srand(getpid());
    int matrizUno[N][N],matrizDos[N][N], i, j;
    // Carga Matriz 1 ----------------------------------------------------------------------------------
    printf("La Matriz Uno Es:\n");
    for (i = 0; i < N; i++) // Recorre Filas
    {
        for (j = 0; j < N; j++) // Recorre Columnas
        {
            matrizUno[i][j] = rand()%10;
            printf("%i ", matrizUno[i][j]);
        }
        printf("\n");
    }
    // Carga Matriz 2 ----------------------------------------------------------------------------------
    printf("La Matriz Dos Es:\n");
    for (i = 0; i < N; i++) // Recorre Filas
    {
        for (j = 0; j < N; j++) // Recorre Columnas
        {
            matrizDos[i][j] = rand()%10;
            printf("%i ", matrizDos[i][j]);
        }
        printf("\n");
    }
    // Resultado Suma ----------------------------------------------------------------------------------
    printf("La Suma De Las Matrices Es:\n");
    for (i = 0; i < N; i++) // Recorre Filas
    {
        for (j = 0; j < N; j++) // Recorre Columnas
        {
            printf("%i ", matrizUno[i][j] + matrizDos[i][j]);
        }
        printf("\n");
    }
    // Fin ----------------------------------------------------------------------------------
    return 0;
}