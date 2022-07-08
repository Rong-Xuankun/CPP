#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct
{
    KeyType key;
    int data;
} RecType;

int partition(RecType R[], int s, int t)
{
    int i = s, j = t;
    RecType tmp = R[i];
    while (i < j)
    {
        while (j > i && R[j].key >= tmp.key)
            j--;
        R[i] = R[j];
        while (i < j && R[i].key <= tmp.key)
            i++;
        R[j] = R[i];
    }
    R[i] = tmp;
    return i;
}

void QuickSort(RecType R[], int s, int t)
{
    int i;
    if (s < t)
    {
        i = partition(R, s, t);
        QuickSort(R, s, i - 1);
        QuickSort(R, i + 1, t);
    }
}

