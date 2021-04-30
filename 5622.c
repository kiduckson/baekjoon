#include <stdio.h>
#include <stdlib.h>
#define LEN 15

int main()
{
    char *str;
    int time;

    str = malloc(LEN + 1);   
    scanf("%s", str);
    time = 0;
    while(*str)
    {
        if('A' <= *str && *str <= 'C')
            time += 3;
        if('D' <= *str && *str <= 'F')
            time += 4;
        if('G' <= *str && *str <= 'I')
            time += 5;
        if('J' <= *str && *str <= 'L')
            time += 6;
        if('M' <= *str && *str <= 'O')
            time += 7;
        if('P' <= *str && *str <= 'S')
            time += 8;
        if('T' <= *str && *str <= 'V')
            time += 9;
        if('W' <= *str && *str <= 'Z')
            time += 10;
        str++;
    }
    printf("%d\n", time);
}