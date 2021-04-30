#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count, j;
    char *str;
    str = (char *)malloc(100 + 1);
    if (str == NULL)
        return 0;
    scanf("%s", str);
    count = 0;
    while (str[count])
        count++;
    j = 0;
    while(str[j])
    { 
        if(str[j] == 'l' || str[j] == 'n')
        {
            j++;
            if(str[j] == 'j')
                count--;
        }
        else if(str[j] == 'd')
        {
            j++;
            if(str[j] == '-')
                count--;
            else if(str[j] == 'z')
            {
                j++;
                if (str[j] == '=')
                    count = count - 2;
            }
        }
        else if (str[j] == 'c' || str[j] == 'z' || str[j] == 's')
        {
            j++;
            if(str[j] == '-' && str[j-1] == 'c')
                count--;
            else if(str[j] == '=')
                count--;
        }
        else
        {
            j++;
        }
    }
    printf("%d\n", count);
}