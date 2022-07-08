#include <stdio.h>
#include <string.h>
int main()
{
    long long int n, m;
    scanf("%lld %lld", &n, &m);
    long long int sum[n];
    memset(sum, 0, sizeof(sum));
    long long int a, b, c;
    long long int max = 0;
    long long int sign = 0;
    for (long long int i = 0; i < m; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        sum[a - 1] += c;
        sum[b - 1] += c;
    }
    for (long long int i = 0; i < m; i++)
    {
        if (sum[i] > max)
        {
            max = sum[i];
            sign = i + 1;
        }
    }
    printf("%lld", sign);
    return 0;
}