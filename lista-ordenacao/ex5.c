#include <stdio.h>

void ordena(int *v, int n);
void troca(int *x, int *y);

int main()
{
    int v[] = {123, 143252, 1231, 200, 500};

    ordena(v, 5);

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

void ordena(int *v, int n)
{
    int min;

    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (v[j] < v[min]) min = j; // percorre o vetor inteiro até encontrar o menor elemento e armazená-lo na variável auxiliar 'min'
        }

        troca(&v[i], &v[min]);
    }
}