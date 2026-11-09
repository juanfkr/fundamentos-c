#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *novoNode();
void imprimeLista(Node *head);

int main() {
    // Cria um Node:
    Node *head;
    int n = 5;

    // Aloca memória para o Node:
    head = novoNode();

    if (!head) {
        printf("Erro na alocação de memória.");
        return 1;
    }


    Node *current = head;

    while (n > 0)
    {
        current->val = n;

        if (n == 1)
        {
            current->next = NULL;
            break;
        }

        current->next = novoNode();

        current = current->next;

        n--;
    }

    current->next = novoNode();
    current->next->val = 15132;
    current->next->next = NULL;
    current = head;

    imprimeLista(head);

    return 0;
}

void imprimeLista(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }

    printf("NULL\n");
}

Node *novoNode() {
    return (Node *) malloc(sizeof(Node));
}