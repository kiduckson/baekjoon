#include <stdio.h>
#include <stdlib.h>
#define N 9

int grid[N][N];

int isPromising(int row, int col, int num){
	for (int i = 0; i < N; i++){
		if (grid[row][i] == num)
			return 0;
	}
	for (int i = 0; i < N; i++){
		if(grid[i][col] == num)
			return 0;
	}
	int startRow = row - row % 3;
	int startCol = col - col % 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if(grid[i+startRow][j+startCol] == num)
				return 0;
	return 1;
}
void printSudoku(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}
int solveSudoku(int row, int col)
{
    if (row == N - 1 && col == N)
        return 1;
    if (col == N)
    {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
        return solveSudoku(row, col + 1);

    for (int num = 1; num <= N; num++)
    {
        if (isPromising(row, col, num)==1)
        {
            grid[row][col] = num;
            if (solveSudoku(row, col + 1)==1)
                return 1;
        }
        grid[row][col] = 0;
    }
    return 0;
}
int main()
{
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &grid[i][j]);
		}
	}
	solveSudoku(0, 0);
	printSudoku();
}
