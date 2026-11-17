#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insert(TNode **list, int n);
void remove_first(TNode **list);
TNode *getFirst(TNode *list);
void printlist(TNode *list);

int main() {
    TNode *list = NULL;

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);

    remove_first(&list);

    printlist(list);

    remove_first(&list);

    printlist(list);

    remove_first(&list);

    printlist(list);
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

void remove_first(TNode **list) {
    if (*list == NULL) return;

    TNode *aux = *list;

    *list = (*list)->next;

    free(aux);
}

TNode *getFirst(TNode *list) {
    return list;
}

void printlist(TNode *list) {
    while (list != NULL) {
        printf("%d -> ", list->value);
        list = list->next;
    }

    printf("NULL\n");
}