#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, ra, rb;
    scanf("%d %d", &a, &b);
    ra = rb = 0;
    while(a && b)
    {
        ra = ra * 10 + a % 10; 
        rb = rb * 10 + b % 10;
        a /= 10;
        b /= 10;
    }
    printf("%d", ra > rb ? ra : rb);
}