#include <stdio.h>
#include <stdlib.h>

int n;
int length[21];
int sum = 0;
int is_rectangle = 0;

int partition(int R[], int s, int t)
{
    int i = s, j = t;
    int tmp = R[i];
    while (i < j)
    {
        while (j > i && R[j] <= tmp)
            j--;
        R[i] = R[j];
        while (i < j && R[i] >= tmp)
            i++;
        R[j] = R[i];
    }
    R[i] = tmp;
    return i;
}

void QuickSort(int R[], int s, int t)
{
    int i;
    if (s < t)
    {
        i = partition(R, s, t);
        QuickSort(R, s, i - 1);
        QuickSort(R, i + 1, t);
    }
}
void dfs(int i, int length1, int length2, int length3, int length4)
{
    if (length1 > sum || length2 > sum || length3 > sum || length4 > sum)
    {
        return;
    }

    if (length1 == sum && length2 == sum && length3 == sum && length4 == sum)
    {
        puts("Yes");
        exit(0);
    }

    if (i == n)
    {
        if (length1 == sum && length2 == sum && length3 == sum && length4 == sum)
        {
            puts("Yes");
        }
        else
            puts("No");
        exit(0);
    }
    else
    {
        dfs(i + 1, length1 + length[i], length2, length3, length4);
        dfs(i + 1, length1, length2 + length[i], length3, length4);
        dfs(i + 1, length1, length2, length3 + length[i], length4);
        dfs(i + 1, length1, length2, length3, length4 + length[i]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &length[i]);
        sum += length[i];
    }
    if (sum % 4 != 0)
    {
        puts("No");
        return 0;
    }
    else
    {
        sum /= 4;
        QuickSort(length, 0, n - 1);
        if (length[0] > sum)
        {
            puts("No");
            return 0;
        }
        else
        {
            dfs(1, length[0], 0, 0, 0);
            if (is_rectangle)
            {
                puts("Yes");
                return 0;
            }
            else
            {
                puts("No");
                return 0;
            }
        }
    }
    return 0;
}