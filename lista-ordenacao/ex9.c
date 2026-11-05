#include <stdio.h>

void ordenacaoBolha(int *v, int n);
void troca(int *x, int *y);

int main()
{
    int v[] = {1, 2, 3, 4, 5};

    ordenacaoBolha(v, 5);
    
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

void ordenacaoBolha(int *v, int n)
{
    int aux;

    for (int *pti = (v+n)-1; pti >= v; pti--)
    {
        for (int *ptj = v; ptj < pti; ptj++)
        {
            if (*ptj < *(ptj+1))
            {
                troca(ptj, ptj+1);
            }
        }
    }
}