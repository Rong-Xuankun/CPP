#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

/*  二叉链存储结构的优点是对于一般的二叉树比较节省存储空间，在二叉链中访问一个结点的孩子很方便
    但是访问一个结点的双亲结点需要扫描所有结点*/

//二叉树中结点的数据值类型
// typedef int ElemType; 
typedef char ElemType;

typedef struct node
{
    ElemType data;
    struct node *lchild; //左孩子结点
    struct node *rchild; //右孩子结点
} BTNode;
