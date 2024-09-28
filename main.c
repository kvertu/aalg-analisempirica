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
void showResults(int * v1, int * v2, int n)
{
    printf("Fim da função! Validando... ");
    if (!compare(v1, v2, n))
        printf("Ordenado!\n");
    else
        printf("Algo deu errado e o vetor não está ordenado.\n");
    printf("\nTempo de execução: %lfs (%ld clocks)\n\n", getElapsedTimeInSeconds(), getElapsedTimeInClocks());
}

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("Parâmetros inválidos.\n");
        return 0;
    }
    int qtde = atoi(argv[1]);
    if (qtde <= 0)
    {
        printf("Quantidade inválida.\n");
        return 0;
    }

    // Inicializa os vetores
    int reference[qtde]; // Vetor de referência (usado para comparar com o vetor a ser ordenado)
    identity(reference, qtde);
    int shuffled[qtde]; // Vetor a ser ordenado
    identity(shuffled, qtde);

    printf("Vetor de referência (tamanho: %d): ", qtde);
    print(reference, qtde);

    int choice;
    do
    {
        reset();
        helper();
        scanf(" %d", &choice);
        
        shuffle(shuffled, qtde);

        switch (choice)
        {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            printf("Ordenando... ");
            start();
            insertionSort(shuffled, qtde);
            stop();
            showResults(reference, shuffled, qtde);
            break;
        case 2:
            printf("Ordenando... ");
            start();
            selectionSort(shuffled, qtde);
            stop();
            showResults(reference, shuffled, qtde);
            break;
        case 3:
            notImplemented();
            break;
        case 4:
            notImplemented();
            break;
        case 5:
            notImplemented();
            break;
        
        default:
            error();
            break;
        }
    } while (choice != 0);
    
}