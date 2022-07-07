#include "顺序串.cpp"

void GetNext(SqString t, int next[]) //由模式串t求出next数组
{
    int j, k;
    j = 0; // j扫描t，k记录t[j]之前与t开头相同的字符个数
    k = -1;
    next[0] = -1;            //设置next[0]值
    while (j < t.length - 1) //求t所有位置的next值
    {
        if (k == -1 || t.data[j] == t.data[k]) // k为-1或比较的字符相等时
        {
            j++; // j、k依次移到下一个字符
            k++;
            next[j] = k; //设置next[j]为k
        }
        else
            k = next[k]; // k回退
    }
}

int KMPIndex(SqString s, SqString t)
{
    int next[MaxSize], i = 0, j = 0;
    GetNext(t, next);
    while (i < s.length && j < t.length)
    {
        if (j == -1 || s.data[i] == t.data[i])
        {
            i++;
            j++;
        }
        else
            j = next[j]; // i不变，j等于next[j]
    }
    if (j >= t.length)
        return (i - t.length);
    else
        return (-1);
}