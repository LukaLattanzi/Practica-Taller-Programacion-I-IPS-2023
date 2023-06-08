// 6) Declare un array de 10 enteros y muestre por pantalla dichos elementos junto con la suma, el promedio y la varianza. Investigar sobre los términos que desconozca.

#include <stdio.h>
#include <math.h>
#define ARRAYLENGTH 10

int main()
{
    int numerosArray[ARRAYLENGTH];
    int i, suma = 0;
    double promedio, varianza = 0.0;
    printf("-- Ingreso de Datos --\n");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        printf("Ingrese el elemento %i de %i del array: ", i + 1, ARRAYLENGTH);
        scanf("%d", &numerosArray[i]);
    }
    printf("-- Carga Completa --\n");
    printf("Elementos del array: [ ");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        printf("%d ", numerosArray[i]);
    }
    printf("]\n");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        suma += numerosArray[i];
    }
    promedio = (double)suma / ARRAYLENGTH;
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        varianza += pow(numerosArray[i] - promedio, 2);
    }
    varianza /= ARRAYLENGTH;
    printf("La suma es: %d\n", suma);
    printf("El promedio es: %.2f\n", promedio);
    printf("La varianza es: %.2f\n", varianza);
    return 0;
}
