#include <bits/stdc++.h>

using namespace std;

int dp[1<<13][5][5][5];


class RGBTree
{
public:

	bool dfs(int mask, int r, int g, int b)
	{
		bool res = false;
		if(dp[mask][r][g][b] == -1)
		{
			int n = G.size(), k = (n-1)/3;
			if(r == k && g == k && b == k)	res = true;

			for (int i = 0; i < n; i++) if (mask & (1<<i))
			{
				for (int j = 0; j < n; j++) if(!(mask & (1<<j)) && (G[i][j] != '.'))
				{
					int tr = r, tg = g, tb = b;
					if(G[i][j] == 'R') tr++;
					else if(G[i][j] == 'G') tg++;
					else tb++;
					if(tr <= k && tg <= k && tb <= k)
						res = res || dfs(mask|(1<<j), tr,tg,tb);
				}

			}
			dp[mask][r][g][b] = res? 1:0;
		}
		else
			res = dp[mask][r][g][b] == 1? true:false;

		return res;
	}



	vector <string> G;
	string exist(vector <string> G)
	{
		this->G = G;
		memset(dp, -1, sizeof(dp));
		return dfs(1, 0, 0, 0)? "Exist" : "Does not exist";
	}
};