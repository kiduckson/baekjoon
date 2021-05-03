#include <stdio.h>

int main()
{
	int len1, len2, max, num1, num2, rd, idx;
	int ans[10001];
	char str1[10001], str2[10001];

	scanf("%s %s", str1, str2);
	len1 = 0, len2 = 0, rd = 0, idx = 0;
	while(str1[len1])
		len1++;
	while(str2[len2])
		len2++;
	max = len1 > len2 ? len1 : len2;
	while(max-- != 0)
	{
		num1 = --len1 < 0 ? 0 : str1[len1] - 48;
		num2 = --len2 < 0 ? 0 : str2[len2] - 48;
		ans[idx] = (num1 + num2 + rd) % 10;
		rd = (num1 + num2 + rd )/ 10;
		idx++;
	}
	if (rd)
		ans[idx] = rd;
	idx = rd ? idx : idx - 1;
	for (int i = idx; i >= 0; i--)
		printf("%d", ans[i]);
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	int len1, len2, max, num1, num2, rd, idx;
// 	int ans[10001];
// 	char str1[10001], str2[10001];
// 	scanf("%s %s", str1, str2);
// 	len1 = 0, len2 = 0;
// 	while(str1[len1])
// 		len1++;
// 	while(str2[len2])
// 		len2++;
// 	max = len1 > len2 ? len1 : len2;
// 	rd = 0;
// 	idx = 0;
// 	while(max != 0)
// 	{
// 		len1--;
// 		len2--;
// 		max--;
// 		num1 = len1 < 0 ? 0 : str1[len1] - 48;
// 		num2 = len2 < 0 ? 0 : str2[len2] - 48;
// 		printf("num1 %d\n", num1);
// 		ans[idx] = (num1 + num2 + rd) % 10;
// 		printf("ans[%d] %d\n", idx, ans[idx]);
// 		rd = (num1 + num2 + rd )/ 10;
// 		idx++;
// 	}
// 	if (rd)
// 		ans[idx] = rd;
// 	idx = rd ? idx : idx - 1;
// 	for (int i = idx; i >= 0; i--)
// 		printf("%d", ans[i]);
// 	return (0);
// }
// /*

// 1. 각자 길이에서 1 씩 뺌 (인덱스 넘버);
// 2. 더하고 10 나누기 나머지를 넣고
// 3. 더하고 나누기 나온 숫자를 나머지로 넣고
// 4. 계속 진행
// 5. 한 숫자의 0이 도달하면 그숫자는 항상 0을 리턴
// 6. 가장 긴 길이가 다도달할떄 까지 진행

// */
