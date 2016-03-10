#include"cstdio"
#include"iostream"
#include"cstring"

using namespace std;


int dp[1020];
int a[1020];



int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n == 0) break;
		
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&a[i]);
			dp[i] =  a[i];
		}
		for(int i = 1; i <= n; i++){

			for(int j = i+1; j <= n; j++)
			if(a[j] > a[i])
				dp[j] = max(dp[j],dp[i] + a[j]);
			
		}
		
		int tmp = 0;
		for(int i = 1; i <= n; i++)
			tmp = max(tmp, dp[i]);
		printf("%d\n",tmp);
	}
	
	
	
	
	return 0;
}
