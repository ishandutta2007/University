#include"stdio.h"
#include"stdlib.h"
#include"limits.h"




int max(int a,int b){
	if (a>=b)
		return a;
	else 
		return b;
}


int main(){
	int _time,d;
	int i;
	while(scanf("%d%d",&_time,&d)==2){
		if(_time==0 && d==0)
			break;
		int had[6]={0};
		int needed[6]={0,0,2,1,0,1};
		d++;		
		for(i=2;i<=5;i++)
			while(_time%i==0){
				needed[i]--;
				_time/=i;
			}
			
		for(i=2;i<=5;i++){
			if(had[i]>=needed[i])
				continue;
			while(d%i==0){
				had[i]++;
				d/=i;
				if(had[i]>=needed[i])
					break;
			}
		}
		
		// for(i=1;i<=5;i++)
			// printf("need:%d had:%d\n",needed[i],had[i]);
		
		
		int isok=1;
		for(i=2;i<=5;i++)
			if(needed[i]>0 && had[i]<=0)
				isok=0;
		if(isok==0){
			printf("Impossible\n");\
			continue;
		}
		
		
		for(i=1;;i++){
			if(had[2]*i>=needed[2] && had[3]*i>=needed[3] && had[5]*i>=needed[5])
				printf("%d\n",i);
				break;
		}
		
		
		
		
		// int m=1;
		// int isok=1;
		// printf("!!!completed\n");
		// for(i=2;i<=5;i++)
			// if(needed[i]>=had[i] && had[i]>=0)
				// m=max(needed[i]/had[i],m);
			// else if(needed[i]>0 && had[i]<=0)
				// isok=0;
		
		// printf("!!!completed\n");
		// if(isok==1)
			// printf("%d\n",m);
		// else
			// printf("Impossible\n");
	}
	return 0;
}