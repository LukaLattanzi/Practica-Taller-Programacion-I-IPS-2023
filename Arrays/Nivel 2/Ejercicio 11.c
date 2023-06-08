// 11) Dado un array A de 10 enteros cargados automáticamente (con números aleatorios), invertir el array, es decir si se tiene el array A= [ 45, 11, -5, 80, 6, 99, 105, -200, 22, 1 ], A deberá quedar del siguiente modo al finalizar el programa A= [ 1, 22, -200, 105, 99, 6, 80, -5, 11, 45 ]. Considere el uso de una variable a modo de pivote.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define LENGTH 10
#define VALORMAX 100

int main()
{
    // Variables ----------------------------------------------------------------------------------
    srand(getpid());
    int arrayA[LENGTH], pivote;
    // Carga A ----------------------------------------------------------------------------------
    printf("El Array Base Es [ ");
    for (int i = 0; i < LENGTH; i++)
    {
        arrayA[i] = rand();
        printf("%i ", arrayA[i]);
    }
    printf("]\n");
    // Invertir A ----------------------------------------------------------------------------------
    for (int i = 0; i <= LENGTH / 2; i++)
    {
        pivote = arrayA[i];
        arrayA[i] = arrayA[(LENGTH - 1) - i];
        arrayA[(LENGTH - 1) - i] = pivote;
    };
    // Resultados ----------------------------------------------------------------------------------
    printf("El Array Invertido Es [ ");
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%i ", arrayA[i]);
    }
    printf("]\n");
    // Fin ----------------------------------------------------------------------------------
    return 0;
}