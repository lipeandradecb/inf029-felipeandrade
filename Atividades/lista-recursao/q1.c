#include <stdio.h>

double fatorial(int n);

int main()
{
    int numero;
    double f;

    printf("Digite o numero que deseja calcular o fatorial: ");
    scanf("%d",&numero);

    f = fatorial(numero);
    printf("Fatorial de %d = %.0lf", numero, f);

//    getchar();
    return 0;
}

double fatorial(int n)
{
    double vfat;

    if ( n <= 1 )
        //Caso base: fatorial de n <= 1 retorna 1
        return (1);
    else {
        vfat = n * fatorial(n - 1);
        return (vfat);
    }
}