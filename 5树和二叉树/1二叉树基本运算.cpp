#include "1链式存储结构.cpp"

void CreateBTree(BTNode *&b, char *str)
{
    BTNode *St[MaxSize], *p; // St数组作为顺序栈
    int top = -1, k, j = 0;
    char ch;
    b = NULL; //初始时二叉链为空
    ch = str[j];
    while (ch != '\0') //循环扫描str中的每个字符
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1; //开始处理左孩子结点
            break;
        case ')':
            top--; //栈顶结点的子树处理完毕
            break;
        case ',':
            k = 2; //开始处理右孩子结点
            break;
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL; //初始化左右子结点
            if (b == NULL)                //如果尚未建立跟结点
                b = p;                    // p所指结点就作为根结点
            else
            {
                switch (k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

void DestroyBTree(BTNode *&b)
{
    if (b != NULL)
    {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

BTNode *FindNode(BTNode *b, ElemType x) //查找结点
{
    BTNode *p;
    if (b == NULL)
        return NULL;
    else if (b->data == x)
        return b;
    else
    {
        p = FindNode(b->lchild, x);
        if (p != NULL)
            return p;
        else
            return FindNode(b->rchild, x);
    }
}

BTNode *LchildNode(BTNode *p) //查找左子结点地址
{
    return p->lchild;
}

BTNode *RchildNode(BTNode *p) //查找右子结点地址
{
    return p->rchild;
}

int BTHeight(BTNode *b) //求二叉树高度
{
    int lchildh, rchildh;
    if (b == NULL)
        return (0);
    else
    {
        lchildh = BTHeight(b->lchild);
        rchildh = BTHeight(b->rchild);
        return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
    }
}

void DispBTree(BTNode *b)
{
    if (b != NULL)
    {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");
            DispBTree(b->lchild);
            if (b->rchild != NULL)
                printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

void copytree(BTNode *a, BTNode *&b)
{
    if (a == NULL)
        b = NULL;
    else
    {
        b = (BTNode *)malloc(sizeof(BTNode));
        b->data = a->data;
        copytree(a->lchild, b->lchild);
        copytree(a->rchild, b->rchild);
    }
}