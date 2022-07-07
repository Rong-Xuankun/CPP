#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;

typedef struct snode
{
    char data;
    struct snode *next;
} LinkStrNode;

void StrAssign(LinkStrNode *&s, char cstr[]) //生成串
{
    int i;
    LinkStrNode *r, *p;
    s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    r = s;
    for (i = 0; cstr[i] != '\0'; i++)
    {
        p = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        p->data = cstr[i];
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

void DestroyStr(LinkStrNode *&s) //销毁串
{
    LinkStrNode *pre = s, *p = s->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

void StrCopy(LinkStrNode *&s, LinkStrNode *t) //复制串
{
    LinkStrNode *p = t->next, *q, *r;
    s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    r = s;
    while (p != NULL)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
}