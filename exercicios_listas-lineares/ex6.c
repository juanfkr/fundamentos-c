#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insert(TNode **list, int n);
TNode *getElement(TNode *list, int n);

int main() {
    TNode *list = NULL;

    insert(&list, 5);

    TNode *node = getElement(list, 7);

    if (node == NULL) {
        printf("NULL\n");
        return 1;
    }

    printf("%d\n", node->value);

    return 0;
}

void insert(TNode **list, int n) {
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

TNode *getElement(TNode *list, int n) {
    while (list != NULL && list->value != n) {
        list = list->next;
    }

    return list;
}