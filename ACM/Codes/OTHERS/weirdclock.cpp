#include"stdio.h"
#include"stdlib.h"

#define rd 60


int main(){

	int C_time,d,n_time;
	while(scanf("%d%d",&C_time,&d)==2){
		if(C_time==0 && d==0)
			break;
		else{
			d++;
			n_time=C_time;
			int count=0;
			while(1){
				n_time*=d;
				n_time%=rd;
				count++;
				if(n_time==0){
					printf("%d\n",count);
					break;
				}
				else if(n_time==C_time){
					printf("Impossible\n");
					break;
				}
			}
		}
	}
	return 0;
}
