// 5) Determinar si un número está entre el 0 y el 100 #define ENTRE_0_100(X) .....siguen uds.....

#include <stdio.h>
#define ENTRE_0_100(X) ((X) >= 0 && (X) <= 100)
#define NUM1 50

int main()
{
    if (ENTRE_0_100(NUM1))
    {
        printf("El numero %i esta entre el 0 y el 100.\n", NUM1);
    }
    else
    {
        printf("El numero %i no esta entre el 0 y el 100.\n", NUM1);
    }
    return 0;
}