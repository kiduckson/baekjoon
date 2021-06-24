#include <stdio.h>
#define MAX 9

int arr[MAX] = {0};
int N, M;

void dfs(int count){
	if (count == M){
		for (int i = 0; i < M; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = (count == 0) ? 1 : arr[count-1] ; i <= N; i++){
		arr[count] = i;
		dfs(count + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	dfs(0);
}
