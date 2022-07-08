//先按奇数和偶数，分为两个数组。
//有偶数就单独分一组，有奇数就单独分一组
//没有偶数就用两个奇数，没有奇数就用两个偶数
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int even[n], odd[n], tmp, count = 1;
    memset(even, 0, sizeof(even));
    memset(odd, 0, sizeof(odd));
    int s_even = 0, s_odd = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (tmp % 2 == 0)
        {
            even[s_even] = tmp;
            s_even++;
        }
        else
        {
            odd[s_odd] = tmp;
            s_odd++;
        }
    }
    int k = 0;
    s_even = 0;
    s_odd = 0;
    while (k < n)
    {
        if (count % 2 == 1)
        {
            if (even[s_even] != 0)
            {
                count++;
                s_even++;
                k++;
            }
            else if (even[s_even] == 0 && odd[s_odd] != 0 && odd[s_odd + 1] != 0)
            {
                count++;
                s_odd += 2;
                k += 2;
            }
            else if (even[s_even] == 0 && odd[s_odd] != 0 && odd[s_odd + 1] == 0)
            {
                count--;
                break;
            }
            else
                break;
        }
        else
        {
            if (odd[s_odd] != 0)
            {
                count++;
                s_odd++;
                k++;
            }
            
            else
                break;
        }
    }
    printf("%d", count - 1);
}