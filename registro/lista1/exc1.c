#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    int codigo;
    char descricao[MAX + 1];
    float preco;
} Produto;

void defineProdutos(Produto *produtos, int n_produtos);
void exibeProdutos(Produto produtos[], int n_produtos);
void ordenaProdutos(Produto *produtos, int n_produtos);
void buscaProduto(Produto produtos[], int n_produtos, int codigo_produto);

int main()
{
    // variaveis
    Produto produtos[MAX];
    int n_produtos = 50;
    int codigo_produto = 1003;

    // lê e armazena n produtos
    defineProdutos(produtos, n_produtos);

    // organiza vetor de produtos
    ordenaProdutos(produtos, n_produtos);

    // exibe produtos
    exibeProdutos(produtos, n_produtos);

    // busca um produto x
    buscaProduto(produtos, n_produtos, codigo_produto);

    return 0;
}

void defineProdutos(Produto *produtos, int n_produtos)
{
    for (int i = 0; i < n_produtos; i++)
    {
        scanf(" %d", &produtos[i].codigo);
        scanf(" %[^\n]", produtos[i].descricao);
        scanf(" %f", &produtos[i].preco);
    }
}

void exibeProdutos(Produto produtos[], int n_produtos)
{
    for (int i = 0; i < n_produtos; i++)
    {
        printf("=====================\n");
        printf("Código: %d\n", produtos[i].codigo);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Preço: R$%.2f \n", produtos[i].preco);
    }
}

void ordenaProdutos(Produto *produtos, int n_produtos)
{
    Produto aux;
    for (int i = n_produtos - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (produtos[j].codigo > produtos[j + 1].codigo)
            {
                aux = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = aux;
            }
        }
    }
}

void buscaProduto(Produto produtos[], int n_produtos, int codigo_produto)
{
    int inicio = 0;
    int meio;
    int fim = n_produtos - 1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (produtos[meio].codigo == codigo_produto)
        {
            printf("Produto encontrado!\n");
            printf("Código: %d", produtos[meio].codigo);
            printf("Código: %s", produtos[meio].descricao);
            printf("Código: %.2f", produtos[meio].preco);
            return;
        }

        if (codigo_produto > produtos[meio].codigo)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    printf("O produto não foi encontrado!");
    return;
}