#include <stdio.h>
#include <string.h>

int n, m;
int cnt = 0;
char graph[501][501];

void dfs(int x, int y)
{
    for (int i = 0; i < m; i++)
    {
        if (graph[x][i] == '1')
        {
            graph[x][i] = '0';
            dfs(x, i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (graph[i][y] == '1')
        {
            graph[i][y] = '0';
            dfs(i, y);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    getchar();
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < n; i++)
        gets(graph[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '1')
            {
                cnt++;
                dfs(i, j);
            }
        }
    }

    printf("%d", cnt);
    return 0;
}
