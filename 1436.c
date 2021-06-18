/*
666 is the number of apocalipse;
Shuan is the direct of a movie called 'The End of the world';
When George Lucas was directing Starwars franchaise, he named each entry
a consecutive manner (each entailed with its relative numbering at the end).
Peter Jackson also followed this simple numbering scheme, named his Lord of Rings entries in the same way.

But Shaun decided to make his own way, naming each movies of his with triple sixes inside; and it as same as
the follows:
666
1666
2666
so on.

Write a program returns the numbering of the movie with the given input N;

rule no1.
- first is 666, 1666, 2666 9666
*/

#include <stdio.h>

int main()
{
	int i, tmp, n, ans, sixes;
	scanf("%d", &n);
	i = 666;
	ans = 0;
	while (ans < 10000)
	{
		tmp = i;
		sixes = 0;
		while(tmp)
		{
			if (tmp % 10 == 6 && sixes != 3)
				sixes++;
			if (tmp % 10 != 6 && sixes != 3)
				sixes = 0;
			tmp /= 10;
		}
		if (sixes == 3)
			ans++;
		if (ans == n)
			break;
		i++;
	}
	printf("%d", i);
	return (0);
}
