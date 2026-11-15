
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

void Empilha(TNo **pilha, int n);
void DesempilhaTudo(TNo **pilha);

int main() {
    TNo *pilha = NULL;
    int n;

    scanf("%d", &n);

    int decimal = n;

    while (n > 0) {
        Empilha(&pilha, n % 2);
        n = n / 2;
    }

    printf("Valor decimal = %d\n", decimal);
    printf("Valor binário = ");

    DesempilhaTudo(&pilha);

    return 0;
}

void Empilha(TNo **pilha, int n) {
    TNo *novoNo = (TNo *) malloc(sizeof(TNo));

    novoNo->valor = n;
    novoNo->prox = *pilha;

    *pilha = novoNo;
}

void DesempilhaTudo(TNo **pilha) {
    TNo *aux;

    while (*pilha != NULL) {
        aux = *pilha;

        printf("%d", aux->valor);

        *pilha = (*pilha)->prox;

        free(aux);
    }

    printf("\n");
}
