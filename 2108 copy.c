#include <stdio.h>
#include <stdlib.h>

int main()
{
	int mean, i, n, *arr, max, min, medium, frqnt, most, cc;
	int count[8001] = {0,};

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	mean = medium = frqnt = most = cc = 0;
	max = -4000;
	min = 4000;

	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		mean += arr[i];
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
		count[arr[i] + 4000]++;
	}
	mean = (int)(((long double)mean / (long double)n) + (mean >= 0 ? 0.5f : -0.5f));
	for (i = 0; i < 8001; i++){
		if (count[i]){
			if (count[i] > frqnt)
				frqnt = count[i];
			medium += count[i];
			if (medium >= n / 2 + 1){
				medium = i - 4000;
				break;
			}
		}
	}
	for (i = 0; i < 8001; i++){
		if (count[i]){
			if (count[i] == frqnt){
				most = i - 4000;
				cc++;
				if (cc == 2)
					break;
			}
		}
	}
	printf("%d\n%d\n%d\n%d\n", mean, medium, most, max - min);
	free(arr);
}
