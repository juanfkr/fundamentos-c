#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int value;
    struct No *prox;
} TNo;

void insere(TNo **lista, int n);
void removeNo(TNo **lista, int n);
void imprime(TNo *lista);
void liberaLista(TNo **lista);

int main() {
    TNo *lista = NULL;
    int n, k;

    do {
        scanf(" %d", &n);
        if (n == 0) break;
        insere(&lista, n);
    } while (n != 0);

    imprime(lista);

    scanf(" %d", &k);

    removeNo(&lista, k);

    printf("Lista após a remoção\n");

    imprime(lista);

    liberaLista(&lista);

    return 0;
}

void insere(TNo **lista, int n) {
    if (n == 0) return;

    TNo *novoNo = (TNo *) malloc(sizeof(TNo));

    novoNo->value = n;
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

void removeNo(TNo **lista, int n) {
    TNo *i, *j;

    i = NULL;
    j = *lista;

    while (j != NULL && j->value != n) {
        i = j;
        j = j->prox;
    }

    if (j == NULL) {
        printf("Elemento %d nao encontrado!\n", n);
        return;

    }

    if (i == NULL) {
        *lista = j->prox;
    } else {
        i->prox = j->prox;
    }

    free(j);
}

void imprime(TNo *lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
    }

    while (lista != NULL) {
        if (lista->prox != NULL) {
            printf("%d --> ", lista->value);
        } else {
            printf("%d\n", lista->value);
        }

        lista = lista->prox;

    }
}

void liberaLista(TNo **lista) {
    TNo *aux;

    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
}