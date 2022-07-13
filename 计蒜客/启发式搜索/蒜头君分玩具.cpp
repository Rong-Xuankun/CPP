#include <stdio.h>

int n;
int like[20][20];
int vis[20];
int max = 0;

int h(int s)
{
    if (s >= n)
        return 0;
    int sum = 0;
    for (int i = s; i < n; i++)
    {
        int max_like = 0;
        for (int j = 0; j < n; j++)
        {
            if (like[i][j] >= max_like)
                max_like = like[i][j];
        }
        sum += max_like;
    }
    return sum;
}

void dfs(int i, int ans)
{
    if (i == n)
    {
        if (ans > max)
            max = ans;
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (ans > max)
            max = ans;
        if (vis[j] == 0)
        {
            if ((ans + h(i)) <= max)
            {
                return;
            }
            else
            {
                vis[j] = 1;
                dfs(i + 1, ans + like[i][j]);
                vis[j] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &like[i][j]);
        }
    }
    dfs(0, 0);
    printf("%d", max);
    return 0;
}