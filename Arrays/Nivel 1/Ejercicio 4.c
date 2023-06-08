// 4) Declare un array A de N numeros, se realice la carga manual y pida al usuario un float f en el rango (0, 100] y en un nuevo array P establezca los elementos de esta forma. Cada elemento P[i] debe ser de la forma A[i]*f para i=0...N-1.

#include <stdio.h>
#define N 5

int main()
{
    float A[N], f, P[N];
    int i;
    printf("Ingrese los elementos del array A:\n");
    for (i = 0; i < N; i++)
    {
        printf("Elemento %i: ", i + 1);
        scanf("%f", &A[i]);
    }
    do
    {
        printf("Ingrese un float f en el rango (0, 100]: ");
        scanf("%f", &f);
    } while (f <= 0 || f > 100);
    for (i = 0; i < N; i++)
    {
        P[i] = A[i] * f;
    }
    printf("Array P: [ ");
    for (i = 0; i < N; i++)
    {
        printf("%.2f ", P[i]);
    }
    printf("]");
    return 0;
}
