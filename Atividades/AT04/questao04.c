#include <stdio.h>

int ler3Numeros(int i);

int main() {
    int numero;
    for (int i = 0; i < 3 ; ++i) {
        numero = ler3Numeros(i);
        printf("numero digitado %d\n\n", numero);
    }
}

int ler3Numeros(int i) {
    int numeros[3];
    printf("digite o número\n\n");
    scanf("%d", &numeros[i]);
    return numeros[i];


}