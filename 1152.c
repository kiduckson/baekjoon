#include <stdio.h>
#include <stdlib.h>

int	    is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
int		is_alpha(int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

int     main()
{
    char *str;
    int count, index;

    str = (char *)malloc(1000004);
    if (str == NULL)
        return 0;
    fgets(str, 1000004, stdin);
    while(is_space(*str))
        str++;
    index = 0;
    count = 0;
    while(str[index])
    {
        if (is_space(str[index]) && is_alpha(str[index-1]))
            count++;
        index++;
    }
    printf("%d\n", count);
}