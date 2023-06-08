// 16) Declarar un array A de 15 elementos enteros. Solicitar al usuario el ingreso de un valor por vez e ir colocando dicho entero en el array, donde cada elemento previo existente en el array A deba ser menor o igual y cada elemento posterior deba ser mayor al que el usuario ingresó. En cada paso mostrar el estado del array. Al finalizar deberá quedar el array ordenado de forma ascendente.

#include <stdio.h>
#define N 15

int main()
{
    // Variables ----------------------------------------------------------------------------------
    int array[N], i, j, aux;
    // Carga y Resultado ----------------------------------------------------------------------------------
    for (i = 0; i < N; i++)
    {
        printf("Ingrese Un Numero: ");
        scanf("%i", &array[i]);
        for (j = 0; j < i; j++)
        {
            if (array[i] < array[j])
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
        printf("El Array Es: ");
        for (j = 0; j <= i; j++)
        {
            printf("%i ", array[j]);
        }
        printf("\n");
    }
    // Fin ----------------------------------------------------------------------------------
    return 0;
}