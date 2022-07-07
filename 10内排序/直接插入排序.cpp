#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct
{
    KeyType key;
    int data;
} RecType;

void InsertSort(RecType R[], int n)
{
    int i, j;
    RecType tmp;
    for (i = 1; i < n; i++)
    {
        if (R[i].key < R[i - 1].key)
        {
            tmp = R[i];
            j = i - 1;
            do
            {
                R[j + 1] = R[j];
                j--;
            } while (j >= 0 && R[j].key > tmp.key);
            R[j + 1].key = tmp.key;
        }
    }
}

void BinInsertSort(RecType R[], int n)
{
    int i, j, high, low, mid;
    RecType tmp;
    for (i = 1; i < n; i++)
    {
        if (R[i].key < R[i - 1].key)
        {
            tmp = R[i];
            low = 0;
            high = i - 1;
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (tmp.key < R[mid].key)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (j = i - 1; j > high; j--)
                R[j + 1] = R[j];
            R[high + 1] = tmp;
        }
    }
}