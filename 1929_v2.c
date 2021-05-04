#include <stdio.h>
#include <math.h>

int main()
{
	int min, max, is_prime, idx;

	scanf("%d %d", &min, &max);
	for (int i = min; i < max; i++)
	{
		idx = (int)sqrt(i);
		is_prime = 0;
		if (i > 1)
			is_prime = 1;
		for (int j = 2; j <= idx; j++)
			if(i % j == 0)
				is_prime = 0;
		if (is_prime)
			printf("%d\n", i);
	}
	return 0;
}
