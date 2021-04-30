#include <stdio.h>

int main()
{
    int input, tens, ones, count, tmp;
    scanf("%d", &input);
    if (!input){
        printf("%d\n", 1);
        return (0);
    }
    tens = ones = tmp = count = 0;
    while(input != tmp)
    {
        if (count == 0)
            tmp = input;
        ones = (tmp / 10) + (tmp % 10);
        if (ones > 9)
            ones = ones % 10;
        tens = tmp % 10 * 10;
        tmp = tens + ones;
        count++;
    }
    printf("%d\n", count);
    return (0);
}