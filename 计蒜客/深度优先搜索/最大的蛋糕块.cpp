#include <stdio.h>
#include <string.h>

int vis[1001][1001];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char maze[1001][1001];
int cnt;
int R, C;

int in(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

void dfs(int x, int y)
{
    cnt++; // 这个连通块的大小
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] == '#')
        {
            dfs(tx, ty);
        }
    }
}

int main()
{

    memset(maze, 0, sizeof(maze));
    memset(vis, 0, sizeof(vis));
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
    {
        gets(maze[i]);
    }

    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (maze[i][j] == '#' && !vis[i][j])
            {
                cnt = 0;
                dfs(i, j);
                if (cnt > ans)
                    ans = cnt;
            }
        }
    }

    printf("%d", ans);
    return 0;
}