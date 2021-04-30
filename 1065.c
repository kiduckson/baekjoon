#include <stdio.h>

int check_is_valid(int n)
{
    int h, t, o, dist1, dist2;

    if (n < 100)
        return (1);
    h = n / 100;
    t = (n / 10) % 10;
    o = n % 10;
    return ((h - t) == (t - o));
}

int main()
{
    int n, count;

    scanf("%d", &n);
    count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (check_is_valid(i))
            count++;
    }
    printf("%d\n", count);
}