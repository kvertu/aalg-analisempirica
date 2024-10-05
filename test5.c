#include "inc/base.h"
#include "inc/sort.h"
#include "inc/timer.h"

/*
    Nesta main as funções de embaralhamento são executadas fora das funções de ordenação 
    permitindo que todos os algoritmos de ordenação trabalhem com o mesmo vetor.

    /Trabalhar com tentativas = 1
*/

/*
    Mostra as opções do programa
*/
void helper()
{
    printf("Escolha o algoritmo de ordenação:\n0: Sair\n1: Insertion Sort\n2: Selection Sort\n3: Merge Sort\n4: Quicksort\n5: Heapsort\n");
}

/*
    Mensagem de erro
*/
void error()
{
    printf("Entrada inválida, tente novamente.\n");
}

/*
    Mensagem para quando a função não está implementada (placeholder)
*/
void notImplemented()
{
    printf("Funcionalidade ainda não implementada.\n");
}

/*
    Mostra os resultados da ordenação
*/
void showResults(int * ref, int * sorted, int n, long sumc, long sump, int attempts)
{
    printf("Fim da função! Validando... ");
    if (!compare(ref, sorted, n))
        printf("Ordenado!\n");
    else
    {
        printf("Algo deu errado e o vetor não está ordenado.\nVetor original: ");
        print(ref, n);
        printf("Vetor \"Ordenado\": ");
        print(sorted, n);
    }
    printf("\nForam feitas %d ordenações.\nTempo de execução média: %.5lfs (%.2lf clocks)\nNúmero de comparações média: %.2lf\nNúmero de permutações média: %.2lf\n",
    attempts, getElapsedTimeInSeconds() / attempts, (double) getElapsedTimeInClocks() / attempts, (double) sumc / attempts, (double) sump / attempts);
}

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Parâmetros inválidos.\n");
        return 0;
    }
    int tam = atoi(argv[1]);
    int tentativas = atoi(argv[2]);
    if (tam <= 0)
    {
        printf("Tamanho de vetor inválida.\n");
        return 0;
    }
    if (tentativas <= 0)
    {
        printf("Quantidade de tentativas inválidas.\n");
        return 0;
    }

    // Inicializa os vetores
    int reference[tam]; // Vetor de referência (usado para comparar com o vetor a ser ordenado)
    identity(reference, tam);
    int shuffled[tam]; // Vetor a ser ordenado
    copy(shuffled, reference, tam);
    int copyShuffled[tam]; //Vetor que recebe a copia do vetor desordenado

    //Ponteiro p/ a função de embaralhamento
    void (*chosenShuffler)(int *, int) = NULL;

    printf("Vetor de referência (tamanho: %d): ", tam);
    print(reference, tam);

    int choice;
    int sortOption;

    //Menu para a escolha da função de embaralhamento
    printf("\nEscolha a forma de embaralhar o vetor: ");
    printf("\n1 - Embaralha todo o vetor ");
    printf("\n2 - Embaralha o vetor parcialmente ");
    printf("\n3 - Inverte as posições do vetor ");
    printf("\n4 - Mantém o vetor ordenado \n");
    scanf("%d", &sortOption);
 
    //Menu para escolher a forma de "desordenação"
    //O vetor já sai desse switch desordenado
    switch(sortOption){
        case 1:
            unsort(shuffled, tam, shuffle);
            break;
        // case 2: adicionar função embaralha parcial do Cauê 
        //     break;     
        case 3:
            unsort(shuffled, tam, invert);
            break;
        case 4:
            unsort(shuffled, tam, dontChange);
            break; 
        default:
            printf("Função de embaralhamento não escolhida! \nFunção shuffle escolhida por padrão\n\n ");
            unsort(shuffled, tam, shuffle);
            break;  
   
    }

    do
    {
        long somac = 0, somap = 0; // A soma das trocas e permutações
        reset();
        helper();
        scanf(" %d", &choice);

        
        switch (choice)
        {
        case 0:
            // Saindo do programa
            printf("Saindo...\n");
            break;
        case 1:
            // Insertion sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                long c, p;
                printf("Antes da ordenação: ");
                print(shuffled, tam);
                copy(copyShuffled, shuffled, tam); //Copia o valor do vetor desordenado para utilizar na função de ordenação
                insertionSort(copyShuffled, tam, &c, &p);
                printf("\nDepois da ordenação: ");
                
                print(copyShuffled, tam);
                printf("\n");
                somac += c;
                somap += p;
            }
            stop();
            showResults(reference, copyShuffled, tam, somac, somap, tentativas);
            break;
        case 2:
            // Selection sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                long c, p;
                printf("\nAntes da ordenação: ");
                print(shuffled, tam);
                copy(copyShuffled, shuffled, tam);
                selectionSort(copyShuffled, tam, &c, &p);
                printf("\nDepois da ordenação: ");
                print(copyShuffled, tam);
                somac += c;
                somap += p;
            }
            stop();
            showResults(reference, copyShuffled, tam, somac, somap, tentativas);
            break;
        case 3:
            // Merge sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                long c, p;
                printf("\nAntes da ordenação: ");
                print(shuffled, tam);
                copy(copyShuffled, shuffled, tam);
                mergeSort(copyShuffled, 0, tam - 1, &c, &p);
                printf("\nDepois da ordenação: ");
                print(copyShuffled, tam);
                somac += c;
                somap += p;
            }
            stop();
            showResults(reference, copyShuffled, tam, somac, somap, tentativas);
            break;
        case 4:
            // Quick sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                long c, p;
                printf("\nAntes da ordenação: ");
                print(shuffled, tam);
                copy(copyShuffled, shuffled, tam);
                quickSort(copyShuffled, 0, tam - 1, &c, &p);
                printf("\nDepois da ordenação: ");
                print(copyShuffled, tam);
                somac += c;
                somap += p;
            }
            stop();
            showResults(reference, copyShuffled, tam, somac, somap, tentativas);
            break;
        case 5:
            // Heap sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                long c, p;
                printf("\nAntes da ordenação: ");
                print(shuffled, tam);
                copy(copyShuffled, shuffled, tam);
                heapSort(copyShuffled, tam, &c, &p);
                printf("\nDepois da ordenação: ");
                print(copyShuffled, tam);
                somac += c;
                somap += p;
            }
            stop();
            showResults(reference, copyShuffled, tam, somac, somap, tentativas);
            break;
        
        default:
            error();
            break;
        }
    } while (choice != 0);
    
}