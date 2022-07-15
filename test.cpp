#define _CRT_SECUE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 32767
int n, m;
float graph[201][201];
int apath[201], sec[201];
float secm;
float D2(int v)
{
    int path[201];
    float dist[201], mind;
    int S[201];
    int i, j, u;
    for (i = 1; i <= n; i++)
    {
        dist[i] = graph[v][i];
        S[i] = 0;
        if (graph[i][j] < INF)
            path[i] = v;
        else
            path[i] = -1;
    }
    S[v] = 1;
    path[v] = 0;
    for (i = 0; i < n; i++)
    {
        mind = INF;
        for (j = 1; j <= n; j++)
            if (S[j] == 0 && dist[j] < mind)
            {
                u = j;
                mind = dist[j];
            }
        S[u] = 1;
        for (j = 1; j <= n; j++)
            if (S[j] == 0)
                if (graph[u][j] < INF && dist[u] + graph[u][j] < dist[j])
                {
                    dist[j] = dist[u] + graph[u][j];
                    path[j] = u;
                }
    }
    // printf("%.2f\n", dist[n]);
    return dist[n];
}
void Dijkstra(int v)
{
    int path[1001];
    float dist[1001], mind, d;
    int S[1001];
    int i, j, u;
    for (i = 1; i <= n; i++)
    {
        dist[i] = graph[v][i];
        S[i] = 0;
        if (graph[i][j] < INF)
            path[i] = v;
        else
            path[i] = -1;
    }
    S[v] = 1;
    path[v] = 0;
    for (i = 0; i < n; i++)
    {
        mind = INF;
        for (j = 1; j <= n; j++)
            if (S[j] == 0 && dist[j] < mind)
            {
                u = j;
                mind = dist[j];
            }
        S[u] = 1;
        for (j = 1; j <= n; j++)
            if (S[j] == 0)
                if (graph[u][j] < INF && dist[u] + graph[u][j] < dist[j])
                {
                    dist[j] = dist[u] + graph[u][j];
                    path[j] = u;
                }
    }
    // printf("%.2f", dist[n]);
    secm = INF;
    int k = path[n];
    i = 0;
    apath[i++] = n;
    while (k != 1)
    {
        apath[i] = k;
        k = path[k];
        i++;
    }
    apath[i] = 1;

    for (; i > 0; i--)
    {
        float x;
        x = graph[apath[i]][apath[i - 1]];

        graph[apath[i]][apath[i - 1]] = INF;
        graph[apath[i - 1]][apath[i]] = INF;

        d = D2(1);
        // printf("%.2f", d);
        if (d < secm)
        {
            secm = d;
        }

        graph[apath[i]][apath[i - 1]] = x;
        graph[apath[i - 1]][apath[i]] = x;
    }
    printf("%.2f\n", secm);
}

int main()
{
    int i, j, a, b, x, y;
    int row[1000], col[1000];
    float d;
    scanf("%d %d ", &n, &m);

    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &x, &y);
        row[i] = x;
        col[i] = y;
    }

    for (i = 1; i <= m; i++)
    {
        scanf("%d %d", &a, &b);
        d = sqrt(1.0 * ((row[a] - row[b]) * (row[a] - row[b]) + (col[a] - col[b]) * (col[a] - col[b])));
        graph[a][b] = d;
        graph[b][a] = d;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (j == i)
                graph[i][j] = 0.0;
            else
            {
                if (!graph[i][j])
                    graph[i][j] = INF;
            }
        }
    Dijkstra(1);

    // system("PAUSE");
    return 0;
}