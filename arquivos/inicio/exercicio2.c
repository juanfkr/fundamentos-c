#include <stdio.h>

int main()
{
    int valor;
    char nome_do_arquivo[30];

    FILE *pt_arqin;

    // le nome do arquivo
    scanf(" %s", nome_do_arquivo);

    // abre arquivo
    pt_arqin = fopen(nome_do_arquivo, "r");

    // valida se foi aberto
    if (pt_arqin == NULL)
    {
        return 0;
    }

    // enquanto não estiver no final do arquivo
    while(feof(pt_arqin) == 0)
    {
        // le cada valor do arquivo
        fscanf(pt_arqin, " %d", &valor);
        printf("valor lido do arquivo %d\n", valor);
    }

    // fecha arquivo
    fclose(pt_arqin);

    return 0;
}