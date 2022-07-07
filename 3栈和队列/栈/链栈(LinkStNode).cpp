#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;

typedef struct linknode
{
    ElemType data;         //数据域
    struct linknode *next; //指针域
} LinkStNode;              //链栈结点类型

//栈空的条件:s->next = NULL
//不存在栈满
//元素e的进栈操作:新建一个结点存放元素e(由p指向它),将结点p插入到头结点之后
//出栈操作:取出首结点的data值并将其删除

/*1.初始化栈*/
void InitStack(LinkStNode *&s)
{
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s->next = NULL;
}

void DestroyStack(LinkStNode *&s)
{
    LinkStNode *pre = s, *p = s->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

bool StackEmpty(LinkStNode *s)
{
    return (s->next == NULL);
}

void Push(LinkStNode *&s, ElemType e)
{
    LinkStNode *p;
    p = (LinkStNode *)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

bool Pop(LinkStNode *&s, ElemType &e)
{
    LinkStNode *p;
    if (s->next == NULL)
        return false;
    p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}

bool GetTop(LinkStNode *s, ElemType &e)
{
    if (s->next == NULL)
        return false;
    e = s->next->data;
    return true;
}