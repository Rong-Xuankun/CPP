#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
int a[N][N], b[N][N];
//初始化地图
void printfun()
{
    int i, j;
    printf("\n");
    printf("     1  2  3  4\n\n");
    for (i = 0; i < N; i++)
    {
        printf("%d   ", i + 1);
        for (j = 0; j < N; j++)
        {
            if (b[i][j])
                printf("%2d ", a[i][j]);
            else
                printf(" * ");
        }
        printf("\n");
    }
}

//游戏结束后输出地雷阵中每个位置的值
void printA()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}

//判断是否为地雷，如果是地雷，就返回1，如果不是地雷，返回0
int fun(int i, int j)
{
    if (i < 0 || i == N || j < 0 || j == N)
        return 0;
    if (a[i][j] == -1)
        return 1;
    return 0;
}

int main()
{
    // mine为地雷总数,sum为某位置周围地雷的数量
    int i, j, coordinate, mine, sum, flag;
loop:
    mine = 0;
    sum = N * N - 1;
    srand((unsigned)time(0));
    //计算地雷总数
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (rand() % (N + 1) == 0)
            {
                a[i][j] = -1;
                mine++;
            }
            else
                a[i][j] = 0;
            b[i][j] = 0;
        }
    }
    if (mine == 0)
    {
        a[rand() % N][rand() % N] = -1;
        mine++;
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (a[i][j] == -1)
            {
                continue;
            }
            //显示周围地雷的数量
            a[i][j] += fun(i - 1, j - 1);
            a[i][j] += fun(i - 1, j);
            a[i][j] += fun(i - 1, j + 1);
            a[i][j] += fun(i, j + 1);
            a[i][j] += fun(i + 1, j + 1);
            a[i][j] += fun(i + 1, j);
            a[i][j] += fun(i + 1, j - 1);
            a[i][j] += fun(i, j - 1);
        }
    }
    do
    {
        srand((unsigned)time(0));
        i = rand() % N;
        j = rand() % N;
    } while (a[i][j] == -1);
    b[i][j] = 1;
    do
    {
        flag = 0;
        do
        {
            system("clear");
            printf("  地雷总数:%d\n", mine);
            printfun();
            if (flag)
                printf("\n输入有误，重新输入!\n");
            printf(
                "请依次输入一个两位整数排雷，第一位为行数，第二位为列数("
                "如12代表第一行第二列):\n");
            scanf("%d", &coordinate);
            getchar();
            flag = 1;
        } while (coordinate < 11 || coordinate > N * 10 + N);
        i = coordinate / 10 - 1;
        j = coordinate % 10 - 1;
        b[i][j] = 1;
        sum--;
    } while (a[i][j] != -1 && sum != mine);
    printA();
    if (a[i][j] == -1)
        printf("\n引爆地雷!\n-1代表地雷!\n");
    else
        printf("\n扫雷成功!\n");
    getchar();
    goto loop;
    return 0;
}