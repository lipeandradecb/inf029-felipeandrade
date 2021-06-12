
// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Felipe Andrade Silva
//  email: felipeandradecb@gmail.com
//  Matrícula: 2016216006
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "FelipeAndrade-2016216006-T1.h"

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{
    int fat = 0;

    if(x < 0) {
        fat = 0;
    }
    else if(x == 0 || x == 1) {
        fat = 1;
    } else {
        for(fat = 1; x > 1; x = x - 1) {
            fat *= x;
        }
    }

    return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

//typedef struct DQ
//{
//    char sDia [3];
//    char sMes [3];
//    char sAno [3];
//    int valido; // 0 se inválido, e 1 se válido
//
//} DataQuebrada;

Data QuebraData(char *data) {
    char dia[3];
    char mes[3];
    char ano[5];
    int barra = 0, k = 0, i = 0;
    Data dataInteira;

    while(data[i] != '\0'){
        if(data[i] == '/'){
            barra++;
            k=0;
        }
        if(barra==0){
            dia[k]=data[i];
            dia[k+1]='\0';
            k++;
        }
        else if(barra == 1){
            if(data[i] == '/'){
                i++;
            }
            mes[k] = data[i];
            mes[k+1] = '\0';
            k++;
        }
        else if(barra == 2){
            if(data[i] == '/'){
                i++;
            }
            ano[k] = data[i];
            ano[k+1] = '\0';
            k++;
        }
        i++;
    }

    dataInteira.dia = atoi(dia);
    dataInteira.mes = atoi(mes);
    dataInteira.ano = atoi(ano);

    if (dataInteira.ano >= 0 && dataInteira.ano <= 18){
        dataInteira.ano += 2000;
    }
    else if (dataInteira.ano >= 19 && dataInteira.ano <= 99){
        dataInteira.ano += 1900;
    }

    return dataInteira;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char *data) {
    int dataValida = 1;

    Data dataQuebrada = QuebraData(data);
    dataValida = ValidaData(dataQuebrada.dia,dataQuebrada.mes,dataQuebrada.ano);

    return dataValida;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos) {
    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;

    if (q1(datainicial) == 0)
        return 2;

    if (q1(datafinal) == 0)
        return 3;

    Data dataQuebradaInicial = QuebraData(datainicial);
    int nDiasInicial = dataQuebradaInicial.dia;
    int nMesesInicial = dataQuebradaInicial.mes;
    int nAnosInicial = dataQuebradaInicial.dia;

    Data dataQuebradaFinal = QuebraData(datafinal);
    int nDiasFinal = dataQuebradaFinal.dia;
    int nMesesFinal = dataQuebradaFinal.mes;
    int nAnosFinal = dataQuebradaFinal.dia;

    nDias = nDiasFinal - nDiasInicial;
    nMeses = nMesesFinal - nMesesInicial;
    nAnos = nAnosFinal - nAnosInicial;

    /*mantenha o código abaixo, para salvar os dados em
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    if (nDias > -1 && nMeses > -1 && nAnos > -1)
        return 1;

    return 4;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
    int qtdOcorrencias = 0;
    int tamTexto = 0;

    for(int k = 0; texto[k] != '\0'; k++)
        tamTexto++;

    if (isCaseSensitive == 1)
        for (int i = 0; i < tamTexto; i++)
            if (texto[i] == c)
                qtdOcorrencias++;

    if (isCaseSensitive != 1)
        for(int i = 0; i < tamTexto; i++)
            if (texto[i] == toupper(c) || texto[i] == tolower(c))
                qtdOcorrencias++;


    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
    int i = 0;
    int j = 0;
    int k = 0;
    int acentos = 0;
    int tamTexto = 0;
    int tamPalavra = 0;

    for(int x = 0; strTexto[x] != '\0'; x++)
        tamTexto++;

    for(int y = 0; strBusca[y] != '\0'; y++)
        tamPalavra++;

    for(i = 0; i < tamTexto; i++) {
        if(strBusca[0] == strTexto[i]) {
            while(strBusca[j] == strTexto[i]) {
                i++;
                j++;
            }
            if(j == tamPalavra) {
                posicoes[k] = i - (tamPalavra - 1) - acentos;
                k++;
                posicoes[k] = i - acentos;
                k++;
            }
            j = 0;
        }
        if(strTexto[i] < 0 && strTexto[i + 1] < 0)
            acentos++;
    }

    int qtdOcorrencias = 0;
    qtdOcorrencias = k/2;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) {
    int invertido = 0;
    int temp;

    while(num > 0) {
        temp = num % 10;
        invertido = invertido * 10 + temp;
        num = num / 10;
    }

    return invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}

int ValidaData(int dia, int mes, int ano) {
    if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (ano < 1 || ano > 2021))
        return 0;

    if (dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
        return 0;

    if (dia > 29 && (mes == 2 && ano % 4 == 0 || ano % 400 == 0 && ano % 100 != 0))
        return 0;
    if (dia > 28 && (mes == 2 && ano % 4 != 0 || ano % 400 != 0 && ano % 100 == 0))
        return 0;

    return 1;
}