#include <stdio.h>
#include <stdlib.h>

int maior(int *v, int n);
int menor(int *v, int n);
void inserePrimeira(int *v, int *n, int x);
void insereUltima(int *v, int *n);
void imprimeVetor(int *v, int n);
void geraAleatorio(int *v, int n);

int main()
{
    int *vetor, n, maior_n, menor_n;

    scanf(" %d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    geraAleatorio(vetor, n);

    maior_n = maior(vetor, n);
    menor_n = menor(vetor, n);

    inserePrimeira(vetor, &n, 10);

    imprimeVetor(vetor, n);

    printf("Maior número: %d\n", maior_n);
    printf("Menor número: %d\n", menor_n);

    return 0;
}

void imprimeVetor(int *v, int n)
{
    for (int *pt = v; pt < (v+n); pt++)
    {
        printf("%d ", *pt);
    }
    printf("\n");
}

void geraAleatorio(int *v, int n)
{
    for (int *pt = v; pt < (v+n); pt++)
    {
        *pt = rand()%100;
    }
}

int maior(int *v, int n)
{
    int maior = *v;

    for (int *pt = v; pt < (v+n); pt++)
    {
        if (*pt > maior)
        {
            maior = *pt;
        }
    }

    return maior;
}

int menor(int *v, int n)
{
    int menor = *v;

    for (int *pt = v; pt < (v+n); pt++)
    {
        if (*pt < menor)
        {
            menor = *pt;
        }
    }

    return menor;
}

void inserePrimeira(int *v, int *n, int x)
{
    int *newDynSize = realloc(v, sizeof(((*n)+1) * sizeof(int)));
    v = newDynSize;

    for (int *pt = (v+(*n)); pt > v; pt--)
    {
        *pt = *(pt-1);
    }

    *v = x;
    *n++;
}