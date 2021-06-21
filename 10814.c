#include <stdio.h>
#include <stdlib.h>

typedef		struct {
	int		age;
	char	name[101];
} member;

void merge(member arr[], int l, int m, int r){
	int i, j, k, idx_l, idx_r;

	idx_l = m - l + 1;
	idx_r = r - m;
	member arr_l[idx_l], arr_r[idx_r];

	for (i = 0; i < idx_l; i++)
		arr_l[i] = arr[l + i];
	for (j = 0; j < idx_r; j++)
		arr_r[j] = arr[m + 1 + j];

	i = j = 0;
	k = l;
	while (i < idx_l && j < idx_r){
		if (arr_l[i].age <= arr_r[j].age){
			arr[k] = arr_l[i];
			i++;
		}
		else{
			arr[k] = arr_r[j];
			j++;
		}
		k++;
	}
	while (i < idx_l)
		arr[k++]= arr_l[i++];
	while (j < idx_r)
		arr[k++]= arr_r[j++];
}

void mergeSort(member arr[], int l, int r)
{
	int m;
	if (l < r){
		m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
	int n;
	member *arr;
	scanf("%d", &n);
	arr = (member *)malloc(sizeof(member) * n);
	for (int i = 0; i < n; i++)
		scanf("%d %s", &arr[i].age, arr[i].name);
	mergeSort(arr, 0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d %s\n", arr[i].age, arr[i].name);
	free(arr);
	return (0);
}
