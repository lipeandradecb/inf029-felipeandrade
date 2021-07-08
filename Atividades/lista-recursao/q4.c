#include<stdio.h>

int somaVetor(int vet[], int n);

int main() {
    int tam;
    int i;
    int soma;

    printf("insira o tamanho do vetor\n");
    scanf("%d", &tam);

    printf("insira os numeros no vetor de tamanho %d\n", tam);
    int vetor[tam];
    for(i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }
    soma = somaVetor(vetor, tam);
    printf("o valor da soma eh %d\n", soma);
    return 0;
}

int somaVetor(int vet[], int n) {
    if(n == 1) {
        return vet[0];
    }
    return vet[n - 1] + somaVetor(vet, n - 1);
}