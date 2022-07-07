#include "1链式存储结构.cpp"
#include "1二叉树基本运算.cpp"

void PreOrder(BTNode *b) //先序遍历递归算法
{
    if (b != NULL)
    {
        printf("%c ", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void InOrder(BTNode *b) //中序遍历递归算法
{
    if (b != NULL)
    {
        InOrder(b->lchild);
        printf("%c ", b->data);
        InOrder(b->rchild);
    }
}

void PostOrder(BTNode *b) //后序遍历递归算法
{
    if (b != NULL)
    {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c ", b->data);
    }
}