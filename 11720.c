#include <stdio.h>
#include <stdlib.h>

int main()
{
    char    *str;
    int     len, rst;
    scanf("%d", &len);
    str = (char *)malloc(len + 1);
    scanf("%s", str);
    rst = 0;
    while(*str)
    {
        rst += *str - 48;
        str++;
    }
    printf("%d\n", rst);
}
