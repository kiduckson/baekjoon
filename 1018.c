#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y, i, j, k, l, wsum, bsum, ans;
	char **arr;

	scanf("%d %d", &y, &x);
	arr = (char **)malloc(sizeof(char *) * y);
	for (i = 0; i < y; i++)
	{
		arr[i] = (char *)malloc(x + 1);
		scanf("%s", arr[i]);
	}
	ans = x * y / 2;
	for (i = 0; i < y - 7; i++){
		for (j = 0; j < x - 7; j++){
			wsum = bsum = 0;
			for (k = i; k < i + 8; k++){
				for (l = j; l < j + 8; l++){
					if((k + l) % 2)
					{
						if (arr[k][l] == 'B')
							wsum++;
						else
							bsum++;
					}
					else
					{
						if (arr[k][l] == 'B')
							bsum++;
						else
							wsum++;
					}
				}
			}
			bsum = bsum > wsum ? wsum : bsum;
			ans = ans > bsum ? bsum : ans;
		}
	}
	printf("%d", ans);
	free(arr);
	return (0);
}




