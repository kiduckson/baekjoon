/*
Brute Force
21 > cards
kim play with sang chang;
each has positive whole
dealer puts n down then tells M
each player must choose N cards which must be under M

1. num of cards
2. max num;
3. output closest max
최대 세장
가장 큰수 더하기
그다음의 큰수
*/
#include <stdio.h>

int main()
{
	int n, max, i, j, k;
	int arr[101];
	int ans;
	scanf("%d%d", &n, &max);
	ans = 0;
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < n - 2; i++)
		for (j = i + 1; j < n - 1; j++)
			for (k = j + 1; k < n; k++)
				if (max >= arr[i] + arr[j] + arr[k])
					if (ans < arr[i] + arr[j] + arr[k])
						ans = arr[i] + arr[j] + arr[k];
	printf("%d", ans);
	return (0);
}
