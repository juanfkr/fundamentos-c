#include <stdio.h>

int somaInteirosRecursiva(int n);
int somaInteirosIterativa(int n);


int main()
{
    int n = 7;

    printf("A soma dos inteiros de 1 até %d é %d", n, somaInteirosRecursiva(n));

    /**
    relação de recorrencia:
              {                             }
    soma(n) = { 1        , se n = 1         }
              { soma(n-1), caso o contrário }
              {                             }
    */

    return 0;
}

int somaInteirosRecursiva(int n)
{
    if (n == 1) return 1;

    return n + somaInteirosRecursiva(n-1);
}

int somaInteirosIterativa(int n)
{
    int soma = 0;

    for (int i = n; i > 0; i--)
    {
        soma += i;
    }

    return soma;
}