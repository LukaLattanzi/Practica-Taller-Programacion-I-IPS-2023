// 1) Declare un array de 10 enteros y permita que el usuario ingrese valores comprendidos entre el -10 y el 10 (asegurar esto) y luego lo muestre por pantalla.

#include <stdio.h>
#define ARRAYLENGTH 10

int main()
{
    int numArray[ARRAYLENGTH], numero, i;
    printf("Ingrese %i numeros para el array (Solo son validos numeros entre el -10 y el 10 inclusive)\n", ARRAYLENGTH);
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        do
        {
            printf("Ingrese el numero %i de %i: ", i + 1, ARRAYLENGTH);
            scanf("%i", &numero);
            numArray[i] = numero;
        } while (numArray[i] < -10 || numArray[i] > 10);
    }
    printf("Listo la carga de datos!\n");
    printf("El array quedo: [ ");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        printf("%i ", numArray[i]);
    }
    printf("]");
    return 0;
}