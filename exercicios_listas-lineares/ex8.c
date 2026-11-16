#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insere_inicio(TNode **list, int n); 

int main() {
    TNode *list = NULL;

    insere_inicio(&list, 3);
    insere_inicio(&list, 2);
    insere_inicio(&list, 1);

    TNode *current = list;

    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("NULL");

    return 0;
}

void insere_inicio(TNode **list, int n) {
    TNode *newNode = (TNode *) malloc(sizeof(TNode));

    newNode->value = n;
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
        return;
    }

    newNode->next = *list;
    *list = newNode;
}
