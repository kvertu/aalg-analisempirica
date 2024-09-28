#include "inc/base.h"
#include "inc/sort.h"
#include "inc/timer.h"

#define ARRAY_SIZE 1000000

int main()
{
    int test[ARRAY_SIZE];
    int copied[ARRAY_SIZE];

    identity(test, ARRAY_SIZE);
    copy(copied, test, ARRAY_SIZE);
    shuffle(copied, ARRAY_SIZE);

    reset();
    printf("Começou!\n");
    start();
    insertionSort(copied, ARRAY_SIZE);
    stop();
    printf("Acabou! Verificando...\n");
    if (!compare(copied, test, ARRAY_SIZE))
    {
        printf("Ordenado!!!\n");
    }
    
    printf("\nTempo de execução: %lfs (%ld clocks)\n", getElapsedTimeInSeconds(), getElapsedTimeInClocks());

    return 0;
}