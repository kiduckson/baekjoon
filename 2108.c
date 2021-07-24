
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, j, tmp, mean, medium, max, min, range;
	int *arr, *arr2;
	int count[8001] = {0};

	scanf("%d", &n);
	max = 0;
	min = 4000;
	arr = malloc(sizeof(int) * n);
	arr2 = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		count[arr[i]+4000]++;
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	// 1. 산술평균
	// 전보다는 큰데 아까보다는 작은거

	mean = 0;
	for (i = 0; i < n; i++)
		mean+= arr[i];
	mean /= n;
	range = max - min;
	for (i = 1; i <= 8001; i++)
		count[i] = count[i - 1] + count[i];
	for (i = n - 1; i >= 0; i--){
		arr2[count[arr[i] + 4000]] = arr[i];
	}
	for (i = 0; i < n; i++){
		printf("arr : %d\n", arr2[i]);
	}

}
