#include <stdio.h>
#define N 8

int solveKTUtils(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);


// A utility function to check if i,j are valid indexes for N*N chessboard
// -1로 이니셜라이즈를 해서 -1이 아니면 이미 왔다갔다는 소리가 되니까 세이프 하지 않음
int isSafe(int x, int y, int sol[N][N]){
	return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}
// A utility function to print solution matrix sol[N][N];
void printSolution(int sol[N][N]){
	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++)
			printf(" %2d ", sol[x][y]);
		printf("\n");
	}
}
/*
this function solves the knight tour problem using backtracking. this function mainly
use solveKTUtil() to solve the problem. It retuns false if no compltete tour is possible,
otherwise return true and prints the tour. Please note that there may be more than one oslutions
this function prints one of the feasible solutions
*/

int solveKT(){
	int sol[N][N];
	// initilize solution matrix
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;
	/*
		xMove[] and ymove[] define next move of knight.
		xmove[] is for next value of x coordinate
		ymove[] is for next	value of y coordinate
		나이트가 움직일 수 있는 8개의 움직임 x랑 y축 이동
	*/
	int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2};
	int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
	// since the knight is initially at the first block
	sol[0][0] = 0;
	// start from 0, 0 and explore all tours using solveKTUtils()
	if (solveKTUtils(0, 0, 1, sol, xMove, yMove) == 0) {
		printf("solution does not exist");
		return (0);
	}
	else
		printSolution(sol);
	return 1;
}

int solveKTUtils(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N]){
	int k, next_x, next_y;
	// 끝까지 다가면 8*8 = 64; thus traverse all the cell
	if (movei == N * N)
		return 1;
	// try all next moves from the current coordinate x, y
	for (k =0; k <8; k++){
		// 현재 x에다가 첫번쨰 무브 해봄
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		// 안전하면 무브 숫자 씀 (처음엔 1로 시작했으니까 1을 넣음 무브 1)
		if (isSafe(next_x, next_y, sol)){
			sol[next_x][next_y] = movei;
			// 재귀로 solve부름 계속해서 스택으로 다음 콜이 쌓이기때문에 아래께 실행되지 않음 == 1이 될때까지
			if (solveKTUtils(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
				return 1;
			else
				sol[next_x][next_y] = -1;
		}
	}
	return 0;
}

int main()
{
	solveKT();
	return (0);
}
