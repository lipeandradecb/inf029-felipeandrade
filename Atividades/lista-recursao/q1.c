#include <stdio.h>

double fatorial(int n);

int main() {
    int num;
    double fat;

    printf("Digite o numero que deseja calcular o fatorial: ");
    scanf("%d",&num);

    fat = fatorial(num);
    printf("Fatorial de %d = %.0lf", num, fat);

    return 0;
}

double fatorial(int n) {
    double vfat;

    if (n <= 1) {
        return 1;
    }
    else {
        vfat = n * fatorial(n - 1);
        return vfat;
    }
}