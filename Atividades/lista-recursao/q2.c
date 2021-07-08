#include <stdio.h>

int fibonacci(int n);

int main() {
    int num;
    int fibo;

    printf("saiba o N-esimo numero da sequencia fibonacci, sendo N o numero inteiro que voce deve digitar\n");
    scanf("%d",&num);

    fibo = fibonacci(num);
    printf("o N-esimo numero tem valor %d\n", fibo);

    return 0;
}

int fibonacci(int n) {
    if(n < 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
