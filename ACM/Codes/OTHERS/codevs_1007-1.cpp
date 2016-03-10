#include"stdio.h"


int main(){

	int k,n=1;
	double sum=0;
	scanf("%d",&k);
	while(1){
		sum+= double(1/double(n));
		if(sum>k){
			printf("%d\n",n);
			return 0;
		}
		n++;
	
	}



}