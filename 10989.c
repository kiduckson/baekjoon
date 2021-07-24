#include <stdio.h>
#define MAX 10001

int main()
{
	int n, i, j, tmp, idx;
	int *arr;
	int counting[MAX] = {0};

	// 숫자 개수
	scanf("%d", &n);
	// 인덱스
	idx = 0;
	for (i = 0; i < n; i++){
		// 숫자 받아서
		scanf("%d", &tmp);
		// 카운팅에 넣기
		counting[tmp]++;
		// 만약에 tmp가 인덱스 보다 크면
		// 인덱스는 템프
		// 이 인덱스가 가장 큰 숫자가 된다
		if (tmp > idx)
			idx = tmp;
	};
	// 젤 큰 수까지만
	for (i = 0; i <= idx; i++){
		// j로 이 숫자가 몇갠지 봄 0보다
		// 예) counting[9] = 2; 9가 두번 나옴
		for(j = 0; j < counting[i]; j++)
			printf("%d\n", i);
	}
	return (0);
}
