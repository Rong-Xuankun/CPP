#include <stdio.h>
#include <string.h>

int vis[101][101];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char maze[101][101];
int cnt = 0;
int R, C;

int in(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

void dfs(int x, int y)
{
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
    getchar();
    for (int i = 0; i < R; i++)
    {
        gets(maze[i]);
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (maze[i][j] == '#' && !vis[i][j])
            {
                cnt++;
                dfs(i, j);
            }
        }
    }

    printf("%d", cnt);
    return 0;
}