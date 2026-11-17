#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insert(TNode **list, int n);
int remove_ultimo(TNode **list);

int main() {
    TNode *list = NULL;

    insert(&list, 5);
    int val = remove_ultimo(&list);

    printf("%d\n", val);
    
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

int remove_ultimo(TNode **list) {
    // lista vazia
    if (*list == NULL) return 0;

    TNode *node = NULL;
    TNode *p = NULL;
    TNode *q = *list;

    int node_val;

    // remoção se: lista só tem um elemento
    if (q->next == NULL) {
        *list = NULL;
        node_val = q->value;
        free(q);
        return node_val;
    }

    while (q->next != NULL) {
        p = q;
        q = q->next;
    }
    

    // remoção do ultimo elemento
    p->next = NULL;
    node_val = q->value;
    free(q);
    return node_val;
}