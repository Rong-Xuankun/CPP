#include <stdio.h>
#include <stdlib.h>

char graph[9][9];

int check(int x, int y, int t)
{
    for (int i = 0; i < 9; i++)
    {
        if (graph[x][i] == (t + '0') || graph[i][y] == (t + '0'))
        {
            return 0;
        }
    }

    int level[3] = {0, 3, 6};
    for (int x1 = level[x / 3]; x1 < level[x / 3] + 3; x1++)
    {
        for (int y1 = level[y / 3]; y1 < level[y / 3] + 3; y1++)
        {
            if (graph[x1][y1] == (t + '0'))
                return 0;
        }
    }

    return 1;
}

void dfs(int x, int y)
{
    if (x == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%c ", graph[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }

    if (graph[x][y] == '*')
    {
        for (int i = 1; i < 10; i++)
        {
            if (check(x, y, i))
            {
                graph[x][y] = (i + '0');
                dfs(x + (y + 1) / 9, (y + 1) % 9);
            }
        }
        graph[x][y] = '*';
    }
    else
    {
        dfs(x + (y + 1) / 9, (y + 1) % 9);
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%c ", &graph[i][j]);
        }
    }

    dfs(0, 0);
    return 0;
}