// 2) Muestre los números impares que hay entre 1 y 100.

#include <stdio.h>

int main()
{
    for (int i = 1; i <= 100; i += 2)
    {
        printf("%i\n", i);
    }
    return 0;
}