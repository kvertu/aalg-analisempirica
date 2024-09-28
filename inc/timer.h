#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <stdbool.h>

/*
    Váriaveis globais para controle do temporizador
*/

clock_t current;
clock_t elapsed = 0;
bool paused = true;

/*
    Reinicia o temporizador
*/
void reset()
{
    elapsed = 0;
    paused = true;
}

/*
    Inicia/retoma o temporizador, caso esteja pausado
*/
void start()
{
    if (paused)
    {
        current = clock();
        paused = false;
    }
}

/*
    Para o temporizador, caso não esteja pausado
*/
void stop()
{
    if (!paused)
    {
        elapsed = clock() - current + elapsed;
        paused = true;
    }
}

/*
    Retorna o tempo marcado em clocks
*/
clock_t getElapsedTimeInClocks()
{
    return paused ? elapsed : clock() - current + elapsed;
}

double getElapsedTimeInSeconds()
{
    return ((double) getElapsedTimeInClocks()) / CLOCKS_PER_SEC;
}

#endif