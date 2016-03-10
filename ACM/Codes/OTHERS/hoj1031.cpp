#include"cstdio"
#include"iostream"
#include"cstring"


using namespace std;

int t;
int m1,m2;
int w[501],v[501];
int n;
int ans[10020];

void search(int m){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&v[i],&w[i]);
	
	
	memset(ans,0x3f,sizeof(ans));
	ans[0]=0;
	for(i=1;i<=n;i++)
		for(j=w[i];j<=m;j++){
			ans[j]=min(ans[j],ans[j-w[i]]+v[i]);
		}
	if(ans[m]==0x3f3f3f3f)
		printf("This is impossible.\n");
	else
		printf("The minimum amount of money in the piggy-bank is %d.\n",ans[m]);
}




int main(){
	int i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d",&m1,&m2);
		search(m2-m1);
	}
	
	
	return 0;
}
