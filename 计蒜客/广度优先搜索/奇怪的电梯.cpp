#include <stdio.h>
#include <string.h>

typedef struct
{
    int x;
    int step;
} location;

int n, A, B;
int vis[201];
int K[201];

int bfs(int A, int B)
{
    location queue[400];
    int l = 0;
    int r = 0;
    location now;
    queue[r].x = A;
    queue[r].step = 0;
    r++;
    while (l < r)
    {
        now = queue[l];
        l++;
        if (vis[now.x] == 1)
            continue;
        vis[now.x] = 1;
        if (now.x == B)
            return now.step;
        for (int i = 0; i < 2; i++)
        {
            if (i == 0)
                queue[r].x = now.x + K[now.x];
            else if (i == 1)
            {
                if (now.x > K[now.x])
                    queue[r].x = now.x - K[now.x];
                else
                break;
            }
            queue[r].step = now.step + 1;
            r++;
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d %d", &n, &A, &B);
    for (int i = 1; i <= n; i++)
        scanf("%d", &K[i]);
    memset(vis, 0, sizeof(vis));
    printf("%d", bfs(A, B));
}