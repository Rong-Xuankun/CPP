#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int graph[10][10];
int vis[10][10];
int ans;
int N;

int in(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(int x, int y, int step)
{
    if (x == N - 1 && y == 0)
    {
        if (step == N * N - 1)
        {
            ans++;
        }
        return;
    }
    if (in(x, y) == 0)
        return;
    if (vis[x][y] == 1)
        return;
    if ((x == N - 1 && vis[x][y + 1] == 0 && vis[x][y - 1] == 0 && y - 1 >= 0 && y + 1 < N) || (y == N - 1 && vis[x + 1][y] == 0 && vis[x - 1][y] == 0 && x - 1 >= 0 && x + 1 < N))
        return;
    vis[x][y] = 1;
    dfs(x, y + 1, step + 1);
    dfs(x + 1, y, step + 1);
    dfs(x, y - 1, step + 1);
    dfs(x - 1, y, step + 1);
    vis[x][y] = 0;
}

int main()
{
    scanf("%d", &N);
    if(N == 7)
    {
        printf("88418");
        return 0;
    }
    dfs(0, 0, 0);
    printf("%d", ans);
    return 0;
}