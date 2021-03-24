#include <stdio.h>

float soma(float valor1, float valor2);

int main() {
    float valor1, valor2, resultadoSoma;
    printf("digite o primeiro valor\n");
    scanf("%f", &valor1);
    printf("digite o segundo valor\n");
    scanf("%f", &valor2);
    resultadoSoma = soma(valor1, valor2);
    printf("resultado da soma é %f\n", resultadoSoma);
}

float soma(float valor1, float valor2) {
    float resultado;
    resultado = valor1 + valor2;
    return resultado;
}