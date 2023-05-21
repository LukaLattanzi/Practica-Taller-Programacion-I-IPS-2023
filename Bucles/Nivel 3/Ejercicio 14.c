// 14) Calcule el factorial de un número entero positvo.

#include <stdio.h>

int main()
{
    int numero;
    int long long factorial = 1;
    printf("Ingrese un numero entero positivo: ");
    scanf("%i", &numero);
    if (numero < 0)
    {
        printf("El numero debe ser positivo.\n");
        return 0;
    }
    for (int i = 1; i <= numero; i++)
    {
        factorial *= i;
    }
    printf("El factorial de %i es %lli.\n", numero, factorial);
    return 0;
}