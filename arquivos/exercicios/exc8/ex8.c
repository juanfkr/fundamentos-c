#include <stdio.h>

#define MAX 100

void leArquivo(int *v, int n, FILE *file);
void ordenaVetor(int *v, int n);
void imprimeArquivo(int *v, int n, FILE *file);

int main(int argc, char *argv[]) 
{
    FILE *inputFile;
    char *inputFileName = argv[1];

    FILE *outputFile;
    char *outputFileName = "ORDENADO.txt";

    int v[MAX], n;

    inputFile = fopen(inputFileName, "r");

    outputFile = fopen(outputFileName, "w");

    fscanf(inputFile, " %d", &n);

    leArquivo(v, n, inputFile);

    ordenaVetor(v, n);

    imprimeArquivo(v, n, outputFile);
    printf("O arquivo foi salvo em %s\n", outputFileName);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

/**
 * @brief Lê os elementos inteiros de um arquivo para dentro de um vetor
 * @param int *v - vetor de elementos inteiros
 * @param int n - tamanho do vetor
 * @param FILE *file - arquivo a ser lido
 */
void leArquivo(int *v, int n, FILE *file)
{
    for (int i = 0; i < n; i++)
    {
        fscanf(file, " %d", &v[i]);
    }
}

/**
 * @brief Ordenda o vetor em ordem crescente utilizando o algoritmo Bubble Sort
 * @param int *v - vetor de elementos inteiros
 * @param int n - tamanho do vetor
 */
void ordenaVetor(int *v, int n)
{
    int aux;

    for (int i = n-1; i >= 0; i--) 
    {
        for (int j = 0; j < i; j++)
        {
            if(v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

/**
 * @brief Armazena um vetor em um arquivo
 * @param int *v - vetor de elementos inteiros
 * @param int n - tamanho do vetor
 * @param FILE *file - arquivo a ser escrito
 */
void imprimeArquivo(int *v, int n, FILE *file)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d", v[i]);
    }
}