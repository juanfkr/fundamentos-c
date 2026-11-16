#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insert(TNode **list, int n);
void nodeQuantity(TNode *list);

int main() {
    TNode *list = NULL;

    insert(&list, 1);
    insert(&list, 1);
    insert(&list, 1);

    nodeQuantity(list);

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

void nodeQuantity(TNode *list) {
    int count = 0;

    while (list != NULL) {
        list = list->next;
        count++;
    }

    printf("A lista possui %d nós.", count);
}