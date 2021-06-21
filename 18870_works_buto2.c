#include <stdio.h>
#include <stdlib.h>

int sorted[1000000];

void merge(int sorted[], int l, int m, int r)
{
	int i, j, k, idx_l, idx_r;

	idx_l = m - l + 1;
	idx_r = r - m;
	int arr_l[idx_l], arr_r[idx_r];
	for (i = 0; i < idx_l; i++)
		arr_l[i] = sorted[l + i];
	for (j = 0; j < idx_r; j++)
		arr_r[j] = sorted[m + 1 + j];

	i = j = 0;
	k = l;
	while (i < idx_l && j < idx_r){
		if (arr_l[i] <= arr_r[j]){
			sorted[k] = arr_l[i];
			i++;
		}
		else {
			sorted[k] = arr_r[j];
			j++;
		}
		k++;
	}
	while (i < idx_l)
		sorted[k++] = arr_l[i++];
	while (j < idx_r)
		sorted[k++] = arr_r[j++];
}

void mergeSort(int sorted[], int l, int r){
	int m;
	if (l < r){
		m = l + (r - l) / 2;
		mergeSort(sorted, l , m);
		mergeSort(sorted, m + 1, r);
		merge(sorted, l, m, r);
	}
}

int main()
{
	int n, *arr;
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		sorted[i] = arr[i];
	}
	mergeSort(sorted, 0, n-1);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (sorted[j] == arr[i]){
				printf("%d ", j);
				break ;
			}
		}
	}
	free(arr);
	return(0);
}
