#include <stdio.h>

int main()
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);
	while(1)
	{
		if (a == 0 && b == 0 && c == 0)
			break;
		if (((a * a) + (b * b)) == (c * c))
			printf("right\n");
		else if (((a * a) + (c * c)) == (b * b))
			printf("right\n");
		else if (((c * c) + (b * b)) == (a * a))
			printf("right\n");
		else
			printf("wrong\n");
		scanf("%d%d%d", &a, &b, &c);
	}
	return (0);
}
