#include <stdio.h>

int N;
long long int H[21];
long long int B;
long long int ans = 1e6;

void dfs(int count_cow, long long int sum)
{
    if (sum >= B)
    {
        if ((sum - B) < ans)
            ans = sum - B;
        return;
    }

    if (count_cow == N - 1)
    {
        if ((sum + H[count_cow]) >= B)
        {
            if ((sum + H[count_cow] - B) < ans)
                ans = sum + H[count_cow] - B;
            return;
        }
        else
            return;
    }
    else
    {
        dfs(count_cow + 1, sum + H[count_cow]);
        dfs(count_cow + 1, sum);
    }
}

int main()
{
    scanf("%d %lld", &N, &B);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &H[i]);
    }
    dfs(0, 0);
    printf("%lld", ans);
    return 0;
}