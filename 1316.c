#include <stdio.h>
#include <stdlib.h>

/* 그룹 단어 체커 */

/* 그룹 단어란 단어에 존재하는 모든 문자에 대해서,
각 문자가 연속해서 나타나는 경우만을 말한다.
예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고,
kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만,
aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오. */


int				main()
{
	int			nbr, tgroup, is_group;
	char		**strs;
	int			*arr;

	scanf("%d", &nbr);
	strs = (char **)malloc(sizeof(char *) * nbr);
	for (int i = 0; i <nbr; i++)
	{
		strs[i] = (char *)malloc(100+1);
		scanf("%s", strs[i]);
	}
	arr = malloc(sizeof(int) * 26);
	tgroup = 0;
	for (int i = 0; i < nbr; i++)
	{
		is_group = 1;
		for (int i = 0; i < 26; i++)
			arr[i] = 0;
		while(*strs[i])
		{
			char std = *strs[i];
			arr[std - 97] += 1;
			while(*strs[i] == std)
				strs[i]++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] > 1)
				is_group = 0;
		}
		if (is_group)
			tgroup++;
	}
	free(arr);
	free(strs);
	printf("%d\n", tgroup);
	return (0);
}
