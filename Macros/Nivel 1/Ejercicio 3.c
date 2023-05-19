// 3) Si un número es par o impar #define PAR(X) .....siguen uds.....

#include <stdio.h>
#define PAR(X) ((X) % 2 == 0)
#define NUM1 50

int main()
{
    if (PAR(NUM1))
    {
        printf("El numero %i es par.\n", NUM1);
    }
    else
    {
        printf("El numero %i es impar.\n", NUM1);
    }
    return 0;
}