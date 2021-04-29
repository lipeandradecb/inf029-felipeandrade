#include <stdio.h>
#include <string.h>
#define TAM 10

int cadastraAluno();
int cadastraProfessor();
int cadastraDisciplina();
void listaAlunos(int qtdeAlunos);
void listaProfessores(int qtdeProfessores);
void listaDisciplinas(int qtdeDisciplinas);
void menuAlunos();
void menuProfessores();
void menuDisciplinas();
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

typedef struct dadosProfessor {
    int matricula;
    char nome[50];
    char sexo;
    Data dataNascimento;
    char cpf[12];
} Professor;

typedef struct dadosDisciplina {
    char nome[50];
    int codigo;
    int semestre;
    Professor professor;
} Disciplina;

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
        printf("3 - Disciplinas\n");
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
            case 2: {
                menuProfessores();
                break;
            }
            case 3: {
                menuDisciplinas();
                break;
            }
            default: {
                printf("Algo errado aconteceu");
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
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        scanf("%d", &opcaoMenuAlunos);
        switch (opcaoMenuAlunos) {
            case 0: {
                printf("Saindo do menu de alunos\n");
                printf("Voltando ao menu principal\n");
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
            default: {
                printf("Algo errado aconteceu");
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
    printf("Digite o sexo (M para masculino e F para Feminino): \n");
    scanf("%c", &listaAlunos[qtdeAlunos].sexo);
    printf("Digite o dia de nascimento: \n");
    scanf("%d", &listaAlunos[qtdeAlunos].dataNascimento.dia);
    printf("Digite o mês de nascimento: \n");
    scanf("%d", &listaAlunos[qtdeAlunos].dataNascimento.mes);
    printf("Digite o ano de nascimento: \n");
    scanf("%d", &listaAlunos[qtdeAlunos].dataNascimento.ano);
    printf("Digite o CPF: \n");
    getchar();
    fgets(listaAlunos[qtdeAlunos].cpf, 12, stdin);
    ln = strlen(listaAlunos[qtdeAlunos].cpf) - 1;
    if (listaAlunos[qtdeAlunos].cpf[ln] == '\n')
        listaAlunos[qtdeAlunos].cpf[ln] = '\0';
    qtdeAlunos++;
    printf("Cadastro finalizado\n");
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

void menuProfessores() {
    int opcaoMenuProfessores, qtdeProfessores;
    int sair = 0;

    while (!sair) {
        printf("Menu Professores\n");
        printf("Digite a opção:\n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar professor\n");
        printf("2 - Listar professores\n");
        scanf("%d", &opcaoMenuProfessores);
        switch (opcaoMenuProfessores) {
            case 0: {
                printf("Saindo do menu de professores\n");
                printf("Voltando ao menu principal\n");
                sair = 1;
                break;
            }
            case 1: {
                qtdeProfessores = cadastraProfessor();
                break;
            }
            case 2: {
                listaProfessores(qtdeProfessores);
                break;
            }
            default: {
                printf("Algo errado aconteceu");
            }
        }
    }
}

int cadastraProfessor() {
    Professor listaProfessores[TAM];
    int qtdeProfessores = 0;

    printf("Cadastro de Professor\n");
    printf("Digite a matrícula: \n");
    scanf("%d", &listaProfessores[qtdeProfessores].matricula);
    printf("Digite o nome: \n");
    getchar();
    fgets(listaProfessores[qtdeProfessores].nome, 50, stdin);
    size_t ln = strlen(listaProfessores[qtdeProfessores].nome) - 1;
    if (listaProfessores[qtdeProfessores].nome[ln] == '\n')
        listaProfessores[qtdeProfessores].nome[ln] = '\0';
    printf("Digite o sexo (M para masculino e F para Feminino): \n");
    scanf("%c", &listaProfessores[qtdeProfessores].sexo);
    printf("Digite o dia de nascimento: \n");
    scanf("%d", &listaProfessores[qtdeProfessores].dataNascimento.dia);
    printf("Digite o mês de nascimento: \n");
    scanf("%d", &listaProfessores[qtdeProfessores].dataNascimento.mes);
    printf("Digite o ano de nascimento: \n");
    scanf("%d", &listaProfessores[qtdeProfessores].dataNascimento.ano);
    printf("Digite o CPF: \n");
    getchar();
    fgets(listaProfessores[qtdeProfessores].cpf, 12, stdin);
    ln = strlen(listaProfessores[qtdeProfessores].cpf) - 1;
    if (listaProfessores[qtdeProfessores].cpf[ln] == '\n')
        listaProfessores[qtdeProfessores].cpf[ln] = '\0';
    qtdeProfessores++;
    printf("Cadastro finalizado\n");
    return qtdeProfessores;
}

void listaProfessores(int qtdeProfessores) {
    Professor listaProfessores[TAM];
    int i;
    printf("Professores cadastrados \n");
    for (i = 0; i < qtdeProfessores; i++){
        printf("-----\n");
        printf("Matrícula: %d\n", listaProfessores[i].matricula);
        printf("Nome: %s\n", listaProfessores[i].nome);
        printf("Sexo: %c\n", listaProfessores[i].sexo);
        printf("Data Nascimento: %d/%d/%d\n", listaProfessores[i].dataNascimento.dia, listaProfessores[i].dataNascimento.mes, listaProfessores[i].dataNascimento.ano);
        printf("CPF: %s\n", listaProfessores[i].cpf);
    }
}

void menuDisciplinas() {
    int opcaoMenuDisciplinas, qtdeDisciplinas;
    int sair = 0;

    while (!sair) {
        printf("Menu Disciplinas\n");
        printf("Digite a opção:\n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar disciplina\n");
        printf("2 - Listar disciplinas\n");
        scanf("%d", &opcaoMenuDisciplinas);
        switch (opcaoMenuDisciplinas) {
            case 0: {
                printf("Saindo do menu de disciplinas\n");
                printf("Voltando ao menu principal\n");
                sair = 1;
                break;
            }
            case 1: {
                qtdeDisciplinas = cadastraDisciplina();
                break;
            }
            case 2: {
                listaDisciplinas(qtdeDisciplinas);
                break;
            }
            default: {
                printf("Algo errado aconteceu");
            }
        }
    }
}

int cadastraDisciplina() {
    Disciplina listaDisciplinas[TAM];
    int qtdeDisciplinas = 0;

    printf("Cadastro de Disciplina\n");
    printf("Digite o nome: \n");
    getchar();
    fgets(listaDisciplinas[qtdeDisciplinas].nome, 50, stdin);
    size_t ln = strlen(listaDisciplinas[qtdeDisciplinas].nome) - 1;
    if (listaDisciplinas[qtdeDisciplinas].nome[ln] == '\n')
        listaDisciplinas[qtdeDisciplinas].nome[ln] = '\0';
    printf("Digite o código da disciplina: \n");
    scanf("%d", &listaDisciplinas[qtdeDisciplinas].codigo);
    printf("Digite o semestre correspondente a disciplina: \n");
    scanf("%d", &listaDisciplinas[qtdeDisciplinas].semestre);
//    printf("Professor: \n");
//    scanf("%d", &listaDisciplinas[qtdeDisciplinas].professor);
    qtdeDisciplinas++;
    printf("Cadastro finalizado\n");

    return qtdeDisciplinas;
}

void listaDisciplinas(int qtdeDisciplinas) {

}
