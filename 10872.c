#include <stdio.h>

int b_factorial(int k)
{
	if (k < 1)
		return 1;
	if (k == 1)
		return 1;
	return (k * b_factorial(k - 1));
}

int main()
{
	int k;
	scanf("%d",&k);
	printf("%d\n", b_factorial(k));
	return (0);
}
