#include <stdio.h>
// https://mathbang.net/101

int b_abs(int a)
{
	return a < 0 ? -a : a;
}

int main()
{
	int nbr, x1, y1, r1, x2, y2, r2;
	int dt, dr, tr;
	scanf("%d", &nbr);
	for (int i = 0; i < nbr; i++)
	{
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		dt = (b_abs(x1 - x2) * b_abs(x1 - x2)) + (b_abs(y1 - y2) * b_abs(y1 - y2));
		dr = b_abs(r1 - r2) * b_abs(r1 - r2);
		tr = (r1 + r2) * (r1 + r2);
		if (x1 == x2 && y1 == y2 &&  r1 == r2)
			printf("%d\n", -1);
		else if (dt == dr || dt == tr)
			printf("%d\n", 1);
		else if (dr < dt && dt < tr)
			printf("%d\n", 2);
		else
			printf("%d\n", 0);
	}
	return (0);
}
