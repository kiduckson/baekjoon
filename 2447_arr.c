#include <stdio.h>
#include <string.h>

char d[2200][2200];

void set(int i, int n, int c){
    if(n>3){
        for(int j=i; j<i+n; j=j+n/3){
            for(int k=c; k<c+n; k=k+n/3) {
                if(j==i+n/3 && k==c+n/3) continue;
                else set(j, n/3, k);
            }
        }
    }
    else{
        for(int j=i; j<i+n; j++){
            if(j==i+1){
                memset(d[j]+c, '*', 1);
                memset(d[j]+c+2, '*', 1);
            }
            else memset(d[j]+c, '*', n);
        }
    }
}

int main(){
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++){
        memset(d[i], ' ', n);
        memset(d[i]+n, 0, 1);
    }

    set(0, n, 0);

    for(int i=0; i<n; i++) printf("%s\n", d[i]);
}
