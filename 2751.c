#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k, idx_l, idx_r;

	idx_l = m - l + 1;
    idx_r = r - m;

    int arr_l[idx_l], arr_r[idx_r];

    for (i = 0; i < idx_l; i++)
        arr_l[i] = arr[l + i];
    for (j = 0; j < idx_r; j++)
        arr_r[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < idx_l && j < idx_r) {
        if (arr_l[i] <= arr_r[j]) {
            arr[k] = arr_l[i];
            i++;
        }
        else {
            arr[k] = arr_r[j];
            j++;
        }
        k++;
    }
    while (i < idx_l) {
        arr[k] = arr_l[i];
        i++;
        k++;
    }
    while (j < idx_r) {
        arr[k] = arr_r[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r){
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
	int n, i;
	int *arr;

	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	mergeSort(arr, 0, n - 1);
	for (i = 0; i < n; i++){
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;
}
