#include <stdio.h>
#include <stdlib.h>

// a 랑 a-1이랑 비교해서 a가 a-1 보다 작으면 서로 위치 바꾸기
// a-n > 0동안
// a-n 이랑 a-n-1이랑 비교
// 작으면 서로 위치 바꾸기
// while (a-n-1 > 0)
// if


int main(){
	int n, i, j, tmp;
	int k[1000];

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &k[i]);
	}
	for (int i = 0; i < n; i++)
	{
		j = 0;
		while(i - j - 1 >= 0)
		{
			if(k[i-j] < k[i-j-1]){
				tmp = k[i-j-1];
				k[i-j-1] = k[i-j];
				k[i-j] = tmp;
			}
			j++;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", k[i]);
}
