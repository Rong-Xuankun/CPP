#include <stdio.h>
#include <string.h>
int main()
{
    int du[1001];
    int graph[1001][1001];
    int father[1001];
    int t, n, x, y;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        memset(du, 0, sizeof(du));
        memset(graph, 0, sizeof(graph));
        memset(father, 0, sizeof(father));
        for (int j = 0; j < n - 1; j++)
        {
            scanf("%d %d", &x, &y);
            father[y] = x;
            graph[x][du[x]] = y;
            du[x]++;
        }
        int count = 0;
        int is = 0;
        for (int j = 1; j <= n; j++)
        {
            if (father[j] == 0 && du[j] == 0)
            {
                printf("0\n");
                break;
            }
            else
            {
                is = 0;
                if (du[j] < du[father[j]])
                {
                    continue;
                }
                for (int k = 0; k < du[j]; k++)
                {
                    if (du[j] < du[graph[j][k]])
                    {
                        is = 1;
                        break;
                    }
                }
                if (is == 1)
                    continue;
            }
            count++;
        }
        printf("%d\n", count);
    }
}