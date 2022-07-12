#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char graph[201][201];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int vis[201][201][15];
int M, N, T;
int flag = 0;
int start_x, start_y;

typedef struct
{
    int x;
    int y;
    int chakela;
    int step;
} naruto;

int in(int x, int y)
{
    return x >= 0 && x < M && y >= 0 && y < N;
}

int bfs(int start_x, int start_y)
{
    naruto queue[80000];
    naruto now;
    int l = 0;
    int r = 0;

    queue[r].x = start_x;
    queue[r].y = start_y;
    queue[r].chakela = T;
    queue[r].step = 0;
    r++;

    while (l < r)
    {
        now = queue[l];
        l++;

        for (int i = 0; i < 4; i++)
        {
            int nx = now.x + dir[i][1];
            int ny = now.y + dir[i][0];
            if (!in(nx, ny) || vis[nx][ny][now.chakela] == 1)
                continue;
            if (graph[nx][ny] == '#' && now.chakela > 0 && vis[nx][ny][now.chakela - 1] == 0)
            {
                queue[r].x = nx;
                queue[r].y = ny;
                queue[r].chakela = now.chakela - 1;
                queue[r].step = now.step + 1;
                r++;
                vis[nx][ny][queue[r].chakela] = 1;
                if (graph[nx][ny] == '+')
                {
                    flag = 1;
                    break;
                }
            }
            else if(graph[nx][ny] != '#' && vis[nx][ny][now.chakela] == 0)
            {
                queue[r].x = nx;
                queue[r].y = ny;
                queue[r].chakela = now.chakela;
                queue[r].step = now.step + 1;
                r++;
                vis[nx][ny][queue[r].chakela] = 1;
                if (graph[nx][ny] == '+')
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
            return now.step;
    }
    return 0;
}

int main()
{
    scanf("%d %d %d", &M, &N, &T);
    for (int i = 0; i < M; i++)
    {
        gets(graph[i]);
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] == '@')
            {
                start_x = i;
                start_y = j;
                break;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    vis[start_x][start_y][T] = 1;
    printf("%d", bfs(start_x, start_y));
    return 0;
}