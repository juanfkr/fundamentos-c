#include <stdio.h>
#include <stdlib.h>

typedef struct DataNascimento {
    int dia;
    int mes;
    int ano;
} DataNascimento;

typedef struct Aluno {
    char nome[101];
    long long int rga;
    DataNascimento dataNascimento;
} Aluno;

typedef struct Disciplina {
    int codigo;
    char nome[101];
    char professor[101];
    int cargaHoraria;
    int qtdAlunos;
    Aluno *alunos;
} Disciplina;

void menu();
void limpaTerminal();
Disciplina *alocaDisciplinas(int k);
void leDisciplinas(Disciplina *disciplinas, int k);
void alunosPorDisciplina(Disciplina *disciplinas, int k, int codigo);
void listarProfessores(Disciplina *disciplinas, int k);
void removeAluno(Disciplina *disciplinas, int k, int codigoDisciplina);

int main() {
    Disciplina *disciplinas = NULL;
    int k;
    int codigoDisciplina;
    int opcao;

    printf("Forneça a quantidade de disciplinas: ");
    scanf(" %d", &k);

    disciplinas = alocaDisciplinas(k);

    leDisciplinas(disciplinas, k);

    printf("Disciplinas cadastradas.");

    do {
        menu();

        scanf(" %d", &opcao);

        limpaTerminal();

        switch (opcao) {
        case 0:
            break;
        case 1:
            printf("Informe o código da disciplina que deseja procurar: ");
            scanf(" %d", &codigoDisciplina);

            alunosPorDisciplina(disciplinas, k, codigoDisciplina);
            break;
        case 2:
            listarProfessores(disciplinas, k);
            break;
        case 3:
            printf("Informe o código da disciplina que deseja procurar");
            scanf(" %d", &codigoDisciplina);

            removeAluno(disciplinas, k, codigoDisciplina);
            break;
        default:
            break;
        }
    } while(opcao != -1);

    return 0;
}

void menu() {
    printf("\n======================\n");
    printf("O que deseja fazer?\n");
    printf("0. Sair\n");
    printf("1. Listar alunos de uma disciplina\n");
    printf("2. Listar professores e suas disciplinas\n");
    printf("3. Remover um aluno\n");
}

void limpaTerminal()
{
    for (int i = 0; i <= 100; i++)
    {
        printf("\n");
    }
}

Disciplina *alocaDisciplinas(int k) {
    Disciplina *disciplinas = (Disciplina *)malloc(k * sizeof(Disciplina));

    if (disciplinas == NULL) return NULL;

    return disciplinas;
}

void leDisciplinas(Disciplina *disciplinas, int k) {
    int qtdAlunos;

    for (Disciplina *pt = disciplinas; pt < (disciplinas + k); pt++)
    {
        printf("Informe o código da disciplina: ");
        scanf(" %d", &pt->codigo);

        printf("Informe o nome da disciplina: ");
        scanf(" %100[^\n]", pt->nome);

        printf("Informe o nome do professor que ministra a disciplina: ");
        scanf(" %100[^\n]", pt->professor);

        printf("Informe a carga horária da disciplina: ");
        scanf(" %d", &pt->cargaHoraria);

        printf("Informe a quantidade de alunos da disciplina: ");
        scanf(" %d", &pt->qtdAlunos);

        limpaTerminal();

        pt->alunos = (Aluno *) malloc(pt->qtdAlunos * sizeof(Aluno));

        if (pt->alunos == NULL)
            return;

        for (Aluno *ptAlunos = pt->alunos; ptAlunos < (pt->alunos + pt->qtdAlunos); ptAlunos++)
        {
            printf("Informe o nome do aluno: ");
            scanf(" %100[^\n]", ptAlunos->nome);

            printf("Informe o RGA do aluno: ");
            scanf(" %lld", &ptAlunos->rga);

            printf("Informe o dia, mês e ano de nascimento: ");
            scanf(" %d %d %d", &ptAlunos->dataNascimento.dia, &ptAlunos->dataNascimento.mes, &ptAlunos->dataNascimento.ano);
        }
    }
}

void alunosPorDisciplina(Disciplina *disciplinas, int k, int codigo) {
    for (Disciplina *pt = disciplinas; pt < (disciplinas + k); pt++)
    {
        if (codigo == pt->codigo)
        {
            printf("Alunos da turma %d do professor %s: \n", pt->codigo, pt->professor);
            for (Aluno *ptAlunos = pt->alunos; ptAlunos < (pt->alunos + pt->qtdAlunos); ptAlunos++)
            {
                printf("\n===================\n");
                printf("RGA: %lld\n", ptAlunos->rga);
                printf("Nome: %s\n", ptAlunos->nome);
                printf("Data de nascimento: %d/%d/%d\n", ptAlunos->dataNascimento.dia, ptAlunos->dataNascimento.mes, ptAlunos->dataNascimento.ano);
            }
        }
    }
}

void listarProfessores(Disciplina *disciplinas, int k) {
    printf("\nLista de professores: \n");

    for (Disciplina *pt = disciplinas; pt < (disciplinas + k); pt++)
    {
        printf("[ %s | %s ]\n", pt->professor, pt->nome);
    }
}

void removeAluno(Disciplina *disciplinas, int k, int codigoDisciplina) {
    long long int rgaAluno;
    Aluno *tempPt;

    for (Disciplina *ptDisciplina = disciplinas; ptDisciplina < (disciplinas + k); ptDisciplina++)
    {
        if (ptDisciplina->codigo != codigoDisciplina) continue;

        printf("DISCIPLINA ENCONTRADA!\n");
        printf("Informe o RGA do aluno que deseja remover: ");
        scanf(" %lld", &rgaAluno);

        Aluno *fim = ptDisciplina->alunos + ptDisciplina->qtdAlunos;

        for (Aluno *ptAluno = ptDisciplina->alunos; ptAluno < (ptDisciplina->alunos + ptDisciplina->qtdAlunos); ptAluno++)
        {
            if (ptAluno->rga != rgaAluno) continue;

            for (Aluno *i = ptAluno; i < fim - 1; i++)
            {
                *i = *(i + 1);
            }

            ptDisciplina->qtdAlunos--;
            printf("Aluno encontrado e removido.\n");
            return;
        }

        tempPt = realloc(ptDisciplina->alunos, ptDisciplina->qtdAlunos * sizeof(Aluno));

        if (tempPt == NULL) {
            return;
        }

        ptDisciplina->alunos = tempPt;

        printf("Aluno não encontrado nessa disciplina.");
        return;
    }

    printf("Disciplina não encontrada");
    return;
}