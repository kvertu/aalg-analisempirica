#include "inc/base.h"
#include "inc/sort.h"
#include "inc/timer.h"

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("Argumentos insuficientes.\n");
        return 0;
    }

    int quantidade = atoi(argv[1]);
    int test[quantidade];
    int copied[quantidade];

    identity(test, quantidade);
    copy(copied, test, quantidade);
    shuffle(copied, quantidade);

    reset();
    printf("Começou!\n");
    start();
    insertionSort(copied, quantidade);
    stop();
    printf("Acabou! Verificando...\n");
    if (!compare(copied, test, quantidade))
    {
        printf("Ordenado!!!\n");
    }
    
    printf("\nTempo de execução: %lfs (%ld clocks)\n", getElapsedTimeInSeconds(), getElapsedTimeInClocks());

    return 0;
}