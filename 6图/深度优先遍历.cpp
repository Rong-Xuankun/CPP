#include "1邻接表存储方法.cpp"
#define MAX 50

int visited[MAX] = {0};

void DFS(AdjGraph *G, int v)
{
    ArcNode *p;
    visited[v] = 1;
    printf("%d ", v);
    p = G->adjlist[v].firstarc;
    while (p != NULL)
    {
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

void ExistPath(AdjGraph *G, int u, int v, bool &has)
{
    int w;
    ArcNode *p;
    visited[u] = 1;
    if (u == v)
    {
        has = true;
        return;
    }
    p = G->adjlist->firstarc;
    while (p != NULL)
    {
        w = p->adjvex;
        if (visited[w] == 0)
            ExistPath(G, w, v, has);
        p = p->nextarc;
    }
}

void FindAllPath(AdjGraph *G, int u, int v, int path[], int d)
{
    int w, i;
    ArcNode *p;
    d++;
    path[d] = u;
    if (u == v && d >= 0)
    {
        for (i = 0; i <= d; i++)
            printf("%2d", path[i]);
        printf("\n");
    }
    p = G->adjlist[u].firstarc;
    while (p != NULL)
    {
        w = p->adjvex;
        if (visited[w] == 0)
            FindAllPath(G, w, v, path, d);
        p = p->nextarc;
    }
    visited[u] = 0;
}