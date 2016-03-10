#include"cstdio"
#include"iostream"
#include"cstring"

using namespace std;



int p[520],w[520];
int dp[10020];



int main(){
	int t;
	int E,F,W;
	int n;
	scanf("%d",&t);
	while(t--){
		//input
		scanf("%d%d",&E,&F);
		W = F - E;
		memset(p,0,sizeof(p));
		memset(w,0,sizeof(w));
		scanf("%d",&n);
		
		for(int i = 1; i <= n; i++)
			scanf("%d%d",&p[i],&w[i]);
		
		memset(dp,0x3f,sizeof(dp));
		dp[0] = 0;
		for(int i = 1;i <= n; i++)
			for(int j = w[i]; j <= W; j++)
				dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
		
		
		if(dp[W] == 0x3f3f3f3f)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[W]);
	}
	
	
	
	return 0;
}
