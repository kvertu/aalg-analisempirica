#include "inc/base.h"
#include "inc/sort.h"
#include "inc/timer.h"

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
void showResults(int * ref, int * sorted, int n, long sum, int attempts)
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
    printf("\nTempo de execução média: %lfs (%lf clocks)\nNúmero de comparações média: %lf\n\n", getElapsedTimeInSeconds() / attempts, (double) getElapsedTimeInClocks() / attempts, (double) sum / attempts);
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

    printf("Vetor de referência (tamanho: %d): ", tam);
    print(reference, tam);

    int choice;
    do
    {
        long soma = 0;
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
                shuffle(shuffled, tam);
                soma += insertionSort(shuffled, tam);
            }
            stop();
            showResults(reference, shuffled, tam, soma, tentativas);
            break;
        case 2:
            // Selection sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                shuffle(shuffled, tam);
                soma += selectionSort(shuffled, tam);
            }
            stop();
            showResults(reference, shuffled, tam, soma, tentativas);
            break;
        case 3:
            // Merge sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                shuffle(shuffled, tam);
                soma += mergeSort(shuffled, 0, tam - 1);
            }
            stop();
            showResults(reference, shuffled, tam, soma, tentativas);
            break;
        case 4:
            // Quick sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                shuffle(shuffled, tam);
                soma += quickSort(shuffled, 0, tam - 1);
            }
            stop();
            showResults(reference, shuffled, tam, soma, tentativas);
            break;
        case 5:
            // Heap sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                shuffle(shuffled, tam);
                soma += heapSort(shuffled, tam);
            }
            stop();
            showResults(reference, shuffled, tam, soma, tentativas);
            break;
        
        default:
            error();
            break;
        }
    } while (choice != 0);
    
}