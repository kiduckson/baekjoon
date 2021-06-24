#include <stdio.h>
#include <stdlib.h>
#define N 9

int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

// 1. 가로줄
int isPromising(int row, int col, int num){
	for (int i = 0; i < N; i++){
		if (i != col && grid[row][i] == num)
			return 0;
	}
	for (int i = 0; i < N; i++){
		if(i != row && grid[i][col] == num)
			return 0;
	}
	int startRow = row - row % 3;
	int startCol = col - col % 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if(i != row && j!= col && grid[i+startRow][j+startCol] == num)
				return 0;
	return 1;
}

void solveSudoku(int row, int col)
{
	if (row == N-1 && col == N-1)
		exit(0);
	// 첫재칸에 숫자 넣기
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (grid[i][j] == 0){
				for (int k = 1; k <= 9; k++){
					if (isPromising(i, j, k)){
						grid[i][j] = k;
						if (j == N-1)
							solveSudoku(i+1, j);
						else
							solveSudoku(i, j+1);
					}
				}

			}
		}
	}

}
int main()
{
	// for (int i = 0; i < N; i++){
	// 	for (int j = 0; j < N; j++){
	// 		scanf("%d", &grid[i][j]);
	// 	}
	// }
	// printf("\n");
	// printf("\n");

	solveSudoku(0, 0);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}
