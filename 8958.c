#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, score, total;
    char *buf, *tmp;
    int *rst;

    scanf("%d", &num);
    rst = malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
    {
        buf = (char*)malloc(81);
        if (buf == NULL)
            return (0);
        scanf("%s", buf);
        tmp = buf;
        total = score = 0;
        while (*tmp)
        {   
            if (*tmp == 79)
                score++;
            else
            {
                score = 0;
            }
            total += score;
            tmp++;
        }
        rst[i] = total;
        free(buf);
    }
    for (int i = 0; i < num; i++)
        printf("%d\n", rst[i]);
    free(rst);
}