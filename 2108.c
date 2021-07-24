<<<<<<< HEAD

=======
>>>>>>> e3d7ccaa2939a82b4dde38cb7c95bf33efe48135
#include <stdio.h>
#include <stdlib.h>

int main()
{
<<<<<<< HEAD
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
=======
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
>>>>>>> e3d7ccaa2939a82b4dde38cb7c95bf33efe48135
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
<<<<<<< HEAD
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

=======
		count[arr[i] + 4000]++;
	}
	mean = (int)(((long double)mean / (long double)n) + (mean >= 0 ? 0.5f : -0.5f));
	for (i = 0; i < 8001; i++){
		if (count[i] > frqnt)
			frqnt = count[i];
		medium += count[i];
		if (medium >= n / 2 + 1){
			medium = i - 4000;
			break;
		}
	}
	for (i = 0; i < 8001; i++){
		if (count[i] == frqnt){
			most = i - 4000;
			cc++;
			if (cc == 2)
				break;
		}
	}
	printf("%d\n%d\n%d\n%d\n", mean, medium, most, max - min);
	free(arr);
>>>>>>> e3d7ccaa2939a82b4dde38cb7c95bf33efe48135
}
