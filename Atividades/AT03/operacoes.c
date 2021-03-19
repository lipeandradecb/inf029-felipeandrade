#include <stdio.h>

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