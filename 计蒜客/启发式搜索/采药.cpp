#include <stdio.h>
#define N 101
#define max(a, b) (((a) > (b)) ? (a) : (b))

int ans = 0, t, m, a[N], b[N];

int h(int now, int s)
{ // 估价函数
    int sum = 0;
    for (int i = now; i < m; i++)
    {
        if (s >= a[i])
        {
            s -= a[i];
            sum += b[i];
        }
        else
        {
            return sum + b[i] * 1.0 / a[i] * s;
        }
    }
    return sum;
}

void dfs(int i, int sa, int sb)
{
    ans = max(ans, sb);
    if (i == m)
        return;
    if (h(i, sa) + sb <= ans)
        return;
    dfs(i + 1, sa, sb);
    if (a[i] <= sa)
        dfs(i + 1, sa - a[i], sb + b[i]);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    scanf("%d%d", &t, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &a[i], &b[i]);
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (b[i] * a[j] < a[i] * b[j])
            {
                swap(&a[i], &a[j]);
                swap(&b[i], &b[j]);
            }
    dfs(0, t, 0);
    printf("%d\n", ans);
    return 0;
}