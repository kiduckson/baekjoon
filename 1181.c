#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef		struct {
	char	str[51];
	int		len;
} words;

int b_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len])
		len++;
	return len;
}

int b_compare(words s1, words s2)
{
	int idx;
	idx = 0;
	if (s1.len > s2.len)
		return (1);
	while (s1.str[idx] && s2.str[idx])
	{
		if(s1.str[idx] < s2.str[idx])
			return (1);
		else if (s1.str[idx] > s2.str[idx])
			return (0);
		idx++;
	}
	return (-1);
}

void merge(words arr[], int l, int m, int r)
{
    int i, j, k, idx_l, idx_r;

	idx_l = m - l + 1;
    idx_r = r - m;

	words arr_l[idx_l], arr_r[idx_r];

    for (i = 0; i < idx_l; i++)
        arr_l[i] = arr[l + i];
    for (j = 0; j < idx_r; j++)
        arr_r[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < idx_l && j < idx_r){
		if (arr_l[i].len < arr_r[j].len){
			arr[k] = arr_l[i];
			i++;
		}
		else if (arr_l[i].len > arr_r[j].len){
			arr[k] = arr_r[j];
			j++;
		}
		else{
			if(b_compare(arr_l[i], arr_r[j])){
				arr[k] = arr_l[i];
				i++;
			}
			else {
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

void mergeSort(words arr[], int l, int r)
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
	words *arr;

	scanf("%d", &n);
	arr = (words*)malloc(sizeof(words) * n);
	for (int i = 0; i < n; i++){
		scanf("%s", arr[i].str);
		arr[i].len = b_strlen(arr[i].str);
	}
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++){
		if (i > 0)
			if (strcmp(arr[i].str, arr[i-1].str) == 0)
				continue;
		printf("%s\n", arr[i].str);
	}
	free(arr);
	return (0);
}
