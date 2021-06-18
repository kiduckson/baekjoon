#include <stdio.h>
#include <stdlib.h>

int int_len(int n)
{
	int len = 1;
	while (n > 9){
		len++;
		n /= 10;
	}
	return len;
}

int main()
{
	int n, len, *arr;
	int count[11] = {0};
	scanf("%d", &n);
	len = int_len(n);
	arr = (int*)malloc(sizeof(int)*len);
	for (int i = len - 1; i >= 0; i--){
		arr[i] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < len; i++)
		count[arr[i]]++;
	for (int i = 10; i >= 0; i--)
		for (int j = 0; j < count[i]; j++)
			printf("%d", i);
	free(arr);
	return 0;
}
