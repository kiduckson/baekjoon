#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y, i, j;
	char **arr;
	int ans[51][51] = {0};

	scanf("%d %d", &y, &x);
	arr = (char **)malloc(sizeof(char *) * y);
	for (i = 0; i < y; i++)
	{
		arr[i] = (char *)malloc(x + 1);
		scanf("%s", arr[i]);
	}
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			// 나머지
			if (j > 0 && j < x - 1 && i > 0 && i < y - 1)
			{
				if (arr[i][j] == arr[i - 1][j])
					ans[i][j]++;
				if (arr[i][j] == arr[i + 1][j])
					ans[i][j]++;
				if (arr[i][j] == arr[i][j - 1])
					ans[i][j]++;
				if (arr[i][j] == arr[i][j + 1])
					ans[i][j]++;
			}
			// x , y == 0;
			else if (j == 0 && i == 0)
			{
				if (arr[i][j] == arr[i + 1][j])
					ans[i][j]++;
				if (arr[i][j] == arr[i][j + 1])
					ans[i][j]++;
			}
			// x == 0; y == len;
			else if (j == x - 1 && i == 0)
			{
				if (arr[i][j] == arr[i + 1][j])
					ans[i][j]++;
				if (arr[i][j] == arr[i][j - 1])
					ans[i][j]++;
			}
			// x == len; y == 0
			else if (j == 0 && i == 0)
			{
				if (arr[i][j] == arr[i + 1][j])
					ans[i][j]++;
				if (arr[i][j] == arr[i][j + 1])
					ans[i][j]++;
			}
			// x , y == len
			else if (j == x - 1 && i == y - 1)
			{
				if (arr[i][j] == arr[i + 1][j])
					ans[i][j]++;
				if (arr[i][j] == arr[i][j - 1])
					ans[i][j]++;
			}
		}
	}
	for (i = 0; i < y; i++)
	{
		printf("\n");
		for (j = 0; j < x; j++)
			printf("%d", ans[i][j]);
	}
	free(arr);
}
