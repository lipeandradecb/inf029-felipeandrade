#include<stdio.h>

int soma1aN(int n);

int main() {
    int num = 0;
    int soma = 0;

    printf("digite um numero inteiro\n");
    scanf("%d", &num);

    soma = soma1aN(num);
    printf("a soma de 1 a N eh %d", soma);
    return 0;
}

int soma1aN(int n) {
    if(n == 1) {
        return 1;
    }
    return n + soma1aN(n - 1);
}