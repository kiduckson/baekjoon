


#include <stdio.h>

int N;
int team[20][20];
int t1;
int t2;


void solve(int cnt, int t1, int t2)
{
	if (cnt == N / 2)
		return (t1 - t2 < 0 ? -(t1 - t2) : t1 - t2);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i != j){

			}
		}
	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &team[i][j]);
	solve(0, 0, 0);
}
