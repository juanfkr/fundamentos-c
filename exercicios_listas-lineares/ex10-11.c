#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insere_antes(TNode **list, int x, int y);
void insere_depois(TNode **list, int x, int y);

int main() {
    TNode *list = NULL;

    //insere_antes(&list, 1, 10);
    //insere_antes(&list, 2, 7);
    //insere_antes(&list, 5, 2);

    insere_depois(&list, 7, 2);
    insere_depois(&list, 5, 7);
    insere_depois(&list, 10, 20);

    TNode *current = list;

    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("NULL");

    return 0;
}

void insere_antes(TNode **list, int x, int y) {
    TNode *newNode = (TNode *) malloc(sizeof(TNode));

    newNode->value = x;
    newNode->next = NULL;

    // lista está vazia: insere o primeiro elemento
    if (*list == NULL) {
        *list = newNode;
        return;
    } 

    TNode *p = NULL;
    TNode *q = *list;

    while(q != NULL && q->value != y) {
        p = q;
        q = q->next;
    }

    // elemento y é o primeiro da lista: insere no começo e faz lista apontar para o novo elemento, e o novo para o antigo primeiro
    if (p == NULL) {
        newNode->next = *list;
        *list = newNode;
        return;
    }

    // elemento y não existe na lista: insere no final
    if (q == NULL) {
        p->next = newNode;
        return;
    }

    // elemento y existe: insere antes do elemento y
    newNode->next = q;
    p->next = newNode;
}


void insere_depois(TNode **list, int x, int y) {
    TNode *newNode = malloc(sizeof(TNode));

    if (newNode == NULL) {
        return;
    }

    newNode->value = x;
    newNode->next = NULL;

    // lista vazia
    if (*list == NULL) {
        *list = newNode;
        return;
    }

    TNode *p = NULL;
    TNode *q = *list;

    // busca pelo elemento y
    while (q != NULL && q->value != y) {
        p = q;
        q = q->next;
    }

    // elemento y não encontrado: insere no final
    if (q == NULL) {
        p->next = newNode;
        return;
    }

    // elemento y encontrado: insere depois dele
    newNode->next = q->next;
    q->next = newNode;
}