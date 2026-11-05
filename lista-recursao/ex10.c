#include <stdio.h>

int somaDigitosRecursiva(int n);
int somaDigitosIterativo(int n);

int main()
{
    int n = 54128;

    printf("A soma dos dígitos em %d é %d\n", n, somaDigitosIterativo(n));

    return 0;
}

int somaDigitosRecursiva(int n)
{
    if (n < 10) return n;

    return n%10 + somaDigitosRecursiva(n/10);
}

int somaDigitosIterativo(int n)
{
    int soma = 0;

    for (int i = n; n > 0; n /= 10)
    {
        soma += n%10;
    }

    return soma;
}