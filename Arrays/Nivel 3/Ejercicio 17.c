// 17) Dado un array A de 20 enteros positivos en el rango [0, 100] cargados aleatoriamente, y un entero positivo e, determinar si dicho entero e está presente en el array. Extender luego el programa para indicar no solo si está, sino también en cuantas ocasiones aparece.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 20

int main()
{
    // Variables ----------------------------------------------------------------------------------
    srand(getpid());
    int array[N], i, e, contador = 0;
    // Carga ----------------------------------------------------------------------------------
    e = rand() % 101;
    printf("El Numero A Buscar Es: %i\n", e);
    printf("El Array Es: [ ");
    for (i = 0; i < N; i++)
    {
        array[i] = rand() % 101;
        printf("%i ", array[i]);
    }
    printf("]\n");
    // Calcular ----------------------------------------------------------------------------------
    for (i = 0; i < N; i++)
    {
        if (array[i] == e)
        {
            contador++;
        }
    }
    // Resultado ----------------------------------------------------------------------------------
    if (contador == 0)
    {
        printf("El Numero %i No Esta En El Array\n", e);
    }
    else
    {
        printf("El Numero %i Esta En El Array %i Veces\n", e, contador);
    }
    // Fin ----------------------------------------------------------------------------------
    return 0;
}