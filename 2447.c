#include <stdio.h>
#include <math.h>

/* n == 3일 경우
***
* *
***
위와같은 형태가 기본이 됨. 가운데가 비어있게 되는데 비어있는 부분의 좌표는 1,1;
계속되는 형태에선 (1,1) (1,4)... (1,25);
따라서 규칙의 형태는 x%3 == 1 && y%3 == 1;

n == 9일경우
*********
* ** ** *
*********
***   ***
* *   * *
***   ***
*********
* ** ** *
*********
모양만 커졌지 패턴은 같다.
가운데가 비어있는 좌표는 (3,3) (3,4) ... (5,5)
이를 수식으로 표현하면 기본단위 모형이 나온후 비어있다는 표현;
따라서 (x / 3 ) % 3 == 1 && y / 3 % 3 == 1;


*/

// printf("i:: %d; j:: %d; num : %d\n", i, j, num);
// coordinate를 받아서 num으로 나눠서 1 남으면 공백을 찍고 재귀에서 아웃
// 3으로 나눌필요 없는것이 숫자는 다 어짜피 3의 제곱수
void b_stars(int i, int j, int num)
{
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1)
		printf(" ");
	else
	{
		if (num / 3 == 0)
			printf("*");
		else
			b_stars(i, j, num / 3);
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			b_stars(i, j, num);
		printf("\n");
	}
}
