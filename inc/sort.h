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

/*
    Maior tamanho que o mergeSort consegue ordenar é 698558

    É provável que isso seja uma limitação por usar estruturas auxiliares (os vetores left e right na função merge)
*/
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

void maxHeapify(int * v, int n, int i)
{
    int temp, maximum, left, right;

    maximum = i;
    right = 2 * i + 2;
    left = 2 * i + 1;

    if (left < n && v[left] > v[maximum])
        maximum = left;

    if (right < n && v[right] > v[maximum])
        maximum = right;

    if (maximum != i)
    {
        temp = v[i];
        v[i] = v[maximum];
        v[maximum] = temp;
        maxHeapify(v, n, maximum);
    }
}

void heapSort(int * v, int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(v, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        maxHeapify(v, i, 0);
    }
}

int partition(int * v, int p, int r)
{
    int x = v[r]; // x é o pivô
    int i = p - 1;

    for (int j = p; j < r; j++)
        if (v[j] <= x)
        {
            i++;

            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }

    int temp = v[i + 1];
    v[i + 1] = v[r];
    v[r] = temp;

    return i + 1;
}

void quickSort(int * v, int p, int r)
{
    if (p < r)
    {
        int q = partition(v, p, r);
        quickSort(v, p, q - 1);
        quickSort(v, q + 1, r);
    }
}

#endif