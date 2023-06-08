// 5) Dado un array de 10 floats, mostrar por pantalla cuales elementos superan al promedio.

#include <stdio.h>
#define ARRAYLENGTH 10

int main()
{
    float numerosArray[ARRAYLENGTH], promedioNumeros = 0;
    int i;
    printf("-- Ingreso de Datos --\n");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        printf("Ingrese el elemento %i de %i del array: ", i + 1, ARRAYLENGTH);
        scanf("%f", &numerosArray[i]);
        promedioNumeros += numerosArray[i];
    }
    promedioNumeros /= ARRAYLENGTH;
    printf("-- Carga Completa --\n");
    printf("El promedio entre todos los numeros del array es de: %f\n", promedioNumeros);
    printf("El array es: [ ");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        printf("%f ", numerosArray[i]);
    }
    printf("Los numeros que superan al promedio son: [ ");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        if (numerosArray[i] > promedioNumeros)
        {
            printf("%f ", numerosArray[i]);
        }
    }
    printf("]\n");
    return 0;
}
