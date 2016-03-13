#include <bits/stdc+++.h>

using namespace std;


int N;
int cost[100], score[100];
int vis[100];
int tmp;

int dfs(int t, int now)
{
	if(t > 3) return;
	


}




int caltmp()
{
	tmp = 0;
	ret = dfs(0, 0);
	return tmp;
}




int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		double tmpf;
		for (int i = 0; i < N; i++)
		{
			scanf("%f%d", &tmpf, &score[i]);
			cost[i] = tmpf * 10;
		}
		msort();
		ans = 0;
		int tmp;
		while(tmp = caltmp())
		{
			ans += tmp;
		}
		printf("%d\n", ans);
	}






	return 0;
}