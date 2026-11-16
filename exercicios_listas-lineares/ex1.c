#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void insert(TNode **list, int n);
void getList(TNode *list);
void store_n_values(TNode **list, int qtd);

int main() {
    TNode *list = NULL;

    store_n_values(&list, 5);

    getList(list);

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

void getList(TNode *list) {
    while(list != NULL) {
        printf("%d -> ", list->value);
        list = list->next;
    }

    printf("NULL");
}

void store_n_values(TNode **list, int qtd) {
    for (int i = 0; i < qtd; i++) {
        int n;
        scanf(" %d", &n);

        insert(list, n);
    }
}