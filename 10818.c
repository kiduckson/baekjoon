#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len, i, max, min;
    int *arr;

    scanf("%d", &len);
    arr = malloc(len * sizeof(int));
    if (arr == NULL)
        return (0);
    i = 0;
    while (i < len)
        scanf("%d", &arr[i++]);
    i = 0;
    min = max = arr[i];
    while (i < len)
    {
        max = arr[i] > max ? arr[i] : max;
        min = arr[i] < min ? arr[i] : min;
        i++;
    }
    printf("%d %d\n", min, max);
    free(arr);
}