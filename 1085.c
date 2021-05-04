/*
한수는 지금 (x, y)에 있다.
직사각형의 왼쪽 아래 꼭짓점은 (0, 0)에 있고, 오른쪽 위 꼭짓점은 (w, h)에 있다.
직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

0 - x;
w - x;
	whatver the smallest

0 - y
h - y
	whatver the smallest

*/

#include <stdio.h>

int			b_abs(int x)
{
	return (x < 0 ? -x : x);
}

int			main()
{
	int x, y, w, h, xrst, yrst;

	scanf("%d%d%d%d",&x,&y,&w,&h);
	xrst = b_abs(0 - x) > b_abs(w - x) ? b_abs(w - x) : b_abs(0 - x);
	yrst = b_abs(0 - y) > b_abs(h - y) ? b_abs(h - y) : b_abs(0 - y);
	printf("%d\n", xrst < yrst ? xrst : yrst);
	return 0;
}
