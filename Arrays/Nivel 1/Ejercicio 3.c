// 3) Declare un array de 10 enteros, permita la carga manual y luego determine lo siguiente: cuantos elementos son positivos y pares, cuantos elementos son positivos e impares, cuantos elementos son negativos y pares y cuantos elementos son negativos e impares.

#include <stdio.h>
#define ARRAYLENGTH 10

int main()
{
    int numerosArray[ARRAYLENGTH], i, positivosPares = 0, positivosImpares = 0, negativosPares = 0, negativosImpares = 0;
    printf("Ingrese %i numeros enteros:\n", ARRAYLENGTH);
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        printf("El elemento %i del array: ", i + 1);
        scanf("%i", &numerosArray[i]);
    }
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        if (numerosArray[i] > 0)
        {
            if (numerosArray[i] % 2 == 0)
            {
                positivosPares++;
            }
            else
            {
                positivosImpares++;
            }
        }
        else if (numerosArray[i] < 0)
        {
            if (numerosArray[i] % 2 == 0)
            {
                negativosPares++;
            }
            else
            {
                negativosImpares++;
            }
        }
    }
    printf("Cantidad de elementos positivos y pares: %i\n", positivosPares);
    printf("Cantidad de elementos positivos e impares: %i\n", positivosImpares);
    printf("Cantidad de elementos negativos y pares: %i\n", negativosPares);
    printf("Cantidad de elementos negativos e impares: %i\n", negativosImpares);
    return 0;
}
