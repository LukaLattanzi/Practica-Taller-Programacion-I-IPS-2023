// 6) Calcule el promedio de 10 números ingresados por el usuario.

#include <stdio.h>
#define cantidadNumeros 10

int main()
{
    int num;
    int suma = 0;
    for (int i = 1; i <= cantidadNumeros; i++)
    {
        printf("Ingrese el numero %i de %i: ", i, cantidadNumeros);
        scanf("%i", &num);
        suma += num;
    }
    double promedio = (double)suma / cantidadNumeros;
    printf("El promedio de los numeros ingresados es: %.2lf.\n", promedio);
    return 0;
}