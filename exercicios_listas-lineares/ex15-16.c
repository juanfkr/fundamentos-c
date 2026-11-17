#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insert(TNode **list, int n);
void pop(TNode **list, int n);
void popAll(TNode **list, int n);
void printlist(TNode *list);

int main() {
    TNode *list = NULL;

    insert(&list, 5);
    insert(&list, 10);
    insert(&list, 15);
    insert(&list, 15);
    insert(&list, 15);
    insert(&list, 15);
    insert(&list, 20);

    printlist(list);

    pop(&list, 20);

    printlist(list);

    popAll(&list, 15);

    printlist(list);

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

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void pop(TNode **list, int n) {
    // lista vazia
    if (*list == NULL) return;

    TNode *p = NULL;
    TNode *q = *list;

    while (q != NULL && q->value != n) {
        p = q;
        q = q->next;
    }

    // elemento não encontrado
    if (q == NULL) return;

    // n é o primeiro elemento
    if (p == NULL) {
        *list = q->next;
        free(q);
        return;
    }

    p->next = q->next;
    free(q);

    printf("Elemento removido\n");
}

void popAll(TNode **list, int n) {
    TNode *p = NULL;
    TNode *q = *list;

    while (q != NULL) {

        if (q->value == n) {

            if (p == NULL) {
                *list = q->next;
            } else {
                p->next = q->next;
            }

            TNode *aux = q;
            q = q->next;

            free(aux);

        } else {
            p = q;
            q = q->next;
        }
    }
}

void printlist(TNode *list) {
    while (list != NULL) {
        printf("%d -> ", list->value);
        list = list->next;
    }
    
    printf("NULL\n");
}