#include"algorithm"
#include"iostream"
using namespace std;

int a[500020];
int b[500020];
int N;


int find(int n){
	int i;
	for(i=2;i<=n;i++)
	{
		a[i]=a[i]*a[i-1]+1;
		b[i]=b[i]*b[i-1]+1;
		sort(a+i,a+N+1);
		sort(b+i,b+N+1,greater<int>());
	}
	return abs(a[n]-b[n]);
	
}



int main(){

	int i;
	
	scanf("%d",&N);
	while(N!=0){
		for(i=1;i<=N;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		
		sort(a+1,a+N+1);
		sort(b+1,b+N+1,greater<int>());
//		for(i=1;i<=N;i++)
//			printf("a:%d b:%d\n",a[i],b[i]);
		printf("%d\n",find(N));
		scanf("%d",&N);
	}
	return 0;
}
