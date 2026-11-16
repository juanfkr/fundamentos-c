#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
}TNode;

void printList(TNode *list);

int main() {

}

void printList(TNode *list) {
    while (list != NULL) {
        printf("%d -> ", list->value);
        list = list->next;
    }

    printf("NULL");
}