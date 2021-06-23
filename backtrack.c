#include <stdio.h>

void backtrack(char *str, unsigned char digit, int count, int N, int M)
{
    if(count == M)
    {
        printf("%s\n", str - 2 * M);
        return;
    }
    for(int i = 0; i < N; i++)
    {
        if(digit & (unsigned char)(1 << i))
        {
            str[2] = '\0';
            str[1] = ' ';
            str[0] = '1' + i;

            backtrack(str + 2, digit ^ (unsigned char)(1 << i), count + 1, N, M);
        }
    }
}

int main()
{
    unsigned char digit = 0;

    char str[256] = { '\0' };
    int temp = 1;
    for(int i = 0; i < 3; i++)
    {
        temp *= 2;
    }

    digit = (unsigned char)(temp - 1);

    backtrack(str, digit, 0, 3, 3);

}
