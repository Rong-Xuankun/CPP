#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

char mat[30][30];
int n, m, ans = 1e9, step[4][2] = {1, 0, -1, 0, 0, 1, 0, -1}, vst[30][30], dx, dy;

int in(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
int abs(int x)
{
    return x > 0 ? x : -x;
}
int h(int x, int y)
{
    return abs(dx - x) + abs(dy - y);
}
void dfs(int x, int y, int d)
{
    if (mat[x][y] == '*')
    {
        ans = min(ans, d);
        return;
    }
    if (d + h(x, y) >= ans)
        return;
    vst[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + step[i][0];
        int ty = y + step[i][1];
        if (in(tx, ty) && mat[tx][ty] != '#' && !vst[tx][ty])
        {
            dfs(tx, ty, d + 1);
        }
    }
    vst[x][y] = 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", mat[i]);
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '*')
                dx = i, dy = j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '@')
            {
                dfs(i, j, 0);
                printf("%d\n", ans == 1e9 ? -1 : ans);
            }
        }
    }
    return 0;
}