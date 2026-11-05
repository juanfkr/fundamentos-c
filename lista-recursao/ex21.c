#include <stdio.h>

int conversaoBinario(int n);

int main()
{
    int n = 13;

    printf("O equivalente binário de %d é %d", n, conversaoBinario(n));

    return 0;
}

int conversaoBinario(int n)
{
    if (n < 2) return n;

    return conversaoBinario(n / 2) * 10 + n % 2;
}