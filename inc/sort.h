#ifndef SORT_H
#define SORT_H

long insertionSort(int * v, int n)
{
    long comparacoes = 0;
    for (int j = 1; j < n; j++)
    {
        int key = v[j];
        int i = j - 1;
        comparacoes++;
        while (i >= 0 && v[i] > key)
        {
            comparacoes++;
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
    }
    return comparacoes;
}

long selectionSort(int * v, int n)
{
    long comparacoes = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            comparacoes++;
            if (v[j] < v[min]) min = j;
        }
            
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
    return comparacoes;
}

long merge(int * v, int p, int q, int r)
{
    long comparacoes = 0;
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

    comparacoes++;
    while (i < n1 && j < n2)
    {
        comparacoes++;
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

    comparacoes++;
    while (i < n1)
    {
        comparacoes++;
        v[k] = left[i];
        i++;
        k++;
    }

    comparacoes++;
    while (j < n2)
    {
        comparacoes++;
        v[k] = right[j];
        j++;
        k++;
    }

    return comparacoes;
}

/*
    Maior tamanho que o mergeSort consegue ordenar é 698558

    É provável que isso seja uma limitação por usar estruturas auxiliares (os vetores left e right na função merge)
*/
long mergeSort(int * v, int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r) / 2);
        long c1 = mergeSort(v, p, q);
        long c2 = mergeSort(v, q + 1, r);
        return merge(v, p, q, r) + c1 + c2;
    }
    return 0;
}

long maxHeapify(int * v, int n, int i)
{
    long comparacoes = 0;
    int temp, maximum, left, right;

    maximum = i;
    right = 2 * i + 2;
    left = 2 * i + 1;

    comparacoes++;
    if (left < n && v[left] > v[maximum])
        maximum = left;

    comparacoes++;
    if (right < n && v[right] > v[maximum])
        maximum = right;

    comparacoes++;
    if (maximum != i)
    {
        temp = v[i];
        v[i] = v[maximum];
        v[maximum] = temp;
        return maxHeapify(v, n, maximum) + comparacoes;
    }
    return comparacoes;
}

long heapSort(int * v, int n)
{
    int i;
    long comparacoes = 0;

    for (i = n / 2 - 1; i >= 0; i--)
        comparacoes += maxHeapify(v, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        comparacoes += maxHeapify(v, i, 0);
    }
    return comparacoes;
}

int partition(int * v, int p, int r, long * comparacoes)
{
    int x = v[r]; // x é o pivô
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        (*comparacoes)++;
        if (v[j] <= x)
        {
            i++;

            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int temp = v[i + 1];
    v[i + 1] = v[r];
    v[r] = temp;

    return i + 1;
}

long quickSort(int * v, int p, int r)
{
    if (p < r)
    {
        long comparacoes = 0;
        int q = partition(v, p, r, &comparacoes);
        comparacoes += quickSort(v, p, q - 1);
        comparacoes += quickSort(v, q + 1, r);
        return comparacoes;
    }
    return 0;
}

#endif