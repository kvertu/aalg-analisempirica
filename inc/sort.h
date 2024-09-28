#ifndef SORT_H
#define SORT_H

void insertionSort(int * v, int n)
{
    for (int j = 1; j < n; j++)
    {
        int key = v[j];
        int i = j - 1;
        while (i >= 0 && v[i] > key)
        {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
    }
}

void selectionSort(int * v, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min]) min = j;
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

#endif