#include"cstdio"
#include"cstring"
#include"iostream"

using namespace std;


char s1[1020],s2[1020];
int dp[1020][1020];


int main(){
	while(scanf("%s%s",s1,s2) == 2){
		memset(dp, 0, sizeof(dp));
		
		for(int i = 0; i < strlen(s1); i++)
			for(int j = 0; j < strlen(s2); j++)
				if(s1[i] == s2[j])
					dp[i+1][j+1] = dp[i][j] + 1;
				else
					dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		
		printf("%d\n",dp[strlen(s1)][strlen(s2)]);
	}
	
	
	return 0;
}
