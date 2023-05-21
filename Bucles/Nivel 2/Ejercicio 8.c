// 8) Muestre los divisores de un número.

#include <stdio.h>

int main()
{
    int num;
    printf("Ingresa un numero entero positivo: ");
    scanf("%i", &num);

    printf("Los divisores de %i son:\n", num);
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            printf("%i ", i);
        }
    }
    return 0;
}