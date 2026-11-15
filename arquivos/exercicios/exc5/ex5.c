#include <stdio.h>
#include <string.h>

#define MAX 100

void populaVetor(int *v, int n, FILE *file);
void trocaMaiorElemento(int *v, int n);

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
    trocaMaiorElemento(v, n);

    printf("%d\n", v[n-1]);

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
 * @brief Troca o maior elemento do vetor para a ultima posição
 * @param int *v - vetor de elementos inteiros
 * @param int n - tamanho do vetor
 */
void trocaMaiorElemento(int *v, int n) 
{
    int maior = 0;
    int pos_maior;
    int aux;

    for (int i = 0; i < n; i++) 
    {
        if (v[i] > maior) 
        {
            maior = v[i];
            pos_maior = i;
        }
    }

    aux = v[n-1];
    v[n-1] = v[pos_maior];
    v[pos_maior] = aux;
}