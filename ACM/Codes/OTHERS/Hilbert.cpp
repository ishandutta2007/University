#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"

char hirbert[11][2e+11][2e+11];


void fill_h(int n){
	

}

int main(){

	int i,j,k;
	for(i=1;i<=10;i++)
		for(j=1;j<=exp((i+1)*log(2));i++)
			for(k=1;k<=exp((i+1)*log(2));k++)
				hilbert[i][j][k]=' ';
	hilbert[1]
	for(i=2;i<=10;i++)
		fill_h(n);
	
	int x;
	// int i,j;
	while(scanf("%d",&x)==1){
		for(i=1;i<=exp((n+1)*log(2))){
			for(j=1;j<=exp((n+1)*log(2)))
				printf("%c",hilbert[x][i][j]);
			printf("\n");
		}
		printf("\n");
	
	}
	return 0;
}