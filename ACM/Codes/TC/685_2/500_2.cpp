#include <bits/stdc++.h>

using namespace std;
typedef pair<int, pair<int, int> > PIII;


class DoubleWeights
{
public:

	int vis[30][200];
	int dist[30][200];
	set< pair<int, pair<int, int> > > st;
	PIII mk(int a, int b, int c) {
		return make_pair(a, make_pair(b, c));
	}

	int minimalCost(vector <string> weight1, vector <string> weight2)
	{
		int n = weight1.size();
		st.clear();
		memset(vis, 0, sizeof(vis));

		st.insert( mk(0,0,0) );
		vis[0][0] = 1;
		dist[0][0] = 0;
		while(!st.empty())
		{
			PIII tmp = *st.begin();
			st.erase(st.begin());
			int u = tmp.second.first;
			int w = tmp.second.second;
			for (int i = 0; i < n; i++)
			{
				if(weight1[u][i] != '.')
				{
					if(w + weight2[u][i] - '0' >= 200) continue;
					if(vis[i][w + weight2[u][i] - '0'] == 0)
					{
						st.insert(mk(tmp.first + weight1[u][i] - '0', i, w + weight2[u][i] - '0'));
						vis[i][w + weight2[u][i] - '0'] = 1;
						dist[i][w + weight2[u][i] - '0'] = tmp.first + weight1[u][i] - '0';
					}
				}
			}
		}

		int ans = 0x7fffffff;
		for (int i = 1; i <= 200; i++)
			if(dist[1][i] > 0)
				ans = min(ans, dist[1][i] * i);
		if(ans == 0x7fffffff) return -1;
		return ans;
	}
};
