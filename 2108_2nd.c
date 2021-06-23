#include <stdio.h>


int main()
{
	int n, mean;
	int arr[500001];
	scanf("%d", &n);
	int max = -4000;
	int min = 4000;
	int total = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
		total += arr[i];
	}
	mean = (int)(((long double)total / (long double)n) + (total >= 0 ? 0.5f : -0.5f));

}
