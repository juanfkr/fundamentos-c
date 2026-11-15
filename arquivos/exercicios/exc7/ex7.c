#include <stdio.h>

#define MAX 100

void leArquivo(int *v, int n, FILE *file);
void ordenaVetor(int *v, int n);
void imprimeArquivo(int *v, int n, FILE *file);

/**
 * @brief Função principal
 * @param int argc - quantidade de argumentos que foi passada
 * @param char *argv - vetor contendo todos os argumentos passados
 */
int main(int argc, char *argv[]) 
{
    FILE *fileInput;
    char *fileInputName = argv[1];

    FILE *fileOutput;
    char *fileOutputName = argv[2];

    int v[MAX], n;
    
    fileInput = fopen(fileInputName, "r");

    fileOutput = fopen(fileOutputName, "w");

    fscanf(fileInput, " %d", &n);

    leArquivo(v, n, fileInput);

    ordenaVetor(v, n);

    imprimeArquivo(v, n, fileOutput);

    int ofile_closed = fclose(fileInput);
    int ifile_closed = fclose(fileOutput);

    if (ofile_closed == 0)
    {
        printf("Arquivo de entrada fechado.\n");
    } else {
        printf("Arquivo de entrada não foi fechado.\n");
    }

    if (ifile_closed == 0)
    {
        printf("Arquivo de saída fechado.\n");
    } else {
        printf("Arquivo de saída não foi fechado.\n");
    }

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
            if (v[j] > v[j+1])
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
        fprintf(file, " %d", v[i]);
    }
}