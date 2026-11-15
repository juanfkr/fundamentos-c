#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void ordenaVetor(int *v, int n);

/**
 * @brief função principal
 * @param int argc - quantidade de argumentos
 * @param char *argv[] - vetor contendo todos os argumentos de execução
 */
int main(int argc, char *argv[]) // o primeiro argumento é sempre a comando de execução do arquivo compilado, 
                                 //ex: ./ex6 -> primeiro arg
{
    FILE *file;
    char *fileName = argv[1];
    int v[MAX], n;

    file = fopen(fileName, "r");

    fscanf(file, " %d", &n);

    for (int i = 0; i < n; i++) 
    {
        fscanf(file, " %d", &v[i]);
    }

    ordenaVetor(v, n);

    for (int i = 0; i < n; i++) 
    {
        printf(" %d ", v[i]);
    }

    int closed = fclose(file);

    if (closed == 0) 
    {
        printf("Fechado com sucesso");
    } else 
    {
        printf("Arquivo não foi fechado");
    }

    return 0;
}

/**
 * @brief Ordena o vetor em ordem crescente utilizando o algoritmo de Bubble Sort
 * @param int *v - vetor de elementos inteiros
 * @param int n - tamanho do vetor
 */
void ordenaVetor(int *v, int n)
{
    int aux;

    for (int i = n - 1; i >= 0; i--) 
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}