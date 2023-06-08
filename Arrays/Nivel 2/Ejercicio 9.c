// 9) Permita la carga aleatoria de dos arrays de 10 enteros cada uno, llamados A y B, e indique cual de los dos tiene más números pares tratando de utilizando como máximo dos bucles for en todo el programa.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define LENGTH 10

int main()
{
    // Variables ----------------------------------------------------------------------------------
    srand(getpid());
    int arrayA[LENGTH], arrayB[LENGTH], paresA = 0, paresB = 0;
    // Carga A ----------------------------------------------------------------------------------
    printf("---- Carga Array A ----\n");
    printf("[ ");
    for (int i = 0; i < LENGTH; i++)
    {
        arrayA[i] = rand();
        if (arrayA[i] % 2 == 0)
        {
            paresA++;
        }
        printf("%i ", arrayA[i]);
    }
    printf("]\n");
    // Carga B ----------------------------------------------------------------------------------
    printf("---- Carga Array B ----\n");
    printf("[ ");
    for (int i = 0; i < LENGTH; i++)
    {
        arrayB[i] = rand();
        if (arrayB[i] % 2 == 0)
        {
            paresB++;
        }
        printf("%i ", arrayB[i]);
    }
    printf("]\n");
    // Resultados ----------------------------------------------------------------------------------
    printf("---- Resultados ----\n");
    printf("El array A tiene %i numeros pares.\n", paresA);
    printf("El array B tiene %i numeros pares.\n", paresB);
    if (paresA > paresB)
    {
        printf("Osea que el array A tiene mas numeros pares.");
    }
    else if (paresA < paresB)
    {
        printf("Osea que el array B tiene mas numeros pares.");
    }
    else
    {
        printf("Osea que ambos array tienen la misma cantidad de numeros pares.");
    }
    // Fin ----------------------------------------------------------------------------------
    return 0;
}
