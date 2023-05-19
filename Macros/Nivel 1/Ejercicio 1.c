// 1) El minimo entre dos enteros. #define MIN(X,Y) .....siguen uds.....

#include <stdio.h>
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define NUM1 50
#define NUM2 100

int main()
{
    int numeroMenor = MIN(NUM1, NUM2);
    printf("El menor numero es: %i.\n", numeroMenor);
    return 0;
}