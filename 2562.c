#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int i, j, max;

    i = j = max = 0;
    arr = malloc(sizeof(int) * 9);
    while(i < 9)
        scanf("%d", &arr[i++]);
    i = 0;
    while(i < 9)
    {
        if (max < arr[i])
        {
            max = arr[i];
            j = i;
        }
        i++;
    }
    printf("%d\n", max);
    printf("%d\n", j + 1);
    free(arr);
}