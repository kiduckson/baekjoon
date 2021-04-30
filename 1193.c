/* An infinite array holds infinite factions

무한히 큰 배열에 다음과 같이 분수들이 적혀있다.

1	2	6	7	15
1/1	1/2	1/3	1/4	1/5	…
3	5	8	14
2/1	2/2	2/3	2/4	…	…
4	9	13
3/1	3/2	3/3	…	…	…
10	12
4/1	4/2	…	…	…	…
11
5/1	5/2	…	…	…	…

6/1	6/2	…	…	…	…
이와 같이 나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.

X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오. */

#include <stdio.h>

// int main()
// {
// 	int in, nu, de;

// 	scanf("%d", &in);
// 	nu = (in / 2) + ((in % 2) != 0);
// 	de = (in % 2) ? 1 : 2;
// 	printf("%d/%d",nu, de);
// }

// 1  => 1
// 2  idx + 1 * idx / 2 = idxsum //  3
// 3  (idx + 1 * idx / 2) + (idx / 2 + 1) = idxsum;

int main()
{
	int nbr, idx, idxsum, a, b;
	char *rst;

	scanf("%d",&nbr);
	if (nbr == 1)
	{
		printf("%d/%d", 1, 1);
		return (0);
	}

	idx = 1;
	idxsum = 1;
	while(idxsum < nbr)
	{
		idx++;
		if(idx % 2)
			idxsum = (idx + 1) * (idx / 2) + (idx / 2 + 1);
		else
			idxsum = (idx + 1) * (idx / 2);
	}
	printf("idx %d\n", idx);
	printf("idxsum %d\n", idxsum);
	int dif = idxsum - nbr;
	if (idx % 2 != 0)
	{
		a = idx - dif;
		b = dif + 1;
	}
	else
	{
		a = dif + 1;
		b = idx - dif;
	}
	printf("%d/%d",a,b);
}
