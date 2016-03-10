#include"stdio.h"
#include"stdlib.h"


int fact(int n){
	if(n==0)
		return 1;
	else
		return n*fact(n-1);

}


int main(){
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n1 2\n2 2.5\n");
	double e=0;
	int i;
	
	for(i=0;i<=9;i++){
		e+=double(1/double(fact(i)));
		if(i>=3)
			printf("%d %.9lf\n",i,e);
	}
	system("pause");
	return 0;

}