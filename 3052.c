#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int tmp, count, size;
    
    size = 42;
    arr = malloc(sizeof(int) * size);
    if (arr == NULL)
        return (0);
    for (int i = 0; i < size; i++)
        arr[i] = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &tmp);
        arr[tmp % size]++;
    }
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i])
            count++;
    }
    printf("%d\n", count);
}