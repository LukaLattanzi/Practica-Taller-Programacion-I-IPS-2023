// 12) Reciba tres enteros positivos n, p y m, asegurándose que n<m - genere la salida n, n+p, n+2.p, n+3.p, …. k (k<=m y es de la forma n+NRO.p) Ejemplo n=2, p=3, m=10, debe generarse: 2, 5, 8 Ejemplo n=1, p=4, m=21, debe generarse 1,5,9,13,17,21

#include <stdio.h>

int main()
{
    int n, p, m;
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);
    printf("Ingrese el valor de p: ");
    scanf("%d", &p);
    printf("Ingrese el valor de m: ");
    scanf("%d", &m);
    if (n >= m)
    {
        printf("El valor de n debe ser menor que m.\n");
        return 0;
    }
    int k = n;
    while (k <= m)
    {
        printf("%d ", k);
        k += p;
    }
    printf("\n");
    return 0;
}