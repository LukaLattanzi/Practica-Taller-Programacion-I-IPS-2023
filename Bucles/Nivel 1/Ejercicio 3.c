// 3) Muestre la suma de todos los números impares que van del 1 al 100.

#include <stdio.h>

int main()
{
    int suma;
    for (int i = 1; i <= 100; i += 2)
    {
        suma += i;
    }
    printf("La suma de todos los numeros impares que van del 1 al 100 es: %i.\n", suma);
    return 0;
}