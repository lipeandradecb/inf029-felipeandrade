#include <stdio.h>

void exibeMenu();
void defineOperacao(int opcao);
void soma(int valor1, int valor2);
void subtracao(int valor1, int valor2);
void multiplicacao(int valor1, int valor2);
void divisao(int valor1, int valor2);

int main() {
    int opcaomenu;
    exibeMenu();
    scanf("%d", &opcaomenu);
    defineOperacao(opcaomenu);
    return 0;
}

void exibeMenu() {
    printf("Escolha a opção desejada:\n"
           " 0 - Sair\n 1 - Somar\n 2 - Subtrair\n 3 - Multiplicar\n 4 - Dividir\n");
}

void defineOperacao(int opcao) {
    float valor1, valor2;
    if (opcao == 0) {
        printf("não vai fazer nada? :(\n");
        return;
    }
    if (opcao > 4 || opcao < 0) {
        printf("Escolha um opção disponível");
        return;
    }
    printf("informe o primeiro valor\n");
    scanf("%f", &valor1);
    printf("informe o segundo valor\n");
    scanf("%f", &valor2);
    switch (opcao) {
        case 1:
            soma(valor1, valor2);
            break;
        case 2:
            subtracao(valor1, valor2);
            break;
        case 3:
            multiplicacao(valor1, valor2);
            break;
        case 4:
            divisao(valor1, valor2);
            break;
        default:
            printf("Digite um inteiro de 1 a 4\n");
    }
}
void soma(int valor1, int valor2) {
    float resultado;
    resultado = valor1 + valor2;
    printf("resultado da soma é: %f\n", resultado);
}

void subtracao(int valor1, int valor2) {
    float resultado;
    resultado = (valor1 - valor2);
    printf("resultado da subtração é: %f\n", resultado);
}

void multiplicacao(int valor1, int valor2) {
    float resultado;
    resultado = valor1 * valor2;
    printf("resultado da multiplicação é: %f\n", resultado);
}

void divisao(int valor1, int valor2) {
    float resultado;
    resultado = valor1 / valor2;
    printf("resultado da divisão é: %f\n", resultado);
}