/* 本质上是迷宫搜索算法和马覆盖点算法的结合 */
/* 实际操作上按照迷宫搜索来做，但是按照马的行进顺序来走 */

#include <stdio.h>
#include <string.h>
#define M 10
#define N 9

int dir[8][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};
int vis[M][N];
char maze[M][N];
int start_x, start_y;

int in(int x, int y)
{
    return x >= 0 && x < M && y >= 0 && y < N;
}

int dfs(int x, int y)
{
    vis[x][y] = 1;
    if (maze[x][y] == 'T')
    {
        return 1;
    }
    for (int i = 0; i < 8; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] != '#')
        {
            if (dfs(tx, ty))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    for (int i = 0; i < M; i++)
    {
        gets(maze[i]);
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (maze[i][j] == 'S')
            {
                start_x = i;
                start_y = j;
            }
        }
    }

    if (dfs(start_x, start_y))
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
}