#include <stdio.h>

#define MAX 100

void populaVetor(int *v, int n, FILE * file);
int maiorElemento(int *v, int n);

int main()
{
    FILE *file;
    int v[MAX], n;
    char fileName[100];

    scanf(" %s", fileName);

    file = fopen(fileName, "r");

    if (file == NULL)
    {
        return 0;
    }

    fscanf(file, " %d", &n);

    populaVetor(v, n, file);

    int maior = maiorElemento(v, n);

    printf("maior numero: %d\n", maior);

    int isClosed = fclose(file);

    if (isClosed == 0) {
        printf("Arquivo foi fechado.\n");
    } else {
        printf("Arquivo não foi fechado.");
    }

    return 0;
}

/**
 * @brief Popula o vetor com elementos inteiros dentro de um arquivo .txt
 * @param int *v - vetor de elementos inteiros
 * @param int n - tamanho do vetor de elementos
 * @param FILE *file - arquivo contendo os elementos a serem lidos
 */
void populaVetor(int *v, int n, FILE *file) {
    for (int i = 0; i < n; i++) {
        fscanf(file, " %d", &v[i]);
    }
}

/**
 * @brief Encontra o maior elemento dentro de um array
 * @param int *v - vetor de elementos inteiros
 * @param int n - tamanho do vetor de elementos
 * @return o maior elemento de um vetor de inteiros
 */
int maiorElemento(int *v, int n) {
    int maior = *v;

    for (int i = 0; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }

    return maior;
}