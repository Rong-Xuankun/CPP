#include <stdio.h>
#include <stdlib.h>
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
    VNode adjlist[101]; //邻接表的头结点数组
    int n, e;           //图中的顶点数n和边数e
} AdjGraph;             //完整的图邻接表类型

int main()
{
    int n, m;
    int a, x, y;
    scanf("%d %d", &n, &m);
    AdjGraph *G;
    ArcNode *p, *q;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (int i = 0; i < n; i++)
        G->adjlist[i].firstarc = NULL;
    G->n = n;
    G->e = m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &x, &y);
        p = (ArcNode *)malloc(sizeof(ArcNode));
        q = (ArcNode *)malloc(sizeof(ArcNode));
        if (a == 0)
        {
            p->adjvex = y;
            p->nextarc = G->adjlist[x].firstarc;
            G->adjlist[x].firstarc = p;
        }
        else
        {
            p->adjvex = y;
            p->nextarc = G->adjlist[x].firstarc;
            G->adjlist[x].firstarc = p;
            q->adjvex = x;
            q->nextarc = G->adjlist[y].firstarc;
            G->adjlist[y].firstarc = q;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        p = G->adjlist[i].firstarc;
        while (p != NULL)
        {
            printf(" %d", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
    return 0;
}