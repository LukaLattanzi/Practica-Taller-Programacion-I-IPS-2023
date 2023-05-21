// 4) Pida dos números y sume todos los números comprendidos entre el primero y el segundo (inclusive). Debe controlarse que el segundo número sea mayor que el primero.

#include <stdio.h>

int main()
{
    int num1, num2;
    int suma = 0;
    printf("Ingrese el primer numero: ");
    scanf("%i", &num1);
    do
    {
        printf("Ingrese el segundo numero: ");
        scanf("%i", &num2);
    } while (num2 <= num1);
    for (int i = num1; i <= num2; i++)
    {
        suma += i;
    }
    printf("La suma de los numeros comprendidos entre %i y %i es: %i.\n", num1, num2, suma);
    return 0;
}