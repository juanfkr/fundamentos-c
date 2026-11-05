#include <stdio.h>

int buscaBinaria(int *v, int n, int x);
int buscaBinariaRecursiva(int *v, int inicio, int fim, int x);

int main()
{
    int v[] = {1, 2, 3, 4, 5};

    int achou = buscaBinariaRecursiva(v, 0, 5, 3);

    printf("%d", achou);

    return 0;
}

int buscaBinaria(int *v, int n, int x)
{
    int inicio = 0;
    int fim = n-1;
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio+fim)/2;

        if (x == v[meio]) return v[meio];

        if (x > v[meio]) 
        {
            inicio = meio+1;
        } else
        {
            fim = meio-1;
        }
    }

    return -1;
}

int buscaBinariaRecursiva(int *v, int inicio, int fim, int x)
{
    if (inicio > fim) return -1;

    int meio = (inicio+fim)/2;

    if (x == v[meio]) return v[meio];

    if (x > v[meio]) return buscaBinariaRecursiva(v, meio+1, fim, x);

    return buscaBinariaRecursiva(v, inicio, meio-1, x);
}