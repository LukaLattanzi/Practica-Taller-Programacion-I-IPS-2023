// 7) Pida un número entero entre 1 y 15 (controlar esto) y muestre el mismo número de asteriscos por pantalla.

#include <stdio.h>

int main()
{
    int num;
    do
    {
        printf("Ingrese un numero entero entre 1 y 15: ");
        scanf("%i", &num);
    } while (num < 1 || num > 15);
    for (int i = 1; i <= num; i++)
    {
        printf("*");
    }
    return 0;
}