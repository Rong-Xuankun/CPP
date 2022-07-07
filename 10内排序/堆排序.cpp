#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct
{
    KeyType key;
    int data;
} RecType;

void sift(RecType R[], int low, int high)
{
    int i = low, j = 2 * i;
    RecType tmp = R[i];
    while (j <= high)
    {
        if (j < high && R[j].key < R[j + 1].key)
            j++;
        if (tmp.key < R[j].key)
        {
            R[i] = R[j];
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
    R[i] = tmp;
}
void HeapSort(RecType R[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        sift(R, i, n);
    for (i = n; i >= 2; i--)
    {
        // swap(R[1], R[i]);
        sift(R, 1, i - 1);
    }
}