/*
    Teste de diversos tipos de "desordenadores" usando ponteiros de função
*/

#include "inc/base.h"

void unsort(int * v, int n, void (*shuffler)(int *, int))
{
    (*shuffler)(v, n);
}

int main()
{
    int og[64], clone[64];

    identity(og, 64);
    copy(clone, og, 64);
    unsort(clone, 64, dontChange);
    print(clone, 64);

    return 0;
}