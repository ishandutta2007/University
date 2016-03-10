#include"cstdio"
#include"cstring"

using namespace std;

int Dmq[1000020];
int Imq[1000020];
int a[1000020];

int maxans[1000020];
int minans[1000020];

int n,k;

int Df,If;
int Dt,It;


void Denque(int sub){
	while(Df < Dt && a[sub] > a[Dmq[Dt - 1]]) 
		Dt --;
	Dmq[Dt++] = sub;
	
}

void Ienque(int sub){
	while(If < It && a[sub] < a[Imq[It - 1]]) 
		It --;
	Imq[It++] = sub;
	
}



void SlidingWD(){
	
	
	for(int i = 1; i < k; i++){
		Denque(i);
		Ienque(i);
	}
	
	for(int i = k; i <= n; i++){
		while(Dmq[Df] <= i - k){
			//DmqPop();
			Df++;
		}
		while(Imq[If] <= i - k){
			//ImqPop();
			If++;
		}
		Denque(i);
		Ienque(i);
		
		maxans[i] = Dmq[Df];
		minans[i] = Imq[If];
		
//		printf("max:%d\nmin:%d\n",maxans[i],minans[i]);
	}
	
	
	
}



int main(){
	scanf("%d%d",&n,&k);
	
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	
	
	SlidingWD();
	
	for(int i = k; i < n; i++)
		printf("%d ",a[minans[i]]);
	printf("%d\n",a[minans[n]]);
	for(int i = k; i < n; i++)
		printf("%d ",a[maxans[i]]);
	printf("%d\n",a[maxans[n]]);
	return 0;
	
}
