#include <stdio.h>
#define N 9
int map[N][N];
int row[N];
int col[N];
int cell[N];
int Qx[81];
int Qy[81];
int num;
void printmap(){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
}

void dfs(int cnt){
	int c = Qx[cnt];
	int r = Qy[cnt];
	int i;
	if(cnt==num){
		printmap();
		exit(0);
	}
	int empty = 0;
	empty |= row[r];
	empty |= col[c];
	empty |= cell[r/3*3+c/3];

	for(i=1;i<=9;i++){
		if(!(empty&1<<i)){
			map[r][c]=i;
			row[r]|=1<<i;
			col[c]|=1<<i;
			cell[r/3*3+c/3]|=1<<i;
			dfs(cnt+1);
			map[r][c]=0;
			row[r]^=1<<i;
			col[c]^=1<<i;
			cell[r/3*3+c/3]^=1<<i;
		}
	}
	return;

}



int main(){

	int i, j;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]!=0){
				row[i]|=1<<map[i][j];
				col[j]|=1<<map[i][j];
				cell[(i/3)*3+j/3]|=1<<map[i][j];
			}else{
				Qx[num]=j;
				Qy[num]=i;
				num++;
			}
		}
	}
	dfs(0);
}
