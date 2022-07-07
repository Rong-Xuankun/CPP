#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//队空的条件:q->front == q->rear
//队满的条件:q->rear == MaxSize - 1
//元素e的进队操作:先将rear增1，然后将元素e放在data数组的rear位置
//出队操作:先将front增1，然后取出data数组中front位置的元素

void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

void DestroyQueue(SqQueue *&q)
{
    free(q);
}

bool QueueEmpty(SqQueue *q)
{
    return (q->front == q->rear);
}

bool enQueue(SqQueue *&q, ElemType e)
{
    if (q->rear == MaxSize - 1)
        return false;
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue *&q, ElemType &e)
{
    if (q->front == q->rear)
        return false;
    q->front++;
    e = q->data[q->front];
    return true;
}

