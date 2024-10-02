/*
    Funções de ordenação

    Parâmetros comuns entre (quase) todas as funções:
        v: vetor a ser ordenado
        n: tamanho do vetor
        comps: quantidade de comparações na ordenação
        perms: quantidade de permutações (trocas) na ordenação
*/
#ifndef SORT_H
#define SORT_H

/*
    Ordenação por inserção
*/
void insertionSort(int * v, int n, long * comps, long * perms)
{
    (*comps) = 0;
    (*perms) = 0;
    for (int j = 1; j < n; j++)
    {
        (*perms)++;
        int key = v[j];
        int i = j - 1;
        (*comps)++;
        while (i >= 0 && v[i] > key)
        {
            (*comps)++;
            (*perms)++;
            v[i + 1] = v[i];
            i--;
        }
        (*perms)++;
        v[i + 1] = key;
    }
}

/*
    Ordenação por inserção
*/
void selectionSort(int * v, int n, long * comps, long * perms)
{
    (*comps) = 0;
    (*perms) = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            (*comps)++;
            if (v[j] < v[min]) min = j;
        }
        
        (*perms)++;
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

/*
    Função de interlacação usada no merge sort

        p: indica o inicio do subvetor a ser intercalado
        q: indica o meio do subvetor a ser intercalado
        r: indica o final do subvetor a ser intercalado
*/
void merge(int * v, int p, int q, int r, long * comps, long * perms)
{
    (*comps) = 0;
    (*perms) = 0;
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    // Cria e preenche os vetores auxiliares com os subvetores em questão
    int left[n1], right[n2];
    for (i = 0; i < n1; i++)
    {
        (*perms)++;
        left[i] = v[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        (*perms)++;
        right[j] = v[q + 1 + j];
    }
        
    i = 0;
    j = 0;
    k = p;

    // Começa a intercalar até um dos subvetores chegar no fim
    (*comps)++;
    while (i < n1 && j < n2)
    {
        (*comps)++;
        if (left[i] <= right[j])
        {
            (*perms)++;
            v[k] = left[i];
            i++;
        }
        else
        {
            (*perms)++;
            v[k] = right[j];
            j++;
        }
        k++;
    }

    // Adiciona o que restar do subvetor left devolta em v (se tiver)
    (*comps)++;
    while (i < n1)
    {
        (*comps)++;
        (*perms)++;
        v[k] = left[i];
        i++;
        k++;
    }

    // Adiciona o que restar do subvetor right devolta em v (se tiver)
    (*comps)++;
    while (j < n2)
    {
        (*comps)++;
        (*perms)++;
        v[k] = right[j];
        j++;
        k++;
    }
}

/*
    Ordenação por intercalação
    Maior tamanho que o mergeSort consegue ordenar é 698558

    É provável que isso seja uma limitação por usar estruturas auxiliares (os vetores left e right na função merge)
*/
void mergeSort(int * v, int p, int r, long * comps, long * perms)
{
    (*comps) = 0;
    (*perms) = 0;
    if (p < r)
    {
        int q = (p + r) / 2; // Determina o meio do vetor

        long c1, c2, c3, p1, p2, p3; // Variáveis temporárias para armazenar a quantidade de comparação e permutações nas funções

        // Recursão
        mergeSort(v, p, q, &c1, &p1);
        mergeSort(v, q + 1, r, &c2, &p2);

        // Intercalação
        merge(v, p, q, r, &c3, &p3);
        (*comps) = c1 + c2 + c3;
        (*perms) = p1 + p2 + p3;
    }
}

/*
    Criação do max-heap
*/
void maxHeapify(int * v, int n, int i, long * comps, long * perms)
{
    (*comps) = 0;
    (*perms) = 0;
    int temp, maximum, left, right;

    maximum = i;
    right = 2 * i + 2;
    left = 2 * i + 1;

    (*comps)++;
    if (left < n && v[left] > v[maximum])
        maximum = left;

    (*comps)++;
    if (right < n && v[right] > v[maximum])
        maximum = right;

    (*comps)++;
    if (maximum != i)
    {
        (*perms)++;
        temp = v[i];
        v[i] = v[maximum];
        v[maximum] = temp;
        long c, p;
        maxHeapify(v, n, maximum, &c, &p);
        (*comps) += c;
        (*perms) += p;
    }
}

/*
    Heap sort
*/
void heapSort(int * v, int n, long * comps, long * perms)
{
    int i;
    (*comps) = 0;
    (*perms) = 0;

    // Transforma o vetor em um max-heap
    for (i = n / 2 - 1; i >= 0; i--)
    {
        long c, p;
        maxHeapify(v, n, i, &c, &p);
        (*comps) += c;
        (*perms) += p;
    }

    for (int i = n - 1; i > 0; i--)
    {
        // Troca o valor da primeira posição com o final da heap
        (*perms)++;
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        // É refeito a transformação do max-heap, mas excluindo a última posição
        long c, p;
        maxHeapify(v, i, 0, &c, &p);
        (*comps) += c;
        (*perms) += p;
    }
}

/*
    Particiona o vetor a partir de um pivô

    Por padrão, o pivô é sempre o elemento na última posição do vetor
    Retorna a posição final do pivô no vetor
*/
int partition(int * v, int p, int r, long * comps, long * perms)
{
    (*comps) = 0;
    (*perms) = 0;
    int x = v[r]; // x é o pivô
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        (*comps)++;
        if (v[j] <= x)
        {
            i++;

            (*perms)++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    (*perms)++;
    int temp = v[i + 1];
    v[i + 1] = v[r];
    v[r] = temp;

    return i + 1;
}

/*
    Quick sort
*/
void quickSort(int * v, int p, int r, long * comps, long * perms)
{
    (*comps) = 0;
    (*perms) = 0;
    if (p < r)
    {
        int q = partition(v, p, r, comps, perms); // Particionamento do vetor
        long c1, c2, p1, p2;

        // Recursão
        quickSort(v, p, q - 1, &c1, &p1);
        quickSort(v, q + 1, r, &c2, &p2);
        (*comps) += c1 + c2;
        (*perms) += c1 + c2;
    }
}

#endif