#include <stdio.h>

#include "defineOperacao.h"

void exibeMenu();

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