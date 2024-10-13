#include "inc/base.h"

int main()
{
    int test[50];
    int copied[50];

    identity(test, 50);
    copy(copied, test, 50);
    shuffle(copied, 50);
    print(test, 50);
    print(copied, 50);
    printf("Existem %d valores na posição errada.\n", compare(copied, test, 50));

    return 0;
}