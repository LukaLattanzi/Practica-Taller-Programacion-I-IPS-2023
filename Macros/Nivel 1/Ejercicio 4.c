// 4) Si un número X es divisible por otro Y (considerar Y nunca es 0) #define DIVISIBLE(X,Y) .....siguen uds.....

#include <stdio.h>
#define DIVISIBLE(X, Y) ((X) % (Y) == 0)
#define NUM1 50
#define NUM2 100 // Este numero nunca igual a 0.

int main()
{
    if (DIVISIBLE(NUM1, NUM2))
    {
        printf("El numero %i es divisible por el numero %i.\n", NUM1, NUM2);
    }
    else
    {
        printf("El numero %i no es divisible por el numero %i.\n", NUM1, NUM2);
    }
    return 0;
}