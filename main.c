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
 

    switch(sortOption){
        case 1:
            chosenShuffler = shuffle;
            break;
        case 2: 
            unsort(shuffled, tam, shufflePartial); 
            break;     
        case 3:
            chosenShuffler = invert;
            break;
        case 4:
            chosenShuffler = dontChange;
            break; 
        default:
            printf("Função de embaralhamento não escolhida! \nFunção shuffle escolhida por padrão ");
            chosenShuffler = shuffle;
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
                unsort(shuffled, tam, chosenShuffler);
                // printf("Antes da ordenação: ");
                // print(shuffled, tam);
                insertionSort(shuffled, tam, &c, &p);
                // printf("\nDepois da ordenação: ");
                // print(shuffled, tam);
                // printf("\n");
                somac += c;
                somap += p;
            }
            stop();
            showResults(reference, shuffled, tam, somac, somap, tentativas);
            break;
        case 2:
            // Selection sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                long c, p;
                unsort(shuffled, tam, chosenShuffler);
                // printf("\nAntes da ordenação: ");
                // print(shuffled, tam);
                selectionSort(shuffled, tam, &c, &p);
                // printf("\nDepois da ordenação: ");
                // print(shuffled, tam);
                somac += c;
                somap += p;
            }
            stop();
            showResults(reference, shuffled, tam, somac, somap, tentativas);
            break;
        case 3:
            // Merge sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                long c, p;
                unsort(shuffled, tam, chosenShuffler);
                // printf("\nAntes da ordenação: ");
                // print(shuffled, tam);
                mergeSort(shuffled, 0, tam - 1, &c, &p);
                // printf("\nDepois da ordenação: ");
                // print(shuffled, tam);
                somac += c;
                somap += p;
            }
            stop();
            showResults(reference, shuffled, tam, somac, somap, tentativas);
            break;
        case 4:
            // Quick sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                long c, p;
                unsort(shuffled, tam, chosenShuffler);
                //printf("\nAntes da ordenação: ");
                //print(shuffled, tam);
                quickSort(shuffled, 0, tam - 1, &c, &p);
                // printf("\nDepois da ordenação: ");
                // print(shuffled, tam);
                somac += c;
                somap += p;
            }
            stop();
            showResults(reference, shuffled, tam, somac, somap, tentativas);
            break;
        case 5:
            // Heap sort
            printf("Ordenando... \n");
            start();
            for (int i = 0; i < tentativas; i++)
            {
                long c, p;
                unsort(shuffled, tam, chosenShuffler);
                // printf("\nAntes da ordenação: ");
                // print(shuffled, tam);
                heapSort(shuffled, tam, &c, &p);
                // printf("\nDepois da ordenação: ");
                // print(shuffled, tam);
                somac += c;
                somap += p;
            }
            stop();
            showResults(reference, shuffled, tam, somac, somap, tentativas);
            break;
        
        default:
            error();
            break;
        }
    } while (choice != 0);
    
}