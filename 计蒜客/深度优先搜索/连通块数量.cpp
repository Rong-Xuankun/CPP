#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visited[20001];

typedef struct ANode
{
    int adjvex;            //该边的邻接点编号
    struct ANode *nextarc; //指向下一条边的指针
} ArcNode;                 //边结点的类型

typedef struct VNode
{
    ArcNode *firstarc; //指向第一个边结点
} VNode;               //邻接表的头结点类型

typedef struct
{
    VNode adjlist[20000]; //邻接表的头结点数组
    int n, e;             //图中的顶点数n和边数e
} AdjGraph;               //完整的图邻接表类型

void CreateAdj(AdjGraph *G, int a, int b)
{
    ArcNode *p, *q;
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = b;
    p->nextarc = G->adjlist[a].firstarc;
    G->adjlist[a].firstarc = p;
    q = (ArcNode *)malloc(sizeof(ArcNode));
    q->adjvex = a;
    q->nextarc = G->adjlist[b].firstarc;
    G->adjlist[b].firstarc = q;
}

void DFS(AdjGraph *G, int v)
{
    ArcNode *p;
    visited[v] = 1;
    p = G->adjlist[v].firstarc;
    while (p != NULL)
    {
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

int main()
{
    int n, m, a, b;
    int cnt = 0;
    scanf("%d %d", &n, &m);
    AdjGraph *G;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (int i = 0; i < n; i++)
        G->adjlist[i].firstarc = NULL;
    G->n = n;
    G->e = m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        CreateAdj(G, a - 1, b - 1);
    }

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            cnt++;
            DFS(G, i);
        }
    }

    printf("%d", cnt);
    return 0;
}