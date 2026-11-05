#include <stdio.h>

void ordenaDecrescente(int *v, int n);

int main()
{
    int v[] = {1, 2, 3, 4, 5};

    ordenaDecrescente(v, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }

    return 0;
}

// ordenação em ordem decrescente com insertion sort
void ordenaDecrescente(int *v, int n)
{
    int i, j, x;

    for (i = 1; i < n; i++)
    {
        x = v[i];
        for (j = i-1; j >= 0; j--)
        {
            if (v[j] < x)
            {
                v[j+1] = v[j]; 
            } else
            {
                break;
            }
        }
         v[j+1] = x;
    }
}