#include"iostream"
#include"cstdio"

using namespace std;


int w[1000],v[1000];
int ans[1000];
int n,m;


int main(){
	int i,j,k;
	int n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d%d",&w[i],&v[i]);
//		
//	for(i=1;i<=n;i++){
//		for(j=m;j>=w[i];j--){
//			for(k=1;k<=j/w[i];k++)
//				ans[j]=max(ans[j],ans[j-w[i]*k]+k*v[i]);
//		}
//		
//		
//	}


	for(i=1;i<=n;i++)
		for(j=w[i];j<=m;j++)
			ans[j]=max(ans[j],ans[j-w[i]]+v[i]);
	
	printf("%d\n",ans[m]);
	return 0;
	
}
