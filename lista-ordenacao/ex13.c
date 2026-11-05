#include <stdio.h>

void ordenaSelection(int *v, int n);
void troca(int *x, int *y);

int main()
{
    int v[] = {5, 4, 3, 2, 1};

    ordenaSelection(v, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ",  v[i]);
    }

    return 0;
}

void troca(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void ordenaSelection(int *v, int n)
{
    int min;

    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (v[j] > v[min]) min = j;
        }

        troca(&v[i], &v[min]);
    }
}