#include <cstdio>
#include <cstring>
#include <memory>
#include <iostream>
#include <queue>

using namespace std;

#define MAXNUM INT_MAX
#define SIZE 9
#define ZeroSet queue<int>

int pathNum = 0;

void getInDegree(int graph[][SIZE], int *inDegree, int size);
void showPath(int path[]);
void getZS(int path[], int k, int graph[][SIZE], queue<int> zs, queue<int> &newZS);
void topSort(int graph[][SIZE], int inDegree[], int path[], queue<int> &zs, int k);

int main(void)
{
    int graph[SIZE][SIZE] = {
        0, 0, 1, 0, 0, 0, 0, 1, 0,
        0, 0, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 1, 0, 0};
    int path[SIZE] = {0};
    int inDegree[SIZE] = {0};
    queue<int> zs;

    zs.push(0);
    zs.push(1);

    getInDegree(graph, inDegree, SIZE);
    topSort(graph, inDegree, path, zs, 0);

    return 0;
}

void getInDegree(int graph[][SIZE], int *inDegree, int size)
{
    memset(inDegree, 0, sizeof(int) * size);
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (graph[j][i] == 1)
                inDegree[i]++;
        }
    }
}

void topSort(int graph[][SIZE], int inDegree[], int path[], queue<int> &zs, int k)
{
    queue<int> newZS;
    int temp = (int)zs.size();
    int counter = 0;

    if (k == SIZE)
    {
        pathNum++;
        showPath(path);
        return;
    }
    //递归基准情形，如果所有结点都在path中，输出所有结点
    if (temp == 0)
    {
        cout << "Can't Topsort" << endl;
        return;
    }
    //如果没有入度为0的结点，且不是所有结点都在path中
    //则存在环路
    while (counter < temp)
    {
        while (!newZS.empty())
            newZS.pop();
        //清空mewZS
        path[k] = zs.front();
        zs.pop();
        zs.push(path[k]);
        //将zs中的一个元素移到最后，并将这个结点作为path的下一条路径
        getZS(path, k, graph, zs, newZS);
        //获取将这个结点加入path后的新的0入度的结点的集合
        topSort(graph, inDegree, path, newZS, k + 1);
        //递归调用
        counter++;
    }
    //每一次循环从zs集合中选择一个，加入path中
    //直到遍历完全所有的集合
}

void showPath(int path[])
{ //输出路径
    cout << pathNum << ':';
    for (int i = 0; i < SIZE; i++)
        printf("C%d,", path[i] + 1);
    putchar('\n');
}

void getZS(int path[], int k, int graph[][SIZE], queue<int> zs, queue<int> &newZS)
{ //获得新的zs集合
    int isINpath[SIZE] = {0};
    bool isZeroDeg = true;

    for (int i = 0; i < k + 1; i++)
        isINpath[path[i]] = 1;
    //初始化isINpath
    while (zs.size() != 1)
    {
        newZS.push(zs.front());
        zs.pop();
    }
    //将原来zs集合中的除了新加入path的结点都加入newZS
    for (int i = 0; i < SIZE; i++)
    {
        if (graph[zs.front()][i])
        { //在新加入path的结点指向的结点中选择还要加入newZS中的结点
            isZeroDeg = true;
            for (int j = 0; j < SIZE; j++)
            {
                if (!isINpath[j] && graph[j][i])
                {
                    isZeroDeg = false;
                    break;
                }
            }
            if (isZeroDeg)
                zs.push(i);
            //选择符合要求的结点
        }
    }
    zs.pop();
    //将新加入path的结点弹出
    while (!zs.empty())
    { //将剩下所有结点加入newZS
        newZS.push(zs.front());
        zs.pop();
    }
}
