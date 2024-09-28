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

#endif