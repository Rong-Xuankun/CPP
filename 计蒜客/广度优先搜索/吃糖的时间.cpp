#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, p, c;
int m;
int a, b;
int vis[100001];

typedef struct ANode
{
    int adjvex;            //该边的邻接点编号
    struct ANode *nextarc; //指向下一条边的指针
} ArcNode;                 //边结点的类型

typedef struct VNode
{
    ArcNode *firstarc; //指向第一个边结点
    int time;
} VNode; //邻接表的头结点类型

typedef struct
{
    VNode adjlist[100000]; //邻接表的头结点数组
    int n, e;              //图中的顶点数n和边数e
} AdjGraph;                //完整的图邻接表类型

int bfs(AdjGraph *G)
{
    VNode queue[5000];
    VNode tmp;
    ArcNode *first;
    int max = 0;
    int l = 0;
    int r = 0;

    queue[r] = G->adjlist[c];
    queue[r].time = 1;
    vis[c] = 1;
    r++;

    while (l < r)
    {
        tmp = queue[l];
        l++;

        first = tmp.firstarc;
        while (first != NULL)
        {
            if (vis[first->adjvex] == 0)
            {
                queue[r] = G->adjlist[first->adjvex];
                queue[r].time = tmp.time + 1;
                if (queue[r].time > max)
                    max = queue[r].time;
                vis[first->adjvex] = 1;
                r++;
            }
            first = first->nextarc;
        }
    }

    return max + m;
}

int main()
{
    scanf("%d %d %d", &n, &p, &c);
    scanf("%d", &m);
    AdjGraph *G;
    ArcNode *q, *t;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    G->n = n;
    G->e = p;

    for (int i = 0; i < n; i++)
        G->adjlist[i].firstarc = NULL;

    for (int i = 0; i < p; i++)
    {
        scanf("%d %d", &a, &b);
        q = (ArcNode *)malloc(sizeof(ArcNode));
        q->adjvex = b;
        q->nextarc = G->adjlist[a].firstarc;
        G->adjlist[a].firstarc = q;
        
        t = (ArcNode *)malloc(sizeof(ArcNode));
        t->adjvex = a;
        t->nextarc = G->adjlist[b].firstarc;
        G->adjlist[b].firstarc = t;
    }

    memset(vis, 0, sizeof(vis));
    printf("%d", bfs(G));
    return 0;
}