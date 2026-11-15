#include <stdio.h>

#define MAX 100

int main() 
{
    // ponteiro para o arquivo de entrada
    FILE * pt_arq;
    char fileName[MAX];
    int l, c, m[MAX][MAX];

    // leia o nome do arquivo de entrada
    scanf(" %s", fileName);

    // abre o arquivo de entrada
    pt_arq = fopen(fileName, "r");


    // verifica se o arquivo de entrada foi aberto com sucesso
    if (pt_arq == NULL) {
        return 0;
    }

    // leia a dimensão da matriz
    fscanf(pt_arq, " %d %d", &l, &c);

    // leia a matriz do arquivo de entrada
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            fscanf(pt_arq, " %d", &m[i][j]);
        }
    }

    // imprime na tela a matriz lida do arquivo
    for(int i = 0; i < l; i++) 
    {
        for(int j = 0; j < c; j++) 
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }


    // fecha o arquivo de entrada
    int fechado = fclose(pt_arq);

    if (fechado == 0) 
    {
        printf("Arquivo fechado com sucesso.");
    } else 
    {
        printf("Não foi possível fechar o arquivo.");
    }

    // finaliza o programa
    return 0;
}

