#include <stdio.h>
#include <string.h>

#define MAX 100

void populaVetor(int *v, int n, FILE *file);
void trocaMenorElemento(int *v, int n);

int main() 
{
    FILE *file;
    char fileName[MAX+5];
    int v[MAX], n;

    scanf(" %99s", fileName);
    strcat(fileName, ".txt");

    file = fopen(fileName, "r");

    if (file == NULL) 
    {
        return 0;
    }

    fscanf(file, " %d", &n);

    populaVetor(v, n, file);
    trocaMenorElemento(v, n);

    printf("%d\n", v[0]);

    int fechado = fclose(file);

    if (fechado == 0) 
    {
        printf("Arquivo fechado.");
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
void populaVetor(int *v, int n, FILE *file)
{
    for (int i = 0; i < n; i++) 
    {
        fscanf(file, " %d", &v[i]);
    }
}

/**
 * @brief Troca o menor elemento para primeira posição do vetor
 * @param int *v - vetor de elementos
 * @param int n - tamanho do vetor
 */
void trocaMenorElemento(int *v, int n) 
{
    int menor = *v;
    int pos_menor;
    int aux;

    for (int i = 0; i < n; i++) 
    {
        if (v[i] < menor) 
        {
            menor = v[i];
            pos_menor = i;
        }
    }

    aux = v[0];
    v[0] = v[pos_menor];
    v[pos_menor] = aux;
}