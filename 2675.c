#include <stdio.h>
#include <stdlib.h>

int b_strlen(char *s)
{
    int len;

    len = 0;
    while(*s++)
        len++;
    return len;
}

int main()
{
    int len, strlen, repeat, r_index;
    char* str;
    char** arr;
    scanf("%d", &len);
    arr = (char **)malloc(sizeof(char*) * len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &repeat);
        str = (char *)malloc(21);
        scanf("%s", str);
        strlen = b_strlen(str);
        arr[i] = (char *)malloc(strlen * repeat + 1);
        r_index = 0;
        while(*str)
        {   
            for (int j = 0; j < repeat; j++)
            {
                arr[i][r_index] = *str;
                r_index++;
            }
            str++;
        } 
    }
    for (int i = 0; i < len; i++)
        printf("%s\n", arr[i]);
    free(arr);
}