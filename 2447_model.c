#include <stdio.h>

void b_stars(int i, int j, int num)
{
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1)
		printf(" ");
	else
	{
		if (num / 3 == 0)
			printf("*");
		else
			b_stars(i, j, num / 3);
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			b_stars(i, j, num);
		printf("\n");
	}
}
