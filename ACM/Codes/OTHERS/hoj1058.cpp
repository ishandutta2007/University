#include"stdio.h"
#include"stdio.h"

int data[1020][1020];

int _max(int a,int b){
	return a>b? a:b;
}


int main(){
	int n;
	int i,j;
	int max;
	while(scanf("%d",&n)==1){
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
				scanf("%d",&data[i][j]);
		
		for(i=2;i<=n;i++)
			for(j=1;j<=i;j++)
				data[i][j]=data[i][j]+_max(data[i-1][j],data[i-1][j-1]);
		max=data[n][1];
		for(i=2;i<=n;i++)
			if(data[n][i]>max)
				max=data[n][i];
		printf("%d\n",max);
	}
	
	return 0;
	
}
