#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 32767

int n, m;
float graph[210][210];
float sec_short;
int first_path[1100];
int sec_path[1100];

float Dijkstra2(int v)
{
    float dist[210], MINdis;
    int path[210];
    int S[210];
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
        MINdis = INF;
        for (j = 1; j <= n; j++)
        {
            if (S[j] == 0 && dist[j] < MINdis)
            {
                u = j;
                MINdis = dist[j];
            }
        }
        S[u] = 1;
        for (j = 1; j <= n; j++)
        {
            if (S[j] == 0)
            {
                if (graph[u][j] < INF && dist[u] + graph[u][j] < dist[j])
                {
                    dist[j] = dist[u] + graph[u][j];
                    path[j] = u;
                }
            }
        }
    }

    return dist[n];
}

void Dijkstra(int v)
{
    float dist[1100], MINdis, D;
    int path[1100];
    int S[1001];
    int i, j, u, t;
    float tmp;
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
        MINdis = INF;
        for (j = 1; j <= n; j++)
        {
            if (S[j] == 0 && dist[j] < MINdis)
            {
                u = j;
                MINdis = dist[j];
            }
        }
        S[u] = 1;
        for (j = 1; j <= n; j++)
        {
            if (S[j] == 0)
            {
                if (graph[u][j] < INF && (dist[u] + graph[u][j]) < dist[j])
                {
                    dist[j] = dist[u] + graph[u][j];
                    path[j] = u;
                }
            }
        }
    }
    sec_short = INF;
    t = path[n];
    i = 0;
    first_path[i] = n;
    i++;
    while (t != 1)
    {
        first_path[i] = t;
        t = path[t];
        i++;
    }

    first_path[i] = 1;

    while (i > 0)
    {
        tmp = graph[first_path[i]][first_path[i - 1]];
        graph[first_path[i]][first_path[i - 1]] = INF;
        graph[first_path[i - 1]][first_path[i]] = INF;
        D = Dijkstra2(1);
        if (D < sec_short)
        {
            sec_short = D;
        }
        graph[first_path[i]][first_path[i - 1]] = tmp;
        graph[first_path[i - 1]][first_path[i]] = tmp;
        i--;
    }
    printf("%.2f\n", sec_short);
}

int main()
{
    int row[1100];
    int col[1100];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &row[i], &col[i]);
    }
    int x, y;
    float d;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &x, &y);
        d = sqrt(1.0 * ((row[x] - row[y]) * (row[x] - row[y]) + (col[x] - col[y]) * (col[x] - col[y])));
        graph[x][y] = d;
        graph[y][x] = d;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0.0;
            }
            else
            {
                if (!graph[i][j])
                    graph[i][j] = INF;
            }
        }
    }
    Dijkstra(1);
    return 0;
}