#include"cstdio"
#include"iostream"
#include"cstring"


using namespace std;

int cnt_brk;
int dp[201][20020];
int v[230],c[230];

void init(){
	memset(dp, 0x3f, sizeof(dp));
	
	dp[0][0] = 0;
	
	for(int i = 1; i <= cnt_brk; i++){
		for(int j = 20; j >= 1; j--){
			for(int k = j*1000; k >= v[i]; k--)
				dp[j][k] = min(dp[j][k], dp[j-1][k - v[i]] + c[i]);
		}
		
		
	}
	
	
}






/*
void init(){
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for(int k = 1;k <= 20;k++)
	{
		for(int i = 1; i <= cnt_brk; i++)
			for(int j = k*1000; j >= v[i]; j--){
//				int flag = 0;
//				if(dp[k - 1][j-v[i]] + c[i] < dp[k][j]){
//					printf("from d[%d][%d] : %d\n",k - 1,j - v[i],dp[k-1][j-v[i]]);
//					flag = 1;
//				}
					
				dp[k][j] = min(dp[k-1][i-1][j-v[i]] + c[i], dp[k][i][j]); 
//				if(flag)printf("to   d[%d][%d] : %d\n",k,j,dp[k][j]);
			}
	}
}
*/
int main(){
	int first = 1;
	while(scanf("%d",&cnt_brk) != EOF){
		if(first) first = 0;
		else printf("\n");
		for(int i = 1; i <= cnt_brk; i++)
			scanf("%d%d",&v[i],&c[i]);
		
		
		init();
		
		int t;
		int m,mmax,mmin;
		scanf("%d",&t);
		while(t--){
			scanf("%d%d%d",&m,&mmin,&mmax);
//			printf("|%d|\n",dp[1][550]);

//			for(int i = mmin*m;i <= mmax*m; i++)
			int tmp = 0x3f3f3f3f;
			for(int i = mmin*m; i <= mmax*m; i++)
				tmp = min(tmp, dp[m][i]);
			
			if(tmp == 0x3f3f3f3f)
				printf("impossible\n");
			else
				printf("%d\n",tmp);		
		}	
		
	}
	return 0;
}
