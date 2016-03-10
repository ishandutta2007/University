#incldue"stdio.h"
#include"stdlib.h"
#include"limits.h"


int needed[6]={0,0,2,1,0,1};
int had[6]={0};


int main(){
	int _time,d;
	while(scanf("%d%d,&_time,&d")==2){
		if(_time==0 && d==0)
			break;
		int had[6]={0};
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
		int m=1;
		int isok=1;
		for(i=2;i<=5;i++)
			if(needed[i]>=had[i] && had[i]>=0)
				m=max(needed[i]/had[i],m);
			else if(needed[i]>0 && had[i]<=0)
				isok=0;
		if(isok==1)
			printf("%d\n",m);
		else
			printf("Impossible\n");
	}
	return 0;
}