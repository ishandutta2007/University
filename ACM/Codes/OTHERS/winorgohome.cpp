#include"cstdio"
#include"cmath"
#include"iostream"

using namespace std;

int check(int a){
	if(a==2)
		return 1;
	for(int i=2;i<=sqrt(a);i++){
		if(a%i == 0)
			return 0;
	}
	return 1;
	
}


int main(){
	int Q,q;
	int i;
	int count;
	int ans;
	while(scanf("%d",&Q)==1){
		if(Q<=3){
			printf("Sea5 0\n");
			continue;
		}
		count = 0;
		ans = 1;
		q=Q;
		int max = sqrt(Q);
		
		for(i=2; i<=max; i++)
			if(q%i == 0){
				q /= i;
				if(check(i) == 1){
					
					ans *= i;
					count++;
					if(count == 2)
						break;
					
				}
				i--;
			}
//		printf("ans = %d,count = %d\n",ans,count);
		if(count>=2 && ans<Q)
			printf("Sea5 %d\n",ans);
		else
			printf("C_on\n");
		
		
		
	}
	
	return 0;
	
}
