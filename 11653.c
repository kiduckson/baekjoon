#include <stdio.h>

int main()
{
	int sum;
	scanf("%d", &sum);

	int div = 2;
	while(sum > 1)
	{
		if(sum % div == 0)
		{
			sum /= div;
			printf("%d\n", div);
		}
		else
			div++;
	}
}
