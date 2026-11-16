#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insert(TNode **list, int n);
int getOccurrency(TNode *list, int n);

int main() {
    TNode *list = NULL;

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 2);

    int occurrency = getOccurrency(list, 2);

    printf("%d ocorrencias\n", occurrency);

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

int getOccurrency(TNode *list, int n) {
    int count = 0;

    while (list != NULL) {
        if (list->value == n) count++;

        list = list->next;
    }

    return count;
}