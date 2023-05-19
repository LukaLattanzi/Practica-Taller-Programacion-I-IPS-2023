// 6) Determinar si dos números son consecutivos #define CONSECUTIVOS(X,Y) .....siguen uds.....

#include <stdio.h>
#define CONSECUTIVOS(X,Y) ((X) + 1 == (Y))
#define NUM1 50
#define NUM2 100

int main()
{
    if (CONSECUTIVOS(NUM1,NUM2))
    {
        printf("El numero %i es consecutivo de %i.\n", NUM2, NUM1);
    }
    else
    {
        printf("El numero %i no es consecutivo de %i.\n", NUM2, NUM1);
    }
    return 0;
}