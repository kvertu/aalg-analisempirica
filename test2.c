#include "inc/base.h"
#include "inc/sort.h"

#define ARRAY_SIZE 300000

int main()
{
    int test[ARRAY_SIZE];
    int copied[ARRAY_SIZE];

    identity(test, ARRAY_SIZE);
    copy(copied, test, ARRAY_SIZE);
    shuffle(copied, ARRAY_SIZE);
    print(copied, ARRAY_SIZE);
    insertionSort(copied, ARRAY_SIZE);
    print(copied, ARRAY_SIZE);

    return 0;
}