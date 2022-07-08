#include <stdio.h>

typedef struct
{
    long long int left;
    long long int right;
} LINE;

int partition(LINE R[], long long int s, long long int t)
{
    long long int i = s, j = t;
    LINE tmp = R[i];
    while (i < j)
    {
        while (j > i && R[j].right >= tmp.right)
            j--;
        R[i] = R[j];
        while (i < j && R[i].right <= tmp.right)
            i++;
        R[j] = R[i];
    }
    R[i] = tmp;
    return i;
}

void QuickSort(LINE R[], long long int s, long long int t)
{
    long long int i;
    if (s < t)
    {
        i = partition(R, s, t);
        QuickSort(R, s, i - 1);
        QuickSort(R, i + 1, t);
    }
}

int main()
{
    long long int n;
    scanf("%lld", &n);

    LINE line[n];
    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &line[i].left, &line[i].right);
    }
    QuickSort(line, 0, n - 1);
    long long int position = line[0].right, count = 1;
    for (long long int i = 0; i < n; i++)
    {
        if (line[i].right > position && line[i].left >= position)
        {
            count++;
            position = line[i].right;
        }
    }
    printf("%lld", count);
    return 0;
}