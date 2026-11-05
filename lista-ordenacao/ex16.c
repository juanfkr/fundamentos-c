#include <stdio.h>

void intercalacao(int *v1, int vt1, int *v2, int vt2, int *v_intercalado);

int main()
{
    int v1[] = {1, 2, 3, 4, 5};
    int v2[] = {6, 7, 8, 9, 10};
    int v_intercalado[10];

    intercalacao(v1, 5, v2, 5, v_intercalado);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", v_intercalado[i]);
    }

    return 0;
}

void intercalacao(int *v1, int vt1, int *v2, int vt2, int *v_intercalado)
{
    int i = 0, j = 0, k = 0;

    while (i < vt1 && j < vt2)
    {
        if(v1[i] < v2[j])
        {
            v_intercalado[k] = v1[i];
            i++;
            k++;
        } else
        {
            v_intercalado[k] = v2[j];
            j++;
            k++;
        }
    }

    while(i < vt1)
    {
        v_intercalado[k] = v1[i];
        i++;
        k++;
    }
    while (j < vt2)
    {
        v_intercalado[k] = v2[j];
        j++;
        k++;
    }
}