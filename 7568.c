/*
x kg y cm = x + y;
큰 덩치 a > b; 키등수 덩치 등수

kg cm  kn	cn
88 186  1	1
55 185  4	2
58 183  3	3
60 175	2	4
46 155	5	5
*/

#include <stdio.h>

int main()
{
	int nbr, rank;
	int arr[51][2];
	scanf("%d", &nbr);
	for (int i = 0; i < nbr; i++)
		scanf("%d%d", &arr[i][0], &arr[i][1]);
	for (int i = 0; i < nbr; i++)
	{
		rank = 0;
		for (int j = 0; j < nbr; j++)
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				rank++;
		rank++;
		printf("%d\n", rank);
	}
	return (0);
}
