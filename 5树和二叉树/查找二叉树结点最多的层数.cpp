#include "1二叉树基本运算.cpp"

typedef struct
{
    int lno;   //结点的层次
    BTNode *p; //结点指针
} Qu;

int BTWidth(BTNode *b, int &k)
{
    Qu Q[MaxSize];
    int front, rear; //定义队首和队尾指针
    int max, lnum, i, n;
    front = rear = 0; //置队列为空队
    if (b != NULL)
    {
        rear++;
        Q[rear].p = b;        //根结点进队
        Q[rear].lno = 1;      //根结点的层次为1
        while (rear != front) //队不空时循环
        {
            front++;
            b = Q[front].p; //出队结点b
            lnum = Q[front].lno;
            if (b->lchild != NULL) //有左孩子，将其进队
            {
                rear++;
                Q[rear].p = b->lchild;
                Q[rear].lno = lnum + 1;
            }
            if (b->rchild != NULL) //有右孩子，将其进队
            {
                rear++;
                Q[rear].p = b->rchild;
                Q[rear].lno = lnum + 1;
            }
        }
        max = 0; // max存放宽度
        lnum = 1;
        i = 1;
        while (i <= rear)
        {
            n = 0;
            while (i <= rear && Q[i].lno == lnum)
            {
                n++; // n累计一层中的结点个数
                i++; // i扫描队列中的所有结点
            }
            lnum = Q[i].lno;
            if (n > max)
            {
                max = n;
                k = Q[i].lno - 1;
            }
        }
        return max;
    }
    else
        return 0;
}

int main()
{
    int k = 1;
    char str[] = {"A(B(D(,G(K,L)),E(,H)),C(F(I,J)))"};
    BTNode *b;
    CreateBTree(b, str);
    printf("二叉树:\n");
    DispBTree(b);
    printf("\n");
    printf("宽度:%d\n该层数是:%d\n", BTWidth(b, k), k);
    DestroyBTree(b);
    return 1;
}