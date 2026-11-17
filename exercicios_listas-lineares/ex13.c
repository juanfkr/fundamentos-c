#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insere_ordenado(TNode **list, int n);

int main() {
    TNode *list = NULL;

    insere_ordenado(&list, 10);
    insere_ordenado(&list, 5);
    insere_ordenado(&list, 2);
    insere_ordenado(&list, 100);

    TNode *current = list;
    
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("NULL");
}

void insere_ordenado(TNode **list, int n) {
    TNode *newNode = (TNode *) malloc(sizeof(TNode));

    newNode->value = n;
    newNode->next = NULL;

    // lista vazia
    if (*list == NULL) {
        *list = newNode;
        return;
    }

    TNode *p = NULL;
    TNode *q = *list;

    // percorre enquanto encontrar valores menores que n
    while (q != NULL && q->value > n) {
        p = q;
        q = q->next;
    }

    // insere no início
    if (p == NULL) {
        newNode->next = *list;
        *list = newNode;
        return;
    }

    // insere de forma ordenada
    newNode->next = q;
    p->next = newNode;


}