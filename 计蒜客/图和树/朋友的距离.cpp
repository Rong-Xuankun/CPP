#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int distance[n][n];
    memset(distance, 0, sizeof(distance));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &distance[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (distance[j][i] > distance[i][j])
            {
                printf("%d ", distance[j][i]);
            }
            else
            {
                printf("%d ", distance[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}