#include <stdio.h>
#include <string.h>

typedef struct
{
    int x;
    int step;
} location;

int n, A, B;
int vis[5001];

int bfs(int A, int B)
{
    location queue[10000];
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
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
                queue[r].x = now.x + 1;
            else if (i == 1)
                queue[r].x = now.x - 1;
            else
            {
                if (now.x * 2 > n + 1)
                    continue;
                else
                    queue[r].x = now.x * 2;
            }
            queue[r].step = now.step + 1;
            r++;
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d %d", &n, &A, &B);
    memset(vis, 0, sizeof(vis));
    printf("%d", bfs(A, B));
}