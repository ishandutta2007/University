#include"cstdio"
#include"iostream"
#include"cstring"

using namespace std;


int dp[40020];
int a[40020];



int main(){
	int t;
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&a[i]);
			dp[i] =  1;
		}
		for(int i = 2; i <= n; i++){
			for(int j = 1; j < i; j++)
			if(a[i] > a[j] && dp[j] + 1 > dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
		
		int max = 0;
		for(int i = 1;i<=n;i++)
			if(dp[i] > max)
				max = dp[i];
		printf("%d\n",max);
	}
	
	
	
	
	return 0;
}
