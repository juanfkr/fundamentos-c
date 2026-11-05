#include <stdio.h>

void selectionSort(int *v, int n);
void swap(int *x, int *y);


int main()
{
    int v[5] = {123, 54234, 1, 0, 240};

    selectionSort(v, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }

    return 0;
}

void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

// escolhe um elemento e compara com o resto à direita
void selectionSort(int *v, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min = i;

        for (int j = i+1; j < n; j++)
        {
            if (v[j] < v[min]) min = j;
        }

        swap(&v[i], &v[min]);
    }
}