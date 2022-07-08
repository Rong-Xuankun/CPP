#include <stdio.h>

typedef struct
{
    int miss_damage;
    int blood;
} zombie;

int partition(zombie R[], int s, int t)
{
    int i = s, j = t;
    zombie tmp = R[i];
    while (i < j)
    {
        while (j > i && R[j].blood >= tmp.blood)
            j--;
        R[i] = R[j];
        while (i < j && R[i].blood <= tmp.blood)
            i++;
        R[j] = R[i];
    }
    R[i] = tmp;
    return i;
}

void QuickSort(zombie R[], int s, int t)
{
    int i;
    if (s < t)
    {
        i = partition(R, s, t);
        QuickSort(R, s, i - 1);
        QuickSort(R, i + 1, t);
    }
}

int main()
{
    int zombie_amount, power, basic_damage, add_damage;
    scanf("%d %d %d %d", &zombie_amount, &power, &basic_damage, &add_damage);

    zombie zom[zombie_amount];
    for (int i = 0; i < zombie_amount; i++)
        scanf("%d %d", &zom[i].miss_damage, &zom[i].blood);

    QuickSort(zom, 0, zombie_amount - 1);

    int i = 0, count = 0;
    while (power > 0 && i < zombie_amount)
    {
        if ((basic_damage + add_damage) >= zom[i].miss_damage)
        {
            if (power >= zom[i].blood)
            {
                count++;
                power -= zom[i].blood;
                i++;
            }
            else
            {
                i++;
                continue;
            }
        }
        else
            i++;
    }

    printf("%d", count);
    return 0;
}