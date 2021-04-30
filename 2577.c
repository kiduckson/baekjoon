#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, rst;
    int *arr;

    scanf("%d %d %d", &a, &b, &c);
    rst = a * b * c;
    arr = malloc(sizeof(int) * 10);
    if (arr == NULL)
        return (0);
    for (int i = 0; i < 10; i++)
        arr[i] = 0;
    while (rst)
    {
        arr[rst % 10] += 1;
        rst /= 10;
    }
    for (int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);
    free(arr);    
}