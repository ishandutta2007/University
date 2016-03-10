#include <stdio.h>

int main(){
    
    int i,j;
    int count=0;
    while(scanf("%d",&i)==1)
	{
		for(j=0;j<32;j++) {
			if(i&(1<<j)){
				count++;
			}
			
			
		}
			
			
		printf("i=%d:   %d\n",i,count);
    }
    return 0;
}