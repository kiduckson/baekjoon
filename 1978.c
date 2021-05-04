#include <stdio.h>
#include <math.h>

int main()
{
	int times, rst, is_prime, idx;
	int	arr[101];

	rst = 0;
	scanf("%d", &times);
	for (int i = 0; i < times; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < times; i++)
	{
		if (arr[i] < 2)
			is_prime = 0;
		else if (arr[i] == 2 || arr[i] == 3)
			is_prime = 1;
		else
		{
			idx = (int)sqrt(arr[i]);
			is_prime = 1;
			for (int j = 2; j <= idx; j++)
				if(arr[i] % j == 0)
					is_prime = 0;
		}
		if (is_prime)
			rst++;
	}
	printf("%d\n", rst);
	return 0;
}
