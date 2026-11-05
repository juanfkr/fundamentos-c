#include <stdio.h>


void selectionSort(int *v, int t);
void insertionSort(int *v, int t);
void intercalacao(int *v1, int tv1, int *v2, int tv2, int *v_intercalado);
void swap(int *x, int *y);


int main()
{
    int v[] = {20, 30, 25, 35, 15};

    int v1[] = {1, 2, 3, 7, 8, 9};
    int v2[] = {4, 5, 6};
    int v_intercalado[9];

    intercalacao(v1, 6, v2, 3, v_intercalado);

    insertionSort(v, 5);

    for(int i = 0; i < 9; i++)
    {
        printf("%d ", v_intercalado[i]);
    }

    return 0;
}

void swap(int *x, int *y)
{
     int aux = *x;
     *x = *y;
     *y = aux;
}

/**
* Algoritmo de ordenação por seleção
* O método de ordenação por seleção é baseado na
idéia de escolher um menor elemento do vetor,
colocá-lo na posição correta, depois um segundo
menor elemento, colocá-lo na posição correta e
assim por diante.
*/
void selectionSort(int *v, int t)
{
    int min;

    for (int i = 0; i < t - 1; i++)
    {
        min = i;
        for (int j = i+1; j < t; j++)
        {
            if (v[j] < v[min]) min = j;
        }

        swap(&v[i], &v[min]);
    }
}

void insertionSort(int *v, int n) {
    int i, j, aux;

    for (i = 1; i < n; i++) {
        aux = v[i]; // variavel auxiliar para guardar o valor de v[i]
        for (j = i - 1; j >= 0; j--)
        {
            if (v[j] > aux)
            {
                // passa o elemento menor v[j+1] para a esquerda
                v[j+1] = v[j];
            } else 
            {
                break;
            }
                
        }

        // Se o laço interno não executar, x permanece na posição original.
        // Se executar, os elementos maiores que x são deslocados para a direita,
        // e x é inserido na posição correta.
        v[j+1] = aux;
    }
}

void intercalacao(int *v1, int tv1, int *v2, int tv2, int *v_intercalado)
{
    int i = 0; // tamanho que representa o vetor1
    int j = 0; // tamanho que representa o vetor2
    int k = 0; // tamanho que representa o vetor intercalado

    while (i < tv1 && j < tv2)
    {
        if (v1[i] <= v2[j])
        {
            v_intercalado[k] = v1[i];
            i++;
        }
        else
        {
            v_intercalado[k] = v2[j];
            j++;
        }

        k++;
    }

    while (i < tv1) // coloca o resto do vetor que sobrou no vetor intercalado
    {
        v_intercalado[k] = v1[i];
        i++;
        k++;
    }
    while (j < tv2) 
    {
        v_intercalado[k] = v2[j];
        j++;
        k++;
    }
}