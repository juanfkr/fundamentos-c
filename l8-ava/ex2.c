#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int value;
    struct No *prox;
} TNo;

void insere(TNo **lista, int n);
void Ponteiros_Para_Remocao(TNo **lista, int x, TNo **p, TNo **q);
void imprime(TNo *lista);
void liberaLista(TNo **lista);

int main() {
    TNo *lista = NULL;
    TNo *p = NULL, *q = NULL;
    int n, k;

    do {
        scanf(" %d", &n);
        if (n == 0) break;
        insere(&lista, n);
    } while (n != 0);

    imprime(lista);

    scanf(" %d", &k);
    
    printf("\n");

    Ponteiros_Para_Remocao(&lista, k, &p, &q);

    liberaLista(&lista);

    return 0;
}

void insere(TNo **lista, int n) {
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

void Ponteiros_Para_Remocao(TNo **lista, int n, TNo **p, TNo **q) {
    *p = NULL;
    *q = *lista;

    while (*q != NULL && (*q)->value != n) {
        *p = *q;
        *q = (*q)->prox;
    }

    if (*q == NULL) {
        printf("%d não existe na lista\n", n);
        return;
    }

    if ((*q)->value == 1) {
        printf("O nó a ser removido é o primeiro da lista");
        return;
    }

    if ((*q)->value == n) {
        printf("O nó cuja chave é %d precede o nó a ser removido\n", (*p)->value);
    }
}

void imprime(TNo *lista) {
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