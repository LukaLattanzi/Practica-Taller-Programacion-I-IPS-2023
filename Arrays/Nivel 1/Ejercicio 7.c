// 7) Declare dos arrays de 10 enteros con valores entre [0, 50], luego determine si son: - iguales: cuando cada componente ubicada en misma posición coincide. - similares frente a suma: cuando no tienen las mismas componentes pero la suma de los elementos coincide - diferentes: cuando no coinciden ni en las componentes ni en la suma

#include <stdio.h>
#define ARRAYLENGTH 10

int main()
{
    // Variables ----------------------------------------------------------------------------------
    int arrayUno[ARRAYLENGTH], arrayDos[ARRAYLENGTH], i;
    int sumaElementosUno = 0, sumaElementosDos = 0;
    int arrayIguales = 1;
    // Carga Array 1 ----------------------------------------------------------------------------------
    printf("-- Ingreso de Datos Array 1 --\n");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        do
        {
            printf("Ingrese el elemento %i de %i del array 1: ", i + 1, ARRAYLENGTH);
            scanf("%i", &arrayUno[i]);
        } while (arrayUno[i] < 0 || arrayUno[i] > 50);
        sumaElementosUno += arrayUno[i];
    }
    printf("-- Carga Completa Array 1 --\n");
    // Carga Array 2 ----------------------------------------------------------------------------------
    printf("-- Ingreso de Datos Array 2 --\n");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        do
        {
            printf("Ingrese el elemento %i de %i del array 2: ", i + 1, ARRAYLENGTH);
            scanf("%i", &arrayDos[i]);
        } while (arrayDos[i] < 0 || arrayDos[i] > 50);
        sumaElementosDos += arrayDos[i];
    }
    printf("-- Carga Completa Array 2 --\n");
    // Mostrar Array 1 ----------------------------------------------------------------------------------
    printf("El array 1 es: [ ");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        printf("%i ", arrayUno[i]);
    }
    printf("]\n");
    printf("La suma de los elementos del array 1 es: %i\n", sumaElementosUno);
    // Mostrar Array 2 ----------------------------------------------------------------------------------
    printf("El array 2 es: [ ");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        printf("%i ", arrayDos[i]);
    }
    printf("]\n");
    printf("La suma de los elementos del array 2 es: %i\n", sumaElementosDos);
    // Comparar Arrays ----------------------------------------------------------------------------------
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        if (arrayUno[i] != arrayDos[i])
        {
            arrayIguales = 0;
            break;
        }
    }
    // Mostrar Mensajes ----------------------------------------------------------------------------------
    if (arrayIguales)
    {
        printf("Los array son iguales ya que tienen los mismos elementos en la misma posicion.");
    }
    else if (sumaElementosUno == sumaElementosDos)
    {
        printf("Los array son similares ya que la suma de sus elementos es la misma.");
    }
    else
    {
        printf("Los array son distintos ya que no comparten los mismos elementos y su suma es distinta.");
    }
    // Fin ----------------------------------------------------------------------------------
    return 0;
}
