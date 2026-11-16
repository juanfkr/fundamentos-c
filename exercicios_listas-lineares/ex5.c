#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insert(TNode **list, int n);
char *getElement(TNode *list, int n);

int main() {
    TNode *list = NULL;

    insert(&list, 1);

    char *achou = getElement(list, 1);

    printf("%s\n", achou);
    
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

char *getElement(TNode *list, int n) {
    while (list != NULL) {
        if (list->value == n) return "SIM";

        list = list->next;
    }

    return "NAO";
}