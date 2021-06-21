#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, *arr, *counter, min, max, offset, range, idx;
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	min = 1000000000;
	max = -1000000000;
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	offset = min < 0 ? -min : min;
	range = max - min + 1;
	min = min + offset;
	counter = (int *)malloc(range * sizeof(int));
	for (i = 0; i < range; i++)
		counter[i] = 0;
	for (i = 0; i < n; i++){
		idx = arr[i] + offset - min;
		counter[idx] = 1;
	}
	for (i = 0; i < range; i++)
		if (i > 0)
			counter[i] = counter[i] + counter[i - 1];
	for (i = 0; i < n; i++){
		idx = arr[i] + offset - min;
		printf("%d ", counter[idx] - 1);
	}
	free(arr);
	free(counter);
	return(0);
}
