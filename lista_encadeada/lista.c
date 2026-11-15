#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *proximo;
} TNode;

void insereNode(TNode **lista, int x);
void imprimeLista(TNode *lista);
TNode *busca(TNode *lista, int x);
void removeNode(TNode **lista, int x);

int main() {
    // lista headless
    TNode *lista = NULL;

    insereNode(&lista, 15);
    insereNode(&lista, 35);
    insereNode(&lista, 10);
    insereNode(&lista, 50);

    imprimeLista(lista);

    TNode *num = busca(lista, 10);

    if (num == NULL) {
        printf("O número não existe na lista.");
    } else {
        printf("O número foi encontrado, e é o %d\n", num->valor);
    }

    removeNode(&lista, num->valor);

    imprimeLista(lista);

    return 0;
}

void imprimeLista(TNode *lista) {
    for (TNode *atual = lista; atual != NULL; atual = atual->proximo) {
        printf("%d -> ", atual->valor);
    }

    printf("NULL\n");
}

TNode *busca(TNode *lista, int x) {
    if (lista == NULL) return NULL;

    if (x == lista->valor) return lista;

    return busca(lista->proximo, x);
}

void insereNode(TNode **lista, int x) {
    TNode *novoNode = (TNode *) malloc(sizeof(TNode));

    novoNode->valor = x;
    novoNode->proximo = NULL;

    // se a lista estiver vazia, lista passa a apontar para o novo nó (novo primeiro elemento)
    if (*lista == NULL) {
        *lista = novoNode;
    } else { // senão, percorre até o final e faz o antigo ultimo nó apontar para o novo (atual ultimo)
        TNode *p = *lista;

        while (p->proximo != NULL) {
            p = p->proximo;
        }

        p->proximo = novoNode;
    }
}

void removeNode(TNode **lista, int x) {
    TNode *p, *q;

    p = NULL;
    q = *lista;

    while (q != NULL && q->valor != x) {
        p = q;
        q = q->proximo;
    }

    if (q == NULL) return;

    if (p != NULL) {
        p->proximo = q->proximo;
    } else {
        *lista = q->proximo;
    }

    printf("Número %d removido\n", q->valor);

    free(q);
}