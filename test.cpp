#include <stdio.h>
#include <stdlib.h>
int n, m, T, l, r;
char maze[210][210];
int vis[210][210][11];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int in(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

struct node
{
    int x, y, d, c;
} q[40010];
int bfs(int sx, int sy)
{
    l = 0, r = 0;
    struct node t = {sx, sy, 0, T};
    q[r++] = t;
    vis[sx][sy][t.c] = 1;
    while (l < r)
    {
        struct node now = q[l++];
        if (maze[now.x][now.y] == '@')
        {
            return now.d;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = now.x + dir[i][0];
            int ty = now.y + dir[i][1];
            /*if (in(tx, ty) && maze[tx][ty] != '*' && !vis[tx][ty]) {
                vis[tx][ty] = 1;
                struct node t = {tx, ty, now.d + 1};
                q[r++] = t;
            }*/
            if (in(tx, ty) && maze[tx][ty] == '#' && !vis[tx][ty][now.c] && now.c > 0)
            {
                vis[tx][ty][now.c] = 1;
                struct node t = {tx, ty, now.d + 1, now.c - 1};
                q[r++] = t;
            }
            if (in(tx, ty) && maze[tx][ty] != '#' && !vis[tx][ty][now.c])
            {
                vis[tx][ty][now.c] = 1;
                struct node t = {tx, ty, now.d + 1, now.c};
                q[r++] = t;
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d%d", &n, &m, &T);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", maze[i]);
    }
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '+')
            {
                x = i;
                y = j;
            }
        }
    }
    printf("%d\n", bfs(x, y));

    // system("PAUSE");
    return 0;
}