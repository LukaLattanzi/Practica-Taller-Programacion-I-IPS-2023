// 9) Pida un número por teclado y decir si es un número primo o no. Controlar que el usuario ingrese un número mayor a 0.

#include <stdio.h>

int main()
{
    int num;
    int esPrimo = 1;
    do
    {
        printf("Ingresa un numero entero positivo: ");
        scanf("%i", &num);
    } while (num < 0);
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            esPrimo = 0;
            break;
        }
    }
    if (esPrimo)
    {
        printf("%i es un numero primo.\n", num);
    }
    else
    {
        printf("%i no es un numero primo.\n", num);
    }
    return 0;
}
