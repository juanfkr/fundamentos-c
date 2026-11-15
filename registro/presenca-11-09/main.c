#include <stdio.h>

#define MAX 20

typedef struct
{
    // um tipo int não suporta o tamanho de um RGA
    // utiliza-se: long long (8 bytes de largura)
    long long rga;
    char nome[50];
    float media;
} Aluno;

void menu();

void defineAlunos(Aluno *turma, int n);
void imprimeTurma(Aluno *turma, int n);
void ordenaTurma(Aluno *turma, int n);
int buscaAluno(Aluno *turma, int n, long long rga);
void alunosAcimaDaMedia(Aluno *turma, int n);
void imprimeAlunosAcimaDaMedia(Aluno *turma, int n);
void insereAluno(Aluno *turma, int *n);

int main()
{
    Aluno turma[MAX];
    int qtdAlunos, opcaoMenu;
    long long rga_aluno;

    scanf(" %d", &qtdAlunos);

    // encerra o programa se a qtd. de alunos NÃO atende o número min. e max. de alunos
    if (!(qtdAlunos >= 1 && qtdAlunos <= 20))
    {
        return 0;
    }

    defineAlunos(turma, qtdAlunos);
    ordenaTurma(turma, qtdAlunos);

    do
    {
        menu();
        scanf(" %d", &opcaoMenu);

        switch (opcaoMenu)
        {
        case 1:
            imprimeTurma(turma, qtdAlunos);
            break;
        case 2:
            printf("Digite o RGA do aluno que deseja buscar: ");
            scanf(" %lld", &rga_aluno);

            buscaAluno(turma, qtdAlunos, rga_aluno);
            break;
        case 3:
            alunosAcimaDaMedia(turma, qtdAlunos);
            break;
        case 4:
            imprimeAlunosAcimaDaMedia(turma, qtdAlunos);
            break;
        case 5:
            insereAluno(turma, &qtdAlunos);
            break;
        case 6:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (opcaoMenu != 6);

    return 0;
}

void menu()
{
    printf("\n==== MENU ====\n");
    printf("1. Imprimir lista de alunos\n");
    printf("2. Buscar um aluno por RGA\n");
    printf("3. Contar alunos com média acima de 6,0\n");
    printf("4. Imprimir alunos com média acima de 6,0\n");
    printf("5. Inserir um novo aluno\n");
    printf("Selecione uma opção: ");
}

void defineAlunos(Aluno *turma, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("RGA: ");
        scanf(" %lld", &turma[i].rga);

        printf("Nome: ");
        scanf(" %[^\n]", turma[i].nome);

        printf("Média: ");
        scanf(" %f", &turma[i].media);
        printf("Aluno %d adicionado\n", i);
    }
}

void imprimeTurma(Aluno *turma, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n--- Aluno %d ---\n", i);
        printf("RGA: %lld\n", turma[i].rga);
        printf("Nome: %s\n", turma[i].nome);
        printf("Média: %.1f\n", turma[i].media);
    }
}

void ordenaTurma(Aluno *turma, int n)
{
    Aluno aux;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (turma[j].rga > turma[j + 1].rga)
            {
                aux = turma[j];
                turma[j] = turma[j + 1];
                turma[j + 1] = aux;
            }
        }
    }
}

int buscaAluno(Aluno *turma, int n, long long rga)
{
    int inicio = 0;
    int meio;
    int fim = n - 1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (rga == turma[meio].rga)
        {
            return 1;
        }

        if (rga > turma[meio].rga)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return 0;
}

void alunosAcimaDaMedia(Aluno *turma, int n)
{
    int contador = 0;

    for (int i = 0; i < n; i++)
    {
        if (turma[i].media > 6)
        {
            contador++;
        }
    }

    printf("Existem %d alunos com média acima de 6,0.", contador);
}

void imprimeAlunosAcimaDaMedia(Aluno *turma, int n)
{
    printf("--- Alunos acima da média ---");
    for (int i = 0; i < n; i++)
    {
        if (turma[i].media > 6)
        {
            printf(" %s", turma[i].nome);
        }
    }
}

void insereAluno(Aluno *turma, int *n)
{
    if (*n >= 20)
    {
        printf("A turma está cheia.");
        return;
    }

    printf("RGA: ");
    scanf(" %lld", &turma[*n].rga);

    printf("Nome: ");
    scanf(" %[^\n]", turma[*n].nome);

    printf("Média: ");
    scanf(" %f", &turma[*n].media);
    printf("Aluno adicionado\n");

    // aumenta a qtd de alunos atualmente
    (*n)++;
    ordenaTurma(turma, *n);
}