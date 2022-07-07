#include <stdio.h>
#include <stdlib.h>
#define size 9
#define MAX 100

typedef struct
{
    int data;
    int inDegree;
} ZeroSet;

ZeroSet Qu[MAX];
int front = -1, rear = -1;

int graph[size][size] = {
    0, 0, 1, 0, 0, 0, 0, 1, 0,
    0, 0, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 1, 0, 0};

void getDegree(ZeroSet zs[size]) //获取每个结点的入度
{
    int count;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
            if (graph[j][i] == 1)
                count++;
        zs[i].inDegree = count;
    }
}

void CreateZs(ZeroSet zs[size])
{
    for (int i = 0; i < size; i++)
        zs[i].data = i + 1;
}

void topSort(int graph[size][size], int path[], ZeroSet zs[size], int k)
{
    int i;
    if (k == 9)
        for (i = 1; i < size; i++)
            printf("C%d ", path[i]);
    for (i = 0; i < size; i++)
    {
        if (zs[i].inDegree == 0)
        {
            rear++;
            Qu[rear] = zs[i];
        }
    }
    front++;
    path[k] = Qu[front].data;
    for (i = 0; i < size; i++)
        if (graph[path[k]][i] == 1)
            zs[i].inDegree--;
    k++;
}

int main()
{
    int i;
    int path[size];
    ZeroSet zs[size];
    CreateZs(zs);
    getDegree(zs);
    for (i = 0; i < size; i++)
        printf("%d,%d\n", zs[i].data, zs[i].inDegree);
    topSort(graph, path, zs, 1);
}