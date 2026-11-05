#include <stdio.h>

void insertionSort(int *v, int n);

int main()
{
    int v[] = {123, 12, 12948, 1203913};

    insertionSort(v, 4);

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", v[i]);
    }

    return 0;
}

void insertionSort(int *v, int n)
{
    int i, j, aux;

    for (i = 1; i < n; i++)
    {
        aux = v[i];
        for (j = i-1; j >= 0 && v[j] > aux; j--)
        {
            v[j+1] = v[j];
        }

        v[j+1] = aux;
    }
}