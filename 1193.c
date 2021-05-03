#include <stdio.h>

/*

무한히 큰 배열에 다음과 같이 분수들이 적혀있다.

1/1	1/2	1/3	1/4	1/5	…
2/1	2/2	2/3	2/4	…	…
3/1	3/2	3/3	…	…	…
4/1	4/2	…	…	…	…
5/1	…	…	…	…	…
…	…	…	…	…	…
이와 같이 나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> … 과 같은
 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.

X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.

*/

int main()
{
	int nbr, idx, idxsum, a, b, dif;
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
	dif = idxsum - nbr;
	if (idx % 2 != 0)
	{
		a = dif + 1;
		b = idx - dif;
	}
	else
	{
		a = idx - dif;
		b = dif + 1;
	}
	printf("%d/%d",a,b);
    return (0);
}
