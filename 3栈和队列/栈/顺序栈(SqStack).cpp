#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize]; //存放栈中的数据元素
    int top;                //栈顶指针，即存放栈顶元素在data数组中的下标
} SqStack;                  //顺序栈类型

//栈空的条件:s->top == -1
//栈满的条件:s->top == MaxSize - 1
//元素e的进栈操作:先将栈顶指针top增1，然后将元素e放在栈顶指针处
//出栈操作:先将栈顶指针top处的元素取出放在e中，然后将栈顶指针减1

/*1.初始化栈*/
void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

/*2.销毁栈*/
void DestroyStack(SqStack *&s)
{
    free(s);
}

/*3.判断栈是否为空*/
bool StackEmpty(SqStack *s)
{
    return (s->top == -1);
}

/*4.进栈*/
bool Push(SqStack *&s, ElemType e)
{
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

/*5.出栈*/
bool Pop(SqStack *&s, ElemType &e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

/*6.取栈顶元素*/
bool GetTop(SqStack *s, ElemType &e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}