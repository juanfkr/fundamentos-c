#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insert(TNode **list, int n);
void storeValues(TNode **list);
void getList(TNode *list);

int main() {
    TNode *list = NULL;

    storeValues(&list);

    getList(list);

    return 0;
}

void insert(TNode **list, int n) {
    if (n == -1) return;

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

void storeValues(TNode **list) {
    int n;

    do {
        scanf(" %d", &n);

        insert(list, n);
    } while (n != -1);
}

void getList(TNode *list) {
    while (list != NULL) {
        printf("%d -> ", list->value);
        list = list->next;
    }

    printf("NULL");
}