#include <stdio.h>
#include <stdlib.h>
#define MAXV 10
#define INF 32767

typedef int InfoType;

typedef struct
{
    int no;        //顶点的编号
    InfoType info; //顶点的其他信息
} VertexType;      //顶点的类型

typedef struct
{
    int edges[MAXV][MAXV]; //邻接矩阵数组
    int n, e;              //顶点数，边数
    VertexType vex[MAXV];  //存放顶点信息
} MatGraph;                //完整的图邻接矩阵类型