#include <stdio.h>

float subtrai(float valor1, float valor2, float valor3);

int main() {
    float valor1, valor2, valor3, resultadoSubtracao;
    printf("digite o primeiro valor\n");
    scanf("%f", &valor1);
    printf("digite o segundo valor\n");
    scanf("%f", &valor2);
    printf("digite o terceiro valor\n");
    scanf("%f", &valor3);
    resultadoSubtracao = subtrai(valor1, valor2, valor3);
    printf("resultado da soma é %f\n", resultadoSubtracao);
}

float subtrai(float valor1, float valor2, float valor3) {
    float resultado;
    resultado = valor1 - valor2 - valor3;
    return resultado;
}