#include <stdio.h>
#include <string.h>

void chamaMenu();

typedef struct dataNascimento {
    int dia, mes, ano;
} Data;

typedef struct dadosAluno {
    int matricula;
    char nome[50];
    char sexo;
    char cpf[11];
} Aluno;

int main() {
    Aluno aluno;
    Aluno listaAlunos[10];
    chamaMenu();
}

void chamaMenu() {
    int opcaoMenu;
    printf("Seja bem vindo ao programa Escola!\n Escolha uma das opções do menu:\n"
           "1 - Alunos\n 2 - Professores\n 3 - Disciplinas\n");
    scanf("%d", &opcaoMenu);
}