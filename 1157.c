#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str;
    int *arr;
    int max, index;

    str = malloc(1000001);
    scanf("%s", str);
    arr = (int *)malloc(sizeof(int) * 26);
    for (int i = 0; i < 26; i++)
        arr[i] = 0;
    while(*str)
    {
        if (*str > 96 && *str < 123)
            arr[*str - 97]++;
        else
        {
            arr[*str - 65]++;
        }
        str++;
    }
    max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            index = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (i != index)
        {
            if (arr[i] == max) 
            {
                printf("?");
                return 0;
            }
        }
    }
    printf("%c", index + 65);
    free(arr);
}