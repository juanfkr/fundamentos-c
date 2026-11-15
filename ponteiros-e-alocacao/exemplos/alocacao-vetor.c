#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[51];
    int idade;
}Cliente;


int main()
{
    Cliente *vetorClientes;

    vetorClientes = (Cliente *) malloc(5 * sizeof(Cliente));

    if (vetorClientes == NULL) return 1;

    for (Cliente *pt = vetorClientes; pt < vetorClientes+5; pt++)
    {
        scanf(" %50[^\n]", pt->nome);
        scanf(" %d", &pt->idade);
    }

    printf("Vetor: ");
    for (Cliente *pt = vetorClientes; pt < vetorClientes+5; pt++)
    {
        printf("Nome: %s \n", pt->nome);
        printf("Idade: %d, \n", pt->idade);
    }

    printf("\n");

    free(vetorClientes);

    return 0;
}