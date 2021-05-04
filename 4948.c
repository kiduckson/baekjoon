/* 그룹

베르트랑 공준은 임의의 자연수 n에 대하여,
n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.

이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.

예를 들어, 10보다 크고,
20보다 작거나 같은 소수는 4개가 있다. (11, 13, 17, 19)
또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)

자연수 n이 주어졌을 때,
n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int input, max, count, i, j;
	int *arr;

	scanf("%d", &input);
	while (input != 0)
	{
		max = input * 2 + 1;
		count = 0;
		arr = malloc(sizeof(int) * max);
		for (i = 2; i < max; i++)
			arr[i] = 1;
		for (i = 2; i * i < max; i++)
			if (arr[i])
				for (j = i * i; j < max; j+=i)
					arr[j] = 0;
		for (i = input + 1; i < max; i++)
			if (arr[i])
				count++;
		printf("%d\n", count);
		free(arr);
		scanf("%d", &input);
	}
}
