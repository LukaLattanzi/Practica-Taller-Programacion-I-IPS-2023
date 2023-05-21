// 16) Muestre los 25 primeros números de la sucesión de Fibonacci.

#include <stdio.h>
#define CANTNUM 25

int main()
{
    int primero = 0, segundo = 1, tercero;
    printf("Sucesion de Fibonacci:\n");
    printf("%i %i ", primero, segundo);
    for (int i = 3; i <= CANTNUM; i++)
    {
        tercero = primero + segundo;
        printf("%i ", tercero);
        primero = segundo;
        segundo = tercero;
    }
    printf("\n");
    return 0;
}