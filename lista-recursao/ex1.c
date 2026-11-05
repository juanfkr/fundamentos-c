#include <stdio.h>

int fatorialIterativo(int n);
int fatorialRecursivo(int n);

int main()
{
    int n = 5;

    printf("%d! = %d", n, fatorialRecursivo(n));

    return 0;
}

int fatorialIterativo(int n)
{
    int fat = 1;

    for (int i = n; n > 0; n--)
    {
        fat *= n;
    } 
}

int fatorialRecursivo(int n)
{
    if (n == 1) return 1;

    return n * fatorialRecursivo(n-1);
}