// 5) Pida dos números y multiplique todos los números comprendidos entre el primero y el segundo (inclusive). Debe controlarse que el segundo número sea mayor que el primero.

#include <stdio.h>

int main()
{
    int num1, num2;
    long long int multiplicacion = 1;
    printf("Ingrese el primer numero: ");
    scanf("%i", &num1);
    do
    {
        printf("Ingrese el segundo numero: ");
        scanf("%i", &num2);
    } while (num2 <= num1);
    for (int i = num1; i <= num2; i++)
    {
        multiplicacion *= i;
    }
    printf("La multiplicacion de los numeros comprendidos entre %i y %i es: %lli.\n", num1, num2, multiplicacion);
    return 0;
}