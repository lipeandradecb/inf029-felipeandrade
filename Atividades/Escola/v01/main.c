#include <stdio.h>
#include <string.h>
#define TAM 10

int cadastraAluno();
void listaAlunos(int qtdeAlunos);
void menuAlunos();
void chamaMenu();

typedef struct dataNascimento {
    int dia, mes, ano;
} Data;

typedef struct dadosAluno {
    int matricula;
    char nome[50];
    char sexo;
    Data dataNascimento;
    char cpf[12];
} Aluno;

int main() {

    chamaMenu();
}

void chamaMenu() {
    int opcaoMenu;
    int sair = 0;

    while (!sair) {
        printf("Menu Principal\n");
        printf("Digite a opção:\n");
        printf("0 - Sair\n");
        printf("1 - Alunos\n");
        printf("2 - Professores\n");
        printf("2 - Disciplinas\n");
        scanf("%d", &opcaoMenu);
        switch (opcaoMenu) {
            case 0: {
                printf("Saindo do menu principal\n");
                printf("Fechando programa\n");
                sair = 1;
                break;
            }
            case 1: {
                menuAlunos();
                break;
            }
        }
    }
}

void menuAlunos() {
    int opcaoMenuAlunos, qtdeAlunos;
    int sair = 0;

    while (!sair) {
        printf("Menu Alunos\n");
        printf("Digite a opção:\n");
        printf("0 - Sair\n");
        printf("1 - Cadastra aluno\n");
        printf("2 - Listar alunos\n");
        scanf("%d", &opcaoMenuAlunos);
        switch (opcaoMenuAlunos) {
            case 0: {
                printf("Saindo do menu de alunos\n");
                printf("Entrando no menu principal\n");
                sair = 1;
                break;
            }
            case 1: {
                qtdeAlunos = cadastraAluno();

                break;
            }
            case 2: {
                listaAlunos(qtdeAlunos);
                break;
            }
        }
    }
}

int cadastraAluno() {
    Aluno listaAlunos[TAM];
    int qtdeAlunos = 0;

    printf("Cadastro de Aluno\n");
    printf("Digite a matrícula: \n");
    scanf("%d", &listaAlunos[qtdeAlunos].matricula);
    printf("Digite o nome: \n");
    getchar();
    fgets(listaAlunos[qtdeAlunos].nome, 50, stdin);
    size_t ln = strlen(listaAlunos[qtdeAlunos].nome) - 1;
    if (listaAlunos[qtdeAlunos].nome[ln] == '\n')
        listaAlunos[qtdeAlunos].nome[ln] = '\0';
    printf("Digite o sexo (M para masculino e F para Feminino): ");
    scanf("%c", &listaAlunos[qtdeAlunos].sexo);
    printf("Digite o dia de nascimento: ");
    scanf("%d", &listaAlunos[qtdeAlunos].dataNascimento.dia);
    printf("Digite o mês de nascimento: ");
    scanf("%d", &listaAlunos[qtdeAlunos].dataNascimento.mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &listaAlunos[qtdeAlunos].dataNascimento.ano);
    printf("Digite o CPF: \n");
    getchar();
    fgets(listaAlunos[qtdeAlunos].cpf, 12, stdin);
    ln = strlen(listaAlunos[qtdeAlunos].cpf) - 1;
    if (listaAlunos[qtdeAlunos].cpf[ln] == '\n')
        listaAlunos[qtdeAlunos].cpf[ln] = '\0';
    qtdeAlunos++;
    printf("Cadastro finalizado");
    return qtdeAlunos;
}

void listaAlunos(int qtdeAlunos) {
    Aluno listaAlunos[TAM];
    int i;
    printf("Alunos cadastrados \n");
    for (i = 0; i < qtdeAlunos; i++){
        printf("-----\n");
        printf("Matrícula: %d\n", listaAlunos[i].matricula);
        printf("Nome: %s\n", listaAlunos[i].nome);
        printf("Sexo: %c\n", listaAlunos[i].sexo);
        printf("Data Nascimento: %d/%d/%d\n", listaAlunos[i].dataNascimento.dia, listaAlunos[i].dataNascimento.mes, listaAlunos[i].dataNascimento.ano);
        printf("CPF: %s\n", listaAlunos[i].cpf);
    }
}