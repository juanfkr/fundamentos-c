#include <stdio.h>

void trocaMaiorElemento(int *v, int n);
void troca(int *x, int *y);

int main()
{
    int v[] = {234, 31, 20, 10, 100};

    trocaMaiorElemento(v, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }

    return 0;
}

void troca(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void trocaMaiorElemento(int *v, int n)
{
    int maior = *v;
    int pos;

    for (int i = 0; i < n; i++)
    {
        if (*(v+i) > maior)
        {
            maior = *(v+i);
            pos = i;
        }
    }

    troca(v+(n-1), v+pos);
}