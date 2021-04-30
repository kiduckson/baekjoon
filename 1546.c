#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int num, max;
    double rst;

    rst = max = 0;
    scanf("%d", &num);
    arr = malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < num; i++)
        max = max > arr[i] ? max : arr[i];
    for (int i = 0; i < num; i++)
    {
        rst += ((double)arr[i] / (double)max * 100);
    }
    printf("%f\n", rst / num);
    free(arr);
}