// 2) El maximo entre dos enteros. #define MAX(X,Y) .....siguen uds.....

#include <stdio.h>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define NUM1 50
#define NUM2 100

int main()
{
    int numeroMayor = MAX(NUM1, NUM2);
    printf("El Mayor numero es: %i.\n", numeroMayor);
    return 0;
}