// 13) Muestre el abecedario por pantalla.

#include <stdio.h>

int main()
{
    char letra;
    printf("Abecedario:\n");
    for (letra = 'A'; letra <= 'Z'; letra++)
    {
        printf("%c ", letra);
    }
    printf("\n");
    return 0;
}