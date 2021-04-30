#include <stdio.h>
#include <stdlib.h>

int main()
{
    int index;
    int *arr;
    char *str;

    str = (char *)malloc(101);
    if (str == NULL)
        return 0;
    scanf("%s", str);
    arr = (int *)malloc(sizeof(int) * 26);
    if (arr == NULL)
        return 0;
    for (int i = 0; i < 26; i++)
        arr[i] = -1;
    index = 0;
    while(str[index] != '\0')
    {
        if (arr[str[index] - 97] == -1)
            arr[str[index] - 97] = index;
        index++;
    }
    for(int i = 0; i < 26; i++)
        printf("%d ", arr[i]);
    free(arr);
    free(str);
}