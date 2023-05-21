// 15) Muestre las tablas de multiplicar del 1 al 10.

#include <stdio.h>
#define DIEZ 10

int main()
{
    for (int i = 1; i <= DIEZ; i++)
    {
        printf("Tabla de multiplicar del %i: ", i);
        for (int j = 0; j <= DIEZ; j++)
        {
            printf("%i ", i * j);
        }
        printf("\n");
    }
}