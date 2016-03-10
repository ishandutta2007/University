#include"cstdio"
#include"iostream"
#include"cstring"

using namespace std;


int c[3] = {150,200,350};
int M;
int dp[10020];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		scanf("%d",&M);
		
		for(int i = 0; i < 3; i++)
			for(int j = c[i]; j <= M; j++)
					dp[j] = max(dp[j], dp[j - c[i]] + c[i]);
		
		printf("%d\n",M-dp[M]);
		
		
	}
	
	
	return 0;
}
