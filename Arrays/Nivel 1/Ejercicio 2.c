// 2) Declare dos arrays de 5 enteros cada uno, llamados A y B, luego en un tercer array de igual dimensión llamado S almacene la suma de los dos anteriores.

#include <stdio.h>
#define ARRAYLENGTH 5

int main()
{
    int A[ARRAYLENGTH], B[ARRAYLENGTH], S[ARRAYLENGTH], i;
    printf("Ingrese los elementos del primer array (A):\n");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("Ingrese los elementos del segundo array (B):\n");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &B[i]);
    }
    printf("La suma de los elementos de A y B es: [ ");
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        S[i] = A[i] + B[i];
        printf("%d ", S[i]);
    }
    printf("]");
    return 0;
}
