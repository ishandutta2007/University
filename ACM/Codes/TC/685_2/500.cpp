#include <bits/stdc++.h>

using namespace std;


class DoubleWeights
{
public:
	int n;
	int ans;
	int vis[40];
	vector<string> c1, c2;

	void dfs(int u, int now1, int now2)
	{
		if(u == 1)
		{
			if(now1 * now2 < ans)
				ans = now1 * now2;
			return;
		}

		if(now1 * now2 > ans)
			return;
		for (int i = 0; i < n; i++)if(c1[u][i] != '.' && vis[i] == 0)
		{
			vis[i] = 1;
			dfs(i, now1 + c1[u][i]-'0', now2 + c2[u][i]-'0');
			vis[i] = 0;
		}
	}



	int minimalCost(vector <string> weight1, vector <string> weight2)
	{
		n = weight1.size();
		memset(vis, 0,sizeof(vis));
		c1 = weight1, c2 = weight2;
		ans = 0x7fffffff;
		vis[0] = 1;
		dfs(0, 0, 0);
		return ans == 0x7fffffff? -1 : ans;
	}

};