#include <stdio.h>

void exibeMenu();
void defineOperacao(int opcao);
void soma(float valor1, float valor2);
void subtracao(float valor1, float valor2);
void multiplicacao(float valor1, float valor2);
void divisao(float valor1, float valor2);

int main() {
    int opcaomenu;
    exibeMenu();
    scanf("%d", &opcaomenu);
    defineOperacao(opcaomenu);
    return 0;
}

void exibeMenu() {
    printf("escolha a opção desejada:\n"
           " 0 - Sair\n 1 - Somar\n 2 - Subtrair\n 3 - Multiplicar\n 4 - Dividir\n");

}

void defineOperacao(int opcao) {
    float valor1, valor2;
    if (opcao == 0) {
        printf("não vai fazer nada? :(\n");
        return;
    }
    if (opcao > 4 || opcao < 0) {
        printf("escolha um opção disponível");
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
            printf("digite um inteiro de 1 a 4\n");
    }
}
void soma(float valor1, float valor2) {
    float resultado;
    resultado = valor1 + valor2;
    printf("resultado da soma é: %.2f\n", resultado);
}

void subtracao(float valor1, float valor2) {
    float resultado;
    resultado = (valor1 - valor2);
    printf("resultado da subtração é: %.2f\n", resultado);
}

void multiplicacao(float valor1, float valor2) {
    float resultado;
    resultado = valor1 * valor2;
    printf("resultado da multiplicação é: %.2f\n", resultado);
}

void divisao(float valor1, float valor2) {
    float resultado;
    resultado = valor1 / valor2;
    printf("resultado da divisão é: %.2f\n", resultado);
}