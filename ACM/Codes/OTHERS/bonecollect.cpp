#include"cstdio"
#include"iostream"
#include"cstring"

using namespace std;

int N,V;
int c[1020];
int v[1020];
int dp[1020];



int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp, 0, sizeof(dp));
		
		scanf("%d%d",&N,&V);
		
		for(int i = 1; i <= N; i++)
			scanf("%d",&v[i]);
		for(int i = 1; i <= N; i++)
			scanf("%d",&c[i]);
		
		
		for(int i = 1; i <= N; i++)
			for(int j = V; j >= c[i]; j--)
				dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
		
		printf("%d\n",dp[V]);
	}
	
	
	return 0;
}
