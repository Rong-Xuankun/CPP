#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct
{
    double x;
    double y;
    double z;
    int step;
} location;

int T, n;
double h, r;
location lct[1000000];
int vis[1001];

double dist(location x1, location x2)
{
    double nx = x1.x - x2.x;
    double ny = x1.y - x2.y;
    double nz = x1.z - x2.z;
    double ans = sqrt(nx * nx + ny * ny + nz * nz);
    return ans;
}

int bfs()
{
    location queue[1001];
    location now;
    int queue_l = 0;
    int queue_r = 0;

    for (int i = 0; i < n; i++)
    {
        if (lct[i].z <= r)
        {
            queue[queue_r] = lct[i];
            queue_r++;
            vis[i] = 1;
        }
    }

    while (queue_l < queue_r)
    {
        now = queue[queue_l];
        queue_l++;

        if ((now.z + r) >= h)
            return now.step;

        for (int i = 0; i < n; i++)
        {
            if (dist(now, lct[i]) <= (2 * r) && dist(now, lct[i]) > 0 && vis[i] == 0)
            {
                queue[queue_r] = lct[i];
                queue[queue_r].step = now.step + 1;
                vis[i] = 1;
                queue_r++;
            }
        }
    }

    return -1;
}

int main()
{
    scanf("%d", &T);
    for (int k = 0; k < T; k++)
    {
        memset(vis, 0, sizeof(vis));
        memset(lct, 0, sizeof(lct));
        scanf("%d %lf %lf", &n, &h, &r);
        for (int j = 0; j < n; j++)
        {
            scanf("%lf %lf %lf", &lct[j].x, &lct[j].y, &lct[j].z);
            lct[j].step = 1;
        }
        printf("%d\n", bfs());
    }

    return 0;
}