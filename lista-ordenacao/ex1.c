#include <stdio.h>

int maiorElemento(int *v, int n);
int maiorElementoRecursivo(int *v, int n);

int main()
{
    int v[] = {1, 2, 3232, 4, 5};

    printf("O maior elemento do vetor é o número: %d\n", maiorElemento(v, 5));

    return 0;
}

int maiorElemento(int *v, int n) 
{
    int maior = *v;

    for (int i = 0; i < n; i++)
    {
        if (*(v+i) > maior)
        {
            maior = *(v+i);
        }
    }

    return maior;
}
