#include <bits/stdc++.h>

using namespace std;

class RGBTree
{
public:
	int n, k;
	bool flag;
	int stk[20], vis[20];
	vector <string> G;
	void dfs(int found, int r, int g, int b)
	{
		if(found == n)
		{
			if(r >= k && g >= k && b >= k) flag = true;
			return;
		}
		
		int tr, tg, tb;
		for (int i = 0; i < n; i++) if(!vis[i])
		{
			if(flag) return;
			if(found == 0)
			{
				vis[i] = true;
				stk[found] = i;
				dfs(found + 1, r, g, b);
				vis[i] = false;
			}
			else
			{
				tr = tg = tb = 0;
				for (int j = 0; j < found; j++)
				{
					if(G[i][stk[j]] == 'R')
						tr++;
					else if(G[i][stk[j]] == 'G')
						tg++;
					else if(G[i][stk[j]] == 'B')
						tb++;
				}
				if(tr || tg || tb)
				{
					vis[i] = true;
					stk[found] = i;
					dfs(found + 1, r+tr, g+tg, b+tb);
					vis[i] = false;
				}
			}
		}
	}

	string exist(vector <string> g)
	{
		G = g;
		n = G.size();
		k = (n-1)/3;
		flag = false;
		dfs(0,0,0,0);
		return flag? "Exist" : "Does not exist";
	}
};