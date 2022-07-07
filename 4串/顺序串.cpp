#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;

typedef struct
{
    char data[MaxSize];
    int length;
} SqString;

void StrAssign(SqString &s, char cstr[]) //初始化串
{
    int i;
    for (i = 0; cstr[i] != '\0'; i++)
        s.data[i] = cstr[i];
    s.length = i;
}

void DestroyStr(SqString &s) //销毁串
{
}

void StrCopy(SqString &s, SqString t) //复制串
{
    int i;
    for (i = 0; i < t.length; i++)
        s.data[i] = t.data[i];
    s.length = t.length;
}

bool StrEqual(SqString s, SqString t) //判断串是否相等
{
    bool same = true;
    int i;
    if (s.length != t.length)
        same = false;
    else
        for (i = 0; i < s.length; i++)
            if (s.data[i] != t.data[i])
            {
                same = false;
                break;
            }
    return same;
}

int StrLength(SqString s) //计算串的长度
{
    return s.length;
}

SqString Concat(SqString s, SqString t) //连接串
{
    SqString str;
    int i;
    str.length = s.length + t.length;
    for (i = 0; i < s.length; i++)
        str.data[i] = s.data[i];
    for (i = 0; i < t.length; i++)
        str.data[i + s.length] = t.data[i];
    return str;
}

SqString SubStr(SqString s, int i, int j) //求子串
{
    int k;
    SqString str; //定义结果串
    str.length = 0;
    if (i <= 0 || i > s.length || j < 0 || i + j - 1 > s.length)
        return str;
    for (k = i - 1; k < i + j - 1; k++)
        str.data[k - i + 1] = s.data[k];
    str.length = j;
    return str;
}

SqString InsStr(SqString s1, int i, SqString s2) //插入串
{
    int j;
    SqString str;
    str.length = 0;
    if (i <= 0 || i > s1.length + 1)
        return str;
    for (j = 0; j < i - 1; j++)
        str.data[j] = s1.data[j];
    for (j = 0; j < s2.length; j++)
        str.data[i + j - 1] = s2.data[j];
    for (j = i - 1; j < s1.length; j++)
        str.data[s1.length + j] = s1.data[j];
    str.length = s1.length + s2.length;
    return str;
}

SqString DelStr(SqString s, int i, int j) //删除子串
{
    int k;
    SqString str;
    str.length = 0;
    if (i <= 0 || i > s.length || i + j > s.length + 1)
        return str;
    for (k = 0; k < i - 1; k++)
        str.data[k] = s.data[k];
    for (k = i - 1 + j; k < s.length; k++)
        str.data[k - j] = s.data[k];
    str.length = s.length - j;
    return str;
}

SqString RepStr(SqString s, int i, int j, SqString t) //子串的替换
{
    int k;
    SqString str;
    str.length = 0;
    if (i < 0 || i > s.length || i + j - 1 > s.length)
        return str;
    for (k = 0; k < i - 1; k++)
        str.data[k] = s.data[k];
    for (k = 0; k < t.length; k++)
        str.data[i - 1 + k] = t.data[k];
    for (k = i + j - 1; k < s.length; k++)
        str.data[t.length - j + k] = s.data[k];
    str.length = s.length - j + t.length;
    return str;
}

void DispStr(SqString s) //输出串
{
    int i;
    if (s.length > 0)
    {
        for (i = 0; i < s.length; i++)
            printf("%c ", s.data[i]);
        printf("\n");
    }
}