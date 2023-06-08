// 10) Dado un array A de 10 ints cargado aleatoriamente y con valores comprendidos entre 0 y 100, determinar si se tienen más elementos pares que impares o bien misma cantidad. Rehaga el ejercicio utilizando un único bucle for si empleo más de uno.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define LENGTH 10
#define VALORMAX 100

int main()
{
    // Variables ----------------------------------------------------------------------------------
    srand(getpid());
    int arrayA[LENGTH], paresA = 0, imparesA = 0;
    // Carga A ----------------------------------------------------------------------------------
    printf("---- Carga Array A ----\n");
    printf("[ ");
    for (int i = 0; i < LENGTH; i++)
    {
        arrayA[i] = rand() % 101;
        if (arrayA[i] % 2 == 0)
        {
            paresA++;
        }
        else
        {
            imparesA++;
        }
        printf("%i ", arrayA[i]);
    }
    printf("]\n");
    // Resultados ----------------------------------------------------------------------------------
    printf("En El Array Se Encontraron %i Numeros Pares Y %i Numeros Impares.\n", paresA, imparesA);
    if (paresA > imparesA)
    {
        printf("Eso Implica Que Hay Mas Numeros Pares Que Impares.\n");
    }
    else if (paresA < imparesA)
    {
        printf("Eso Implica Que Hay Mas Numeros Impares Que Pares.\n");
    }
    else
    {
        printf("Eso Implica Que Hay La Misma Cantidad De Numeros Pares Que Impares.\n");
    }
    // Fin ----------------------------------------------------------------------------------
    return 0;
}
