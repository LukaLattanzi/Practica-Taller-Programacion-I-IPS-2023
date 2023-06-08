// 13) Permitir el ingreso de una matriz de enteros de dimensión 3x4 y mostrarla por pantalla.

#include <stdio.h>

int main()
{
    // Variables ----------------------------------------------------------------------------------
    int matriz[3][4], i, j; // 3 Filas, 4 Columnas
    // Carga ----------------------------------------------------------------------------------
    printf("Ingrese Los Valores De La Matriz 3x4:\n");
    for (i = 0; i < 3; i++) // Recorre Filas
    {
        for (j = 0; j < 4; j++) // Recorre Columnas
        {
            printf("Fila %i, Columna %i: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }
    // Resultados ----------------------------------------------------------------------------------
    printf("La Matriz Es:\n");
    for (i = 0; i < 3; i++) // Recorre Filas
    {
        for (j = 0; j < 4; j++) // Recorre Columnas
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
    // Fin ----------------------------------------------------------------------------------
    return 0;
}
