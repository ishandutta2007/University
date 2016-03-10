#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int ll[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};


int main(){
	int N,M;
	int n,len,_count;
	int flag[10001];
	
	
	while(scanf("%d%d",&N,&M)==2){
		n=N;
		len=0;
		_count=0;
		memset(flag,0,sizeof(flag));
		flag[N%M]=1;
		while(n>0){
			n/=10;
			len++;
		}
		// printf("len=%d\n",len);
		n=N%M;
		while(n!=0){
			_count++;
			n=n*ll[len]+N;
			// printf("n=%d\n",n);
			n%=M;
			if(flag[n]==1){
				break;
			}
			flag[n]=1;
		}
		if(n==0) printf("%d\n",_count+1);
		else printf("0\n");
	
	}
	return 0;
}