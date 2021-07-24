#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} point;

void merge(point arr[], int l, int m, int r)
{
    int i, j, k, idx_l, idx_r;

	idx_l = m - l + 1;
    idx_r = r - m;

	point arr_l[idx_l], arr_r[idx_r];

    for (i = 0; i < idx_l; i++)
        arr_l[i] = arr[l + i];
    for (j = 0; j < idx_r; j++)
        arr_r[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < idx_l && j < idx_r){
		if (arr_l[i].y < arr_r[j].y){
			arr[k] = arr_l[i];
			i++;
		}
		else if (arr_l[i].y > arr_r[j].y){
			arr[k] = arr_r[j];
			j++;
		}
		else{
			if (arr_l[i].x < arr_r[j].x){
				arr[k] = arr_l[i];
				i++;
			}
			else if (arr_l[i].x > arr_r[j].x){
				arr[k] = arr_r[j];
				j++;
			}
		}
		k++;
	}
	while (i < idx_l)
		arr[k++] = arr_l[i++];
	while (j < idx_r)
		arr[k++] = arr_r[j++];
}

void mergeSort(point arr[], int l, int r)
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
	int n;
	point *arr;

	scanf("%d", &n);
	arr = (point*)malloc(sizeof(point) * n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
	free(arr);
	return (0);
}
