#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 151

typedef struct No {
    char nome[MAX];
    char endereco[MAX];
    struct No *prox;
} TNo;

void insere(TNo **lista, char *nome, char *endereco);
TNo *busca_e_move(TNo **lista, char *nome);
void imprime(TNo *lista);
void libera(TNo **lista);

int main() {
    TNo *lista = NULL;
    char nome[MAX], endereco[MAX], chave[MAX];

    do {
        scanf("%s", nome);

        if(strcmp(nome, "0") == 0) {
            break;
        }

        scanf("%s", endereco);

        insere(&lista, nome, endereco);
    } while (true);

    printf("Lista armazenada antes da busca\n");
    imprime(lista);

    scanf(" %s", chave);
    printf("\nChave de Busca\n%s\n", chave);

    TNo *elemento = busca_e_move(&lista, chave);

    if (elemento == NULL) {
        printf("\nSite nao encontrado!\n");

        printf("\nLista armazenada depois da busca\n");
        imprime(lista);
    } else {
        printf("\nEndereco Buscado\n%s\n", elemento->endereco);

        printf("\nLista armazenada depois da busca\n");
        imprime(lista);
    }

    libera(&lista);

    return 0;
}

void insere(TNo **lista, char *nome, char *endereco) {
    TNo *novoNo = (TNo *) malloc(sizeof(TNo));

    strcpy(novoNo->nome, nome);
    strcpy(novoNo->endereco, endereco);
    novoNo->prox = NULL;

    if (*lista == NULL) {
        *lista = novoNo;
    } else {
        TNo *p = *lista;

        while (p->prox != NULL) {
            p = p->prox;
        }

        p->prox = novoNo;
    }
}

TNo *busca_e_move(TNo **lista, char *nome) {
    TNo *p, *q;

    p = NULL;
    q = *lista;

    while (q != NULL && (strcmp(nome, q->nome) != 0)) {
        p = q;
        q = q->prox;
    }

    // elemento nao encontrado
    if (q == NULL) return NULL;

    // elemento é o primeiro da lista, não precisa ser movido
    if (p == NULL) return q;
 
    // aponta o elemento anterior para o elemento sucessor do elemento encontrado
    p->prox = q->prox;

    // aponta o elemento encontrado para o primeiro da lista e aponta a lista para o elemento encontrado
    q->prox = *lista;
    *lista = q;

    return q;
}

void imprime(TNo *lista) {
    while (lista != NULL) {
        printf("%s %s\n", lista->nome, lista->endereco);

        lista = lista->prox;
    }
}

void libera(TNo **lista) {
    TNo *aux;

    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
}