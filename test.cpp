#include <stdio.h>
#include <stdlib.h>

int n, max;
int toy[10], likebest[10], pre[10];
int like[10][10];

void dfs(int x, int ans)
{
    if (x == n + 1)
    {
        if (ans > max)
            max = ans;
        return;
    }
    int i;
    for (i = 1; i <= n; i++)
    {
        if (ans > max)
            max = ans;
        if (toy[i] == 0)
        {
            if ((ans + pre[x]) <= max)
                return;
            else
            {
                toy[i] = 1;
                dfs(x + 1, ans + like[x][i]);
                toy[i] = 0;
            }
        }
    }
}

int main()
{
    int i, j, a, b;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a);
            like[i][j] = a;
        }
    for (i = 1; i <= n; i++)
    {
        b = 0;
        for (j = 1; j <= n; j++)
        {
            b = like[i][j] > b ? like[i][j] : b;
        }
        likebest[i] = b;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            pre[i] += likebest[j];
        }
    }
    dfs(1, 0);
    printf("%d\n", max);

    system("PAUSE");
    return 0;
}