#include <stdio.h>

int menorElemento(int *v, int n);

int main()
{
    int v[] = {1, 2, 3, 4, 5};

    printf("O menor elemento do vetor é o número: %d\n", menorElemento(v, 5));
    return 0;
}

int menorElemento(int *v, int n)
{
    int menor = *v;

    for (int i = 0; i < n; i++)
    {
        if (*(v+i) < menor)
        {
            menor = *(v+i);
        }
    }

    return menor;
}