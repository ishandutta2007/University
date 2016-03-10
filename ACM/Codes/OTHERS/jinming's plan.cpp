#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int dp[32000];
int f[60][32000];
int N,m;
int level[60];
int v[60];
int follow[60];
int tmp[60];
int tmp_len;
int M;
int sub[60];
int son[60][2];


/*
void process1(int a){
	M++;
	sub[M] = a;
	for(int i = 1; i < tmp_len; i++)
		for(int j = N; j >= v[tmp[i]] + v[a]; j--)
			f[M][j] = max(f[M][j], f[M][j-v[tmp[i]]] + v[tmp[i]]*level[tmp[i]]);
	int m = level[a]*v[a];
	for(int i = v[a]; i <= N; i++)
		f[M][i] += m;
}
*/


/*

void process2(){
	for(int i = 1; i <= M; i++)
		for(int j = N; j >= v[sub[i]]; j--){
			for(int k = v[sub[i]]; k <= j; k++)
				dp[j] = max(dp[j], dp[j - k] + f[i][k]);
		}
	
}
*/


int main(){
	scanf("%d%d",&N,&m);
	
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d",&v[i],&level[i],&follow[i]);
		if(follow[i] != 0){
			if(son[follow[i]][0] == 0)
				son[follow[i]][0] = i;
			else
				son[follow[i]][1] = i;
		}
	}
	
//	for(int i = 1;i <= m; i++)
//		printf("%d %d\n",son[i][0],son[i][1]);
//	
/*
	for(int i = 1; i <= m; i++)
		if(follow[i] == 0){
			tmp_len = 1;
			tmp[0] = i;
			for(int j = 1; j <= m; j++)
				if(follow[j] == i)
					tmp[tmp_len++] = j;
			process1(i);
		}
	process2();

*/

	for(int i = 1; i <= m; i++)
		if(follow[i] == 0){
			for(int j = N; j >= 0; j--)
			{
//				printf("|%d|\n",i);
				if(j >= v[i])
					dp[j] = max(dp[j], dp[j - v[i]] + v[i]*level[i]);
				if(j >= v[i] + v[son[i][0]])
					dp[j] = max(dp[j], dp[j - v[i] - v[son[i][0]]] + v[i]*level[i] + v[son[i][0]]*level[son[i][0]]);
				if(j >= v[i] + v[son[i][1]])
					dp[j] = max(dp[j], dp[j - v[i] - v[son[i][1]]] + v[i]*level[i] + v[son[i][1]]*level[son[i][1]]);
				if(j >= v[i] + v[son[i][0]] + v[son[i][1]])
					dp[j] = max(dp[j], dp[j - v[i] - v[son[i][0]] - v[son[i][1]]] + v[i]*level[i] + v[son[i][0]]*level[son[i][0]] + v[son[i][1]]*level[son[i][1]]);
				
			}
			
			
		}

	printf("%d\n",dp[N]);
	
	return 0;
}

