#include <stdio.h>
#define MAX 9

int N, M;
int visited[MAX] = {0};
int arr[MAX] = {0};

void dfs(int count){
	if (count == M){
		for (int i = 0; i < M; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++){
		arr[count] = i;
		dfs(count + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	dfs(0);
}
