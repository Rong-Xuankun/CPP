#include <stdio.h>
#include <string.h>

int tree[1005][1005];
int du[1005];
int main()
{
    int t, n, a, b;
    scanf("%d", &t);
    while (t--)
    {
        memset(tree, 0, sizeof(tree));
        memset(du, 0, sizeof(du));
        scanf("%d", &n);
        for (int j = 0; j < n - 1; j++)
        {
            scanf("%d %d", &a, &b);
            tree[a - 1][b - 1] = 1;
            tree[b - 1][a - 1] = 1;
            du[a - 1]++;
            du[b - 1]++;
        }
        int count = n;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (tree[j][k])
                {
                    if (du[k] > du[j])
                    {
                        count--;
                        break;
                    }
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}