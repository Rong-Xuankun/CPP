#include <stdio.h>
#include <string.h>
#define maxn 1001
#define maxm 10101
#define min(a, b) (((a) < (b)) ? (a) : (b))

const int inf = 0x3f3f3f3f;
struct edge
{
    int v, w, next;
} e[maxm * 2];

int p[maxn], eid, n, m, s, d[maxn], vis[maxn];

void insert(int u, int v, int w)
{
    struct edge t = {v, w, p[u]};
    e[eid] = t;
    p[u] = eid++;
}
void insert2(int u, int v, int w)
{
    insert(u, v, w);
    insert(v, u, w);
}

int main()
{
    scanf("%d%d", &n, &m); // s 是源点
    memset(p, -1, sizeof(p));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        insert2(u, v, w);
    }
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mind = inf;
        int u = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && d[j] < mind)
            {
                mind = d[j];
                u = j;
            }
        }
        if (mind == inf)
        {
            break;
        }
        vis[u] = 1;
        for (int j = p[u]; j != -1; j = e[j].next)
        {
            int v = e[j].v;
            d[v] = min(d[v], d[u] + e[j].w);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", d[i]);
    }
    return 0;
}