#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int l, int c);
void leMatriz(int **v, int l, int c);
void imprimeMatriz(int **v, int l, int c);
void liberaMemoria(int **v, int l);

int main()
{
    int **numeros;

    numeros = alocaMatriz(2, 2);

    leMatriz(numeros, 2, 2);

    imprimeMatriz(numeros, 2, 2);

    liberaMemoria(numeros, 2);

    return 0;
}

int **alocaMatriz(int l, int c)
{
    int **v = (int **) malloc(l * sizeof(int *));

    if (v == NULL) return NULL;

    for (int i = 0; i < l; i++)
    {
        *(v+i) = (int *) malloc(c * sizeof(int));

        if (*(v+i) == NULL) return NULL;
    }

    printf("Matriz alocada com sucesso.\n");

    return v;
}

void leMatriz(int **v, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int *p = v[i]; p < v[i]+c; p++)
        {
            scanf(" %d", p);
        }
    }
}

void imprimeMatriz(int **v, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int *p = v[i]; p < v[i]+c; p++)
        {
            printf("%d ", *p);
        }
        printf("\n");
    }
}

void liberaMemoria(int **v, int l)
{
    for (int i = 0; i < l; i++)
    {
        free(*(v+i));
    }

    free(v);

    printf("Memória liberada com sucesso.");
}