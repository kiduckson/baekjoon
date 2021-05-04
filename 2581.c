#include <stdio.h>
#include <math.h>

int main()
{
	int min, max, idx, is_first;
	int rst;
	int arr[10001];

	rst = 0;
	scanf("%d %d", &min, &max);
	arr[0] = arr[1] = 0;
	arr[2] = arr[3] = 1;
	idx = 5000;

	// initialize 1로 채우기
	for (int i = 2; i < 10001; i++)
		arr[i] = 1;

	// 2의 제곱 0으로 채우기
	for (int i = 2; i < idx; i++)
		if (i * 2 < 10001)
			arr[i * 2] = 0;
	// 3의 제곱 0으로 채우기
	// for (int i = 2; i < idx; i++)
	// 	if (i * 3 < 10001)
	// 		arr[i * 3] = 0;

	// 배수 채워넣기
	for(int i = 2; i < idx; i++)
		if (arr[i] == 1)
			for (int j = 2; j < idx; j++)
				if (j * i < 10001)
					arr[j * i] = 0;
	is_first = 0;
	for(int i = min; i <= max; i++)
	{
		if(arr[i] == 1)
		{
			if (is_first == 0)
				is_first = i;
			rst += i;
		}
	}
	if (rst > 0)
	{
		printf("%d\n", rst);
		printf("%d\n", is_first);
	}
	else
		printf("-1");
}
