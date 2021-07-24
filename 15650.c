#include <stdio.h>
#define MAX 9

int arr[MAX] = {0};
int vst[MAX] = {0};
int N, M;

void dfs(int count, int idx)
{
	if (count == M){
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = idx; i <= N; i++){
		if(!vst[i]){
			vst[i] = 1;
			arr[count] = i;
			dfs(count + 1, i + 1);
			vst[i] = 0;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	dfs(0, 1);
}
