// 7) Determinar el máximo entre tres enteros #define MAX(X,Y,Z) .....siguen uds.....

#include <stdio.h>
#define MAX(X, Y, Z) (((X) > (Y)) ? ((X) > (Z) ? (X) : (Z)) : ((Y) > (Z) ? (Y) : (Z)))
#define NUM1 50
#define NUM2 100
#define NUM3 150

int main()
{
    int numeroMayor = MAX(NUM1, NUM2,NUM3);
    printf("El Mayor numero es: %i.\n", numeroMayor);
    return 0;
}