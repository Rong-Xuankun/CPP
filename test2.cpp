#include <stdio.h>
#include <string.h>
int main()
{
    long long int n;
    scanf("%lld", &n);
    char order[n][10];
    char web[n][100];
    char stack_web[n/4][100];
    long long int top = -1;
    long long int high = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", order[i]);
        if (order[i][0] == 'V')
            scanf("%s", web[i]);
        else if (order[i][0] == 'B')
            continue;
        else
            continue;
    }
    for (int i = 0; i < n; i++)
    {
        if (order[i][0] == 'V')
        {
            top++;
            high = top;
            strcpy(stack_web[top], web[i]);
            printf("%s\n", stack_web[top]);
        }
        else if (order[i][0] == 'B')
        {
            top--;
            if (top >= 0)
                printf("%s\n", stack_web[top]);
            else
            {
                printf("Ignore\n");
                top++;
            }
        }
        else if (order[i][0] == 'F')
        {
            top++;
            if (top <= high && high >= 0)
                printf("%s\n", stack_web[top]);
            else
            {
                printf("Ignore\n");
                top--;
            }
        }
    }
}