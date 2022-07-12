#include <stdio.h>
#include <string.h>

int M, N;
char maze[2001][2001];
int start_x, start_y;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int vis[2001][2001][2];

typedef struct
{
    int x;
    int y;
    int step;
    int has_key;
} location;

int in(int x, int y)
{
    return x >= 0 && x < M && y >= 0 && y < N;
}

int bfs1(int start_x, int start_y)
{
    location queue[4000000];
    int l = 0;
    int r = 0;
    location now;

    queue[r].x = start_x;
    queue[r].y = start_y;
    queue[r].step = 0;
    queue[r].has_key = 0;
    vis[start_x][start_y][0] = 1;
    r++;

    while (l < r)
    {
        now = queue[l];
        l++;

        for (int i = 0; i < 4; i++)
        {
            int next_x = now.x + dir[i][0];
            int next_y = now.y + dir[i][1];
            if (maze[next_x][next_y] != '#' && in(next_x, next_y) && vis[next_x][next_y][now.has_key] == 0)
            {
                vis[next_x][next_y][now.has_key] = 1;
                if (maze[next_x][next_y] == 'P')
                {
                    queue[r].x = next_x;
                    queue[r].y = next_y;
                    queue[r].step = now.step + 1;
                    queue[r].has_key = 1;
                    vis[next_x][next_y][queue[r].has_key] = 1;
                    r++;
                }
                else if (maze[next_x][next_y] == 'T' && now.has_key == 1)
                {
                    return now.step + 1;
                }
                else
                {
                    queue[r].x = next_x;
                    queue[r].y = next_y;
                    queue[r].step = now.step + 1;
                    queue[r].has_key = now.has_key;
                    vis[next_x][next_y][now.has_key] = 1;
                    r++;
                }
            }
            else
                continue;
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d", &M, &N);
    getchar();
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
    memset(vis, 0, sizeof(vis));
    printf("%d", bfs1(start_x, start_y));
    return 0;
}