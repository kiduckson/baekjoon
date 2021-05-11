#include <stdio.h>

int b_fibonacci(int k)
{
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;
	return b_fibonacci(k - 1) + b_fibonacci(k - 2);
}

int main()
{
	int k;
	scanf("%d", &k);
	printf("%d", b_fibonacci(k));
}
