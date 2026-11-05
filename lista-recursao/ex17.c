#include <stdio.h>

int maiorElementoRecursivo(int *v, int n);
int maiorElementoIterativo(int *v, int n);

int main()
{
    int n = 5;
    int v[] = {1, 2, 3, 4, 5};

    printf("O maior elemento do vetor é %d", maiorElementoRecursivo(v, n));

    return 0;
}

int maiorElementoRecursivo(int *v, int n)
{
    if (n == 1) return v[0];
    
    int maior = maiorElementoRecursivo(v, n-1);

    if (maior > v[n-1]) return maior;

    return v[n-1];
}

int maiorElementoIterativo(int *v, int n)
{
    int maior = *v;

    for (int i = 0; i < n; i++)
    {
        if(v[i] > maior)
        {
            maior = v[i];
        }
    }

    return maior;
}