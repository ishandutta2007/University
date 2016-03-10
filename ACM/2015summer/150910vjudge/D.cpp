#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
	int v;
	Edge(){}
	Edge(int v):v(v){}
}edges[100020];

vector<int>G[100020];
vector<int>le[1020];
deque<int>dq,dq2;

int tot;
int n, k;
int rt;
int w[100020];
int cnt_le;

void addedge(int u, int v)
{
	edges[tot].v = v;
	G[u].push_back(tot++);
}

void callevel()
{
	cnt_le = 0;
	dq.clear();
	dq2.clear();
	le[cnt_le].push_back(w[rt]);
	if(G[rt].size() > 0)
	{
		dq.push_back(rt);
		dq2.push_back(0);
	}
	while(!dq.empty())
	{
		int nowrt = dq.front();
		int nowk = dq2.front() + 1;
		if(nowk > cnt_le) cnt_le = nowk;
		dq.pop_front();
		dq2.pop_front();
		for(int i = 0, len = G[nowrt].size(); i < len; i++)
		{
			int v = edges[G[nowrt][i]].v;
			le[nowk].push_back(w[v]);
			if(G[v].size() > 0)
			{
				dq.push_back(v);
				dq2.push_back(nowk);
			}
		}
	}

}


int main()
{
	while(scanf("%d%d", &n, &k) != EOF)
	{
		if(n+k==0) break;

		for(int i = 0; i <= n; i++) G[i].clear();
		for(int i = 0; i <= 1000; i++) le[i].clear();
		memset(edges, 0, sizeof(edges));
		int u;
		for(int i = 1; i <= n;i++)
		{
			scanf("%d%d",&u,&w[i]);

			if(n == 0) rt = i;
			else
			{
				addedge(u, i);
			}
		}

		callevel();
		int ans = 0;
		for(int i = 0; i <= cnt_le; i++)if(le[i].size() >= k)
		{
			sort(le[i].begin(), le[i].end() ,greater<int>());
			int tmp = 0;
			for(int j = 0; j < k; j++)
				tmp += le[i][j];

			ans = max(ans, tmp);
		}

		printf("%d\n", ans);
	}
	return 0;
}