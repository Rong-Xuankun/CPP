#include <stdio.h>
int nowx = 0, nowy = 0, dir = 0;
int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main()
{
    int matrix[110][110];
    int m;
    int n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < m * n; i++)
    {
        printf("%d ", matrix[nowx][nowy]);
        matrix[nowx][nowy] = -1;
        nowx += step[dir][0];
        nowy += step[dir][1];
        if (dir == 0)
        {
            if (nowy == n - 1 || matrix[nowx][nowy + 1] == -1)
            {
                dir = 1;
            }
        }
        else if (dir == 1)
        {
            if (nowx == m - 1 || matrix[nowx + 1][nowy] == -1)
            {
                dir = 2;
            }
        }
        else if (dir == 2)
        {
            if (nowy == 0 || matrix[nowx][nowy - 1] == -1)
            {
                dir = 3;
            }
        }
        else if (dir == 3)
        {
            if (nowx == 0 || matrix[nowx - 1][nowy] == -1)
            {
                dir = 0;
            }
        }
    }
    return 0;
}
