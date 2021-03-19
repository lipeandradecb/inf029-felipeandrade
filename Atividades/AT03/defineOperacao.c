#include <stdio.h>

#include "operacoes.h"

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
