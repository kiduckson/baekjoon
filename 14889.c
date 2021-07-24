#include <stdio.h>

int teams[21][21];
int check[22];
int N;
int ans = 1000000000;

void DFS(int x, int pos)
{
	if (x == N/2) // 카운트수가 정원의 1/2가 됬을때 능력치 합 계산
	{
		int start, link, tmp;
		link = start = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (check[i] == 1 && check[j] == 1) start += teams[i][j];
				if (check[i] == 0 && check[j] == 0) link += teams[i][j];
			}
		}
		tmp = start - link > 0 ? start - link : -(start - link);
		if (ans > tmp)
			ans = tmp;
	}
	for (int i = pos; i < N; i++)
	{
		check[i] = 1;
		DFS(x + 1, i + 1);
		check[i] = 0;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &teams[i][j]);
	DFS(0, 1);
	printf("%d\n", ans);
}
