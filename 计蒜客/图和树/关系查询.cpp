#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char name1[21];
    char name2[21];
    int n, m;
    scanf("%d", &n);
    char name_1[n][21];
    char name_2[n][21];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", name_1[i], name_2[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s %s", name1, name2);
        for (int j = 0; j < n; j++)
        {
            if (strcmp(name_1[j], name1) == 0 && strcmp(name_2[j], name2) == 0)
            {
                printf("Yes\n");
                break;
            }
            else if (strcmp(name_2[j], name1) == 0 && strcmp(name_1[j], name2)==0)
            {
                printf("Yes\n");
                break;
            }
            else if (j == n - 1)
                printf("No\n");
        }
    }
    return 0;
}