#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int main()
{
	int min, max;
	int *arr;

	arr = malloc(sizeof(int)* MAX);
	scanf("%d %d", &min, &max);
	arr[0] = arr[1] = 0;
	arr[2] = arr[3] = 1;

	// initialize 1로 채우기
	for (int i = 2; i < MAX; i++)
		arr[i] = 1;

	for(int i = 2; i * i < MAX; i++)
		if (arr[i] == 1)
			for (int j = i * i; j < MAX; j += i)
					arr[j] = 0;
	for(int i = min; i <= max; i++)
		if (arr[i])
			printf("%d\n", i);
	free(arr);
	return (0);
}
