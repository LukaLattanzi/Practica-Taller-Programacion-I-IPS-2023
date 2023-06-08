// 12) Dado un array A de N enteros cargados manualmente o bien de forma automática y un número entero r en el rango [-(N-1), N-1]. El valor r impondrá rotaciones a derecha (en caso de r positivo) o rotaciones a izquierda (en caso de r negativo) sobre los elementos del array A. Una rotación es el cambio de posición en los elementos del array. Ejemplo, un array A con N valiendo 10, r estará comprendido en [-9, 9]. Es decir, dado el array A= [ 45, 11, -5, 80, 6, 99, 105, -200, 22, 1], Si r= 1 ⇒ A= [ 1, 45, 11, -5, 80, 6, 99, 105, -200, 22 ] Todos los elementos rotaron 1 posición a la derecha Si r=-3 ⇒ A= [ -5, 80, 6, 99, 105, -200, 22, 1, 45, 11 ] Todos los elementos rotaron 3 posiciones a la izquierda.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define LENGTH 10

int main()
{
    // Variables ----------------------------------------------------------------------------------
    srand(getpid());
    int arrayA[LENGTH], pivote, movimientos, i, j;
    // Carga A ----------------------------------------------------------------------------------
    printf("El Array Base Es [ ");
    for (int i = 0; i < LENGTH; i++)
    {
        arrayA[i] = rand();
        printf("%i ", arrayA[i]);
    }
    printf("]\n");
    // Cargar Movimientos ----------------------------------------------------------------------------------
    do
    {
        printf("Ingrese La Cantidad De Movimientos A Realizar (De -%i a %i): ", LENGTH - 1, LENGTH - 1);
        scanf("%i", &movimientos);
    } while (movimientos < -(LENGTH - 1) || movimientos > LENGTH - 1);
    printf("Escojio Desplazarse %i Lugares\n", movimientos);
    // Realizar Movimientos ----------------------------------------------------------------------------------
    if (movimientos > 0)
    {
        for (i = 0; i < movimientos; i++)
        {
            pivote = arrayA[LENGTH - 1];
            for (j = LENGTH - 1; j > 0; j--)
            {
                arrayA[j] = arrayA[j - 1];
            }
            arrayA[0] = pivote;
        }
    }
    else
    {
        for (i = 0; i > movimientos; i--)
        {
            pivote = arrayA[0];
            for (j = 0; j < LENGTH - 1; j++)
            {
                arrayA[j] = arrayA[j + 1];
            }
            arrayA[LENGTH - 1] = pivote;
        }
    }
    // Resultados ----------------------------------------------------------------------------------
    printf("El Array Desplazado Es [ ");
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%i ", arrayA[i]);
    }
    printf("]\n");
    // Fin ----------------------------------------------------------------------------------
    return 0;
}
