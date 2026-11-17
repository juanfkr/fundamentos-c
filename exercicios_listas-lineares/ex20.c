#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insert(TNode **list, int n);
void remove_pares(TNode **list);
void printlist(TNode *list);

int main() {
    TNode *list = NULL;

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);

    printlist(list);

    remove_pares(&list);

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

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void remove_pares(TNode **list) {
    TNode *aux = NULL;
    TNode *p = NULL;
    TNode *q = *list;

    while (q != NULL) {
        if ((q->value % 2) == 0) {
            if (p == NULL) {
                *list = q->next;
            } else {
                p->next = q->next;
            }

            aux = q;

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