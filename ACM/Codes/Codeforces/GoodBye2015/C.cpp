#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int dp[600][600];
int verr[600][600] , horr[600][600];

char mp[600][600];
int n , m;


int ver(int i, int j)
{
	if(mp[i][j] == '.' && mp[i-1][j] == '.') return 1;
	return 0;
}

int hor(int i, int j)
{
	if(mp[i][j] == '.' && mp[i][j-1] == '.') return 1;
	return 0;
}


void pre()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1]-dp[i-1][j-1];
			
			dp[i][j] += ver(i, j);
			dp[i][j] += hor(i, j);
			verr[i][j] = verr[i][j-1] + ver(i, j);
			horr[i][j] = horr[i-1][j] + hor(i, j);
		}
	}
}



int main()
{
	scanf("%d%d", &n, &m);
	getchar();
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			scanf("%c", &mp[i][j]);
		getchar();
	}
	
	pre();
	
	// for(int i = 1; i <= n; i++)
		// for(int j = 1; j <= m; j++)
		// {
			// printf("%d%c", dp[i][j], j == m? '\n' : ' ');
		// }
		
		
	int t;
	scanf("%d", &t);
	
	int x11,x22,y11,y22;
	
	while(t--)
	{
		scanf("%d%d%d%d", &x11, &y11, &x22, &y22);
		
		printf("%d\n", dp[x22][y22] - dp[x11-1][y22] - dp[x22][y11-1] + dp[x11-1][y11-1] - verr[x11][y22] + verr[x11][y11-1] - horr[x22][y11] + horr[x11-1][y11]);
	}
	
	
	
	return 0;
}
/*
0 1 2 3 3
1 2 4 7 8
1 2 5 8 10
1 2 6 10 12


*/