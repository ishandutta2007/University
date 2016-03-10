#include"stdio.h"

int main(){
	int _time,d;
	int i;
	while(scanf("%d%d",&_time,&d)==2){
		if(_time==0 && d==0)
			break;
		if(_time%60==0){
			printf("0\n");
			continue;
		}
		_time*=d+1;
		if(_time%60==0){
			printf("1\n");
			continue;
		}
		_time*=d+1;
		if(_time%60==0){
			printf("2\n");
			continue;
		}
		printf("Impossible\n");
	}
	return 0;
}