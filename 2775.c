
/*
평소 반상회에 참석하는 것을
좋아하는 주희는 이번 기회에 부녀회장이 되고 싶어
각 층의 사람들을 불러 모아 반상회를 주최하려고 한다.

이 아파트에 거주를 하려면 조건이 있는데,
“a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지
사람들의 수의 합만큼 사람들을 데려와 살아야 한다”
는 계약 조항을 꼭 지키고 들어와야 한다.

아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 왔다고 가정했을 때,
주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있는지 출력하라.
단, 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.

3층 1 5 15 35 70 126
2층 1 4 10 20 35 56
1층 1 3 6 10 15 21
0층 1 2 3 4 5 6
*/

#include <stdio.h>
#include <stdlib.h>

int			main()
{
	int		t, floor, nth, rst, std;
	int		**arr;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &floor, &nth);
		arr = (int **)malloc(sizeof(int *) * (floor + 1));
		for (int j = 0; j <= floor; j++)
		{
			arr[j] = (int*)malloc(sizeof(int) * (nth + 1));
			arr[j][0] = 0;
			for (int k = 1; k <= nth; k++)
			{
				if (j == 0)
					arr[j][k] = k;
				else
				{
					std = 1;
					arr[j][k] = 0;
					while(std <= k)
					{
						arr[j][k] += arr[j-1][std++];
					}
				}
				printf("arr[%d][%d] %d\n", j, k, arr[j][k]);
			}
		}
		printf("%d\n", arr[floor][nth]);
		free(arr);
	}
}


// int main() {
// 	int k, T;
// 	int n;
// 	int arr[14];
// 	scanf("%d", &T);
// 	for (int t = 0; t < T; t++) {
// 		scanf("%d%d", &k, &n);
// 		for (int i = 0; i < n; i++)
// 			arr[i] = i + 1;
// 		for (int j = 0; j < k; j++) {
// 			for (int i = 1; i < n; i++) {
// 				arr[i] += arr[i - 1];
// 			}
// 		}
// 		printf("%d\n", arr[n-1]);
// 	}
// }
