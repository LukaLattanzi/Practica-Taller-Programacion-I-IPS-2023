// 8) Permita la caga de una array de 30 enteros aleatorios. Luego mostrarlos por pantalla.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define LENGTH 30

int main()
{
    // Variables ----------------------------------------------------------------------------------
    srand(getpid());
    int arrayRandom[LENGTH];
    // Carga Y Muestra Del Array ----------------------------------------------------------------------------------
    printf("---- Array Numeros Random ----");
    printf("[ ");
    for (int i = 0; i < LENGTH; i++)
    {
        arrayRandom[i] = rand();
        printf("%i ", arrayRandom[i]);
    }
    printf("]");
    // Fin ----------------------------------------------------------------------------------
    return 0;
}
