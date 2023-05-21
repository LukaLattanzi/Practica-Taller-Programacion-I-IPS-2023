// 11) Calcule el promedio de N números, se dejarán de solicitar números hasta que se introduzca el cero.

#include <stdio.h>

int main()
{
    int contador = 0;
    int suma = 0;
    int num;
    printf("Ingrese un num (ingrese 0 para terminar): ");
    scanf("%d", &num);
    while (num != 0)
    {
        suma += num;
        contador++;
        printf("Ingrese otro num (ingrese 0 para terminar): ");
        scanf("%d", &num);
    }
    if (contador > 0)
    {
        printf("La suma de todos los nums ingresados es igual a: %i\n", suma);
        printf("Se ingresaron %i nums.\n", contador);
        printf("El promedio es igual a: %.2f\n", (float)suma / contador);
    }
    else
    {
        printf("No se ingresaron nums.\n");
    }
    return 0;
}