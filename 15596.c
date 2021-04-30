#include <stdio.h>

long long sum(int *a, int n)
{
    long long ans, i;
    
    i = ans = 0;
    while(i < n)
        ans += a[i++];
    return (ans);
}
