#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;      //存放元素值
    struct LNode *next; //指向后继结点
} LinkNode;             //单链表结点类型

/*建立单链表(头插法)*/
void CreateListF(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;             //创造头结点，其next域置为NULL
    for (int i = 0; i < n; i++) //循环建立数据结点s
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];    //创建数据结点s
        s->next = L->next; //将结点s插入到原首结点之前、头结点之后
        L->next = s;
    }
}

/*建立单链表(尾插法)*/
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode)); //创造头结点
    r = L;                                    // r始终指向尾结点，初始时指向头结点
    for (int i = 0; i < n; i++)               //循环建立数据结点
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i]; //创建数组结点s
        r->next = s;    //将结点s插入到结点r之后
        r = s;
    }
    r->next = NULL; //尾结点的next域置为NULL
}

/*1.初始化线性表*/
void InitList(LinkNode *&L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

/*2.销毁线性表*/
void DestroyList(LinkNode *&L)
{
    LinkNode *pre = L, *p = L->next; // pre指向结点p的前驱结点
    while (p != NULL)                //扫描单链表L
    {
        free(pre); //释放pre结点
        pre = p;   // pre、p同步后移一个结点
        p = pre->next;
    }
    free(pre); //循环结束时p为NULL，pre指向尾结点，释放它
}

/*3.判断线性表是否为空表*/
bool ListEmpty(LinkNode *L)
{
    return (L->next == NULL);
}

/*4.求线性表的长度*/
int ListLength(LinkNode *L)
{
    int n = 0;
    LinkNode *p = L; // p指向头结点，n置为0
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return (n); //循环结束，p指向尾结点，其序号n为结点个数
}

/*5.输出线性表*/
void DispList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/*6.求线性表中的某个数据元素值*/
bool GetElem(LinkNode *L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L;
    if (i <= 0)
        return false;
    while (j < i && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        e = p->data;
        return true;
    }
}

/*7.按元素值查找*/
int LocateElem(LinkNode *L, ElemType e)
{
    int i = 1;
    LinkNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return (0);
    else
        return (i);
}

/*8.插入数据元素*/
bool ListInsert(LinkNode *&L, int i, ElemType e)
{
    int j = 0;
    LinkNode *p = L, *s;
    if (i <= 0)
        return false;
    while (j < i + 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

/*9.删除数据元素*/
bool ListDelete(LinkNode *&L, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = L, *q;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        q = p->next;
        if (q == NULL)
            return false;
        e = q->data;
        p->next = q->next;
        free(q);
        return true;
    }
}

void reverse(LinkNode *&s)
{
    LinkNode *p, *q;
    p = s->next;
    while (p != NULL)
    {
        q = p->next;
        p->next = s->next;
        s->next = p;
        p = q;
    }
}

void delminnode(LinkNode *&L)
{
    LinkNode *p = L->next, *q;
    int min = p->data;
    while (p != NULL)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    p = L->next;
    while (p->next != NULL)
    {
        if (p->next->data == min)
        {
            p->next = p->next->next;
            p = p->next;
        }
    }
}