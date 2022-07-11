#include <stdio.h>
#include <string.h>

char initial_status[5];
char unlock_status[5];
int vis[10000];

typedef struct
{
    char str[5];
    int step;
} lock;

int is_check(char str[])
{
    int sum;
    for (int i = 0; i < 4; i++)
    {
        sum = str[i] - 48 + sum * 10;
    }

    if (vis[sum] == 0)
    {
        vis[sum] = 1;
        return 0;
    }
    else
        return 1;
}

int bfs(char initial_status[], char unlock_status[])
{
    lock initial;
    strcpy(initial.str, initial_status);
    initial.step = 0;
    lock queue[100000];
    lock now;
    lock test;
    int l = 0;
    int r = 0;
    char tmp;

    queue[r] = initial;
    r++;

    while (l < r)
    {
        now = queue[l];
        l++;
        if (is_check(now.str) == 1)
            continue;

        if (strcmp(now.str, unlock_status) == 0)
            return now.step;

        for (int i = 0; i < 11; i++)
        {
            test = now;
            if (i == 0)
            {
                test.str[0] += 1;
                test.step++;
                if (test.str[0] == ':')
                    test.str[0] = '1';
                queue[r] = test;
                r++;
            }
            else if (i == 1)
            {
                test.str[0] -= 1;
                test.step++;
                if (test.str[0] == '0')
                    test.str[0] = '9';
                queue[r] = test;
                r++;
            }
            else if (i == 2)
            {
                test.str[1] += 1;
                test.step++;
                if (test.str[1] == ':')
                    test.str[1] = '1';
                queue[r] = test;
                r++;
            }
            else if (i == 3)
            {
                test.str[1] -= 1;
                test.step++;
                if (test.str[1] == '0')
                    test.str[1] = '9';
                queue[r] = test;
                r++;
            }
            else if (i == 4)
            {
                test.str[2] += 1;
                test.step++;
                if (test.str[2] == ':')
                    test.str[2] = '1';
                queue[r] = test;
                r++;
            }
            else if (i == 5)
            {
                test.str[2] -= 1;
                test.step++;
                if (test.str[2] == '0')
                    test.str[2] = '9';
                queue[r] = test;
                r++;
            }
            else if (i == 6)
            {
                test.str[3] += 1;
                test.step++;
                if (test.str[3] == ':')
                    test.str[3] = '1';
                queue[r] = test;
                r++;
            }
            else if (i == 7)
            {
                test.str[3] -= 1;
                test.step++;
                if (test.str[3] == '0')
                    test.str[3] = '9';
                queue[r] = test;
                r++;
            }
            else if (i == 8)
            {
                tmp = test.str[0];
                test.str[0] = test.str[1];
                test.str[1] = tmp;
                test.step++;
                queue[r] = test;
                r++;
            }
            else if (i == 9)
            {
                tmp = test.str[1];
                test.str[1] = test.str[2];
                test.str[2] = tmp;
                test.step++;
                queue[r] = test;
                r++;
            }
            else
            {
                tmp = test.str[2];
                test.str[2] = test.str[3];
                test.str[3] = tmp;
                test.step++;
                queue[r] = test;
                r++;
            }
        }
    }
    return 0;
}

int main()
{
    gets(initial_status);
    gets(unlock_status);
    memset(vis, 0, sizeof(vis));
    printf("%d", bfs(initial_status, unlock_status));
    return 0;
}