#include<stdio.h>

int inverteNumero(int n);

int main() {
    int num = 0;

    printf("digite um numero \n");
    scanf("%d", &num);
    inverteNumero(num);
    return 0;
}

int inverteNumero(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        printf("%d", n % 10);
        n = n / 10;
        return inverteNumero(n);
    }
}