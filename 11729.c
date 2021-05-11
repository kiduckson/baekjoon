
/*
Take an example for 2 disks :

Step 1 : Shift first disk from 1 to 2.
Step 2 : Shift second disk from 1 to 3.
Step 3 : Shift first disk from 2 to 3.

The pattern here is :
Shift 'n-1' disks from 1 to 2.
Shift last disk from 1 to 3.
Shift 'n-1' disks from 2 to 3.

Image illustration for 3 disks :
*/

#include <stdio.h>
#include <math.h>

void b_hanoi(int n, char src, char dst, char tmp) {
	if (n > 0)
	{
		b_hanoi(n - 1, src, tmp, dst);
		printf("%c %c\n", src, dst);
		b_hanoi(n - 1, tmp, dst, src);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)pow(2, n) - 1);
	b_hanoi(n,'1','3','2');
}
