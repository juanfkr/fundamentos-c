#include <stdio.h>

int potenciaRecursiva(int x, int n);

int main()
{
    int n = 2, x = 4;

    printf("%d^%d=%d", x, n, potenciaRecursiva(x, n));
    return 0;
}

int potenciaRecursiva(int x, int n)
{
    if (n == 0) return 1;

    return x * potenciaRecursiva(x, n-1);
}