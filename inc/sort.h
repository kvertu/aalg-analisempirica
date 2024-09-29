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

void merge(int * v, int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = v[p + i];
    for (j = 0; j < n2; j++)
        right[j] = v[q + 1 + j];
    
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            v[k] = left[i];
            i++;
        }
        else
        {
            v[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        v[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        v[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int * v, int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r) / 2);
        mergeSort(v, p, q);
        mergeSort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

#endif