/*
어떤 자연수 N이 있을때 그 자연수 N의 분해합은 N과 N을 이루는 자리수의 합
M의 분해합이 N 인 경우 M을 N의 생성자라고 한다. 예를 들어,
245의 분해합은 256(=245+2+4+5)이 된다.
따라서 245는 256의 생성자가 된다.

생성자 245
245의 분해합 256;
256의 생성자 245

*/

#include <stdio.h>

int main()
{
	int N;
	int total;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		total = 0;
		for (int j = i; j != 0; j /= 10)
			total += j % 10;
		if(N == i + total)
		{
			printf("%d\n", i);
			return (0);
		}
	}
	printf("%d\n", 0);
	return (0);
}
