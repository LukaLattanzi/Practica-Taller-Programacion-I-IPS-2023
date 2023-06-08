// 18) Dado un array de 10 enteros positivos en el rango [0, 100] cargados aleatoriamente, mostrarlo por pantalla, luego ordenar sus elementos de manera ascendente y finalmente mostrar el resultado.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 10

int main()
{
    // Variables ----------------------------------------------------------------------------------
    srand(getpid());
    int array[N], i, j, aux;
    // Carga ----------------------------------------------------------------------------------
    printf("El Array Es: [ ");
    for (i = 0; i < N; i++)
    {
        array[i] = rand() % 101;
        printf("%i ", array[i]);
    }
    printf("]\n");
    // Ordenamiento ----------------------------------------------------------------------------------
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                aux = array[j + 1];
                array[j + 1] = array[j];
                array[j] = aux;
            }
        }
    }
    // Resultado ----------------------------------------------------------------------------------
    printf("El Array Ordenado Es: [ ");
    for (i = 0; i < N; i++)
    {
        printf("%i ", array[i]);
    }
    printf("]\n");
    // Fin ----------------------------------------------------------------------------------
    return 0;
}