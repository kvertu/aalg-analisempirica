/*
    Funções básicas para manipulação dos vetores
*/

#ifndef BASE_H
#define BASE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void unsort(int * v, int n, void (*shuffler)(int *, int))
{
    (*shuffler)(v, n);
}
/*
    Retorna um número aleatório entre 0 e 1 (inclusivo)
*/
double randomD()
{
    return (double)rand() / (double)RAND_MAX;
}

/*
    Embaralha um vetor de tamanho n
*/
void shuffle(int * v, int n)
{
    int current = n;

    while (current != 0)
    {
        int random = floor(randomD() * current);
        current--;

        int temp = v[current];
        v[current] = v[random];
        v[random] = temp;
    }
}

/*
    Inverte um vetor de tamanho n
*/
void invert(int * v, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = temp;
    }
}

/*
    Não faz nada
*/
void dontChange(int * v, int n) {
    return;
}

/*
    Copia o conteudo do vetor src para dest (assumindo que eles tem tamanho igual)
*/
void copy(int * dest, int * src, int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

/*
    Imprime o vetor na tela
*/
void print(int * v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

/*
    Compara os vetores v1 e v2 (assumindo que ambos tem tamanho igual)
    Retorna a quantidade de posições que não batem (ou seja: 0 indica que não iguais, n indica que são completamente diferentes)
*/
int compare(int * v1, int * v2, int n)
{
    int result = 0;
    for (int i = 0; i < n; i ++)
    {
        if (v1[i] != v2[i]) result++;
    }
    return result;
}

/*
    Preenche o vetor tal que v[i] = i, para todo i entre 0 e n (inclusivo)
*/
void identity(int * v, int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
}

#endif