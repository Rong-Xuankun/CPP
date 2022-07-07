#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int main()
{
    char data16[MAXSIZE];
    int data10 = 0;
    int i;
    printf("请输入一个16进制的数:\n");
    gets(data16);
    for (i = 0; data16[i] != '\0'; i++)
    {
        if (data16[i] >= 48 && data16[i] <= 57)
            data10 = data10 * 16 + (int)data16[i] - 48;
        else if (data16[i] >= 65 && data16[i] <= 70)
            data10 = data10 * 16 + (int)data16[i] - 55;
        else if (data16[i] >= 97 && data16[i] <= 102)
            data10 = data10 * 16 + (int)data16[i] - 87;
        else
        {
            printf("error!\n");
            return 0;
        }
    }
    printf("转化为10进制后为:%d\n", data10);
    return 0;
}