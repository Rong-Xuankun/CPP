#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DLinkNode;

/*头插法建立双链表*/
void CreateListF(DLinkNode *&L, ElemType a[], int n)
{
    DLinkNode *s;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->next = L->prior = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->next = L->next;
        if (L->next != NULL)
            L->next->prior = s;
        L->next = s;
        s->prior = L;
    }
}

/*尾插法建立双链表*/
void CreateListR(DLinkNode *&L, ElemType a[], int n)
{
    DLinkNode *s, *r;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}