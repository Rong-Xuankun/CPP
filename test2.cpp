#include <stdio.h>
#include <string.h>
int main()
{
    char str[5000];
    gets(str);
    int length = strlen(str);
    char stack[2500];
    int top = -1;
    int is_right = 1;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(')
        {
            top++;
            stack[top] = str[i];
        }
        else
        {
            if (top == -1 && i != length - 1)
            {
                is_right = 0;
                break;
            }
            else
            {
                stack[top] = '\0';
                top--;
            }
        }
    }
    if (top == -1 && is_right == 1)
    {
        printf("Yes\n");
    }
    else
        printf("No\n");
}