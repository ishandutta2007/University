#include <bits/stdc++.h>
using namespace std;

class SegmentsAndPoints
{
public:
	struct Edge
	{
		int from, to;
		Edge(int f, int t):from(f),to(t){}
		Edge(){}
	};

	vector<Edge> G[300];
	int matching[300], check[300];
	int n, m, sum;

	bool dfs(int u)
	{
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].to;
			if(!check[v]) {
				check[v] = true;
				if(matching[v] == -1 || dfs(matching[v])) {
					matching[v] = u;
					matching[u] = v;
					return true;
				}
			}
		}
		return false;
	}

	int hungarian()
	{
		int ans = 0;
		memset(matching, -1, sizeof(matching));
		for (int u = 1; u <= n; u++) if(matching[u] == -1)
		{
			memset(check, 0, sizeof(check));
			if(dfs(u))
				ans ++;
		}
		return ans;
	}

	void addedge(int u, int v)
	{
		G[u].push_back(Edge(u,v));
		G[v].push_back(Edge(v,u));
	}

	string isPossible(vector <int> p, vector <int> l, vector <int> r)
	{
		int len = p.size();
		n = len * 2;

		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
			{
				if(p[i] >= l[j] && p[i] <= r[j])
					addedge(i+1, j + len + 1);
			}
		return hungarian() == len? "Possible" : "Impossible";
	}		
};
