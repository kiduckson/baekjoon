#include <stdio.h>
#include <stdlib.h>

int calculate_dn(int n)
{
    int ans, left;

    ans = 0;
    while (n > 9)
    {
        left = n % 10;
        ans += left;
        n /= 10;
    }
    ans += n;
    return (ans);
}

int main()
{
    int n, dn;
    int *arr;
    arr = (int*)malloc(sizeof(int) * 10000);
    for (int i = 0; i < 10000; i++)
        arr[i] = i;
    n = 1;
    dn = 0;
    while(n < 10000)
    {
        dn = calculate_dn(n) + n;
        if (dn < 10000)
            arr[dn] = 0;
        n++;
    }
    for (int i = 0; i < 10000; i++)
    {
        if (arr[i])
            printf("%d\n", arr[i]);
    }
    free(arr);
}