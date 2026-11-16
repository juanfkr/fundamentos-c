#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insere_fim(TNode **list, int n);

int main() {
    TNode *list = NULL;

    insere_fim(&list, 1);
    insere_fim(&list, 2);
    insere_fim(&list, 3);

    TNode *current = list;

    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("NULL");

    return 0;
}

void insere_fim(TNode **list, int n) {
    TNode *newNode = (TNode *) malloc(sizeof(TNode));

    newNode->value = n;
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
        return;
    }

    TNode *current = *list;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}