#include"cstdio"
#include"iostream"
#include"cstring"
#include"limits"


using namespace std;


int main(){
	
	
	int a[10020];
	int dp[10020];
	int n;
	while(1){
		scanf("%d",&n);
		if(n == 0)
			break;
		memset(dp, 0, sizeof(dp));
		for(int i = 1;i <= n; i++)
			scanf("%d",&a[i]);
		
		
		dp[1] = a[1];
		int tmp = a[1];
		for(int i = 2; i <= n; i++)
		{
			dp[i] = max(dp[i - 1] + a[i], a[i]);
			tmp = max(tmp,dp[i]);
		}
		if(tmp > 0)printf("The maximum winning streak is %d.\n",tmp);
		else printf("Losing streak.\n");
	}
	
	
	
	
	return 0;
}
