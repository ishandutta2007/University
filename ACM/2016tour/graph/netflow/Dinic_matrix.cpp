//poj1273

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 300;
const int INF = 0x7fffffff;

int G[maxn][maxn];
int layer[maxn];
int vis[maxn];
int n, m;	//n 为定点总数， m为边数
int st, ed; //st 是源点， ed是汇点

bool calc_layer()
{
	deque<int> deq;
	memset(layer, -1, sizeof(layer));
	layer[st] = 0;
	deq.push_back(st);
	while(!deq.empty())
	{
		int v = deq.front();
		deq.pop_front();
		for (int i = 1; i <= n; i++) if(layer[i] == -1 && G[v][i] > 0)
		{
			layer[i] = layer[v] + 1;
			if(i == ed) return true;
			else deq.push_back(i);
		}
	}
	return false;
}

int Dinic()
{
	int i;
	int maxFlow = 0;
	deque<int> deq;	//DFS 用的栈
	while(calc_layer())
	{
		deq.push_back(st);
		memset(vis, 0, sizeof(vis));
		while(!deq.empty())
		{
			int nd = deq.back();
			if(nd == ed)	//nd 是汇点
			// if(nd == ed)
			{
				int minc = INF;
				int minc_u;
				int len = deq.size();
				for (i = 1; i < len; i++)
				{
					int u = deq[i-1], v = deq[i];
					if(G[u][v] > 0 && G[u][v] < minc)
					{
						minc = G[u][v];
						minc_u = u;
					}
				}
				//增广， 改图
				maxFlow += minc;
				for (i = 1; i < len; i++)
				{
					int u = deq[i-1], v = deq[i];
					G[u][v] -= minc;	//修改边容量
					G[v][u] += minc;	//添加反向边
				}
				//退栈到 minc_u 成为栈顶，以便继续dfs
				while(!deq.empty() && deq.back() != minc_u)
				{
					vis[deq.back()] = 0;
					deq.pop_back();
				}
			} else {	//nd 不是汇点
				for (i = 1; i <= n; i++)
				{
					if(G[nd][i] > 0 && layer[i] == layer[nd] + 1 && !vis[i])
					{
						vis[i] = 1;
						deq.push_back(i);
						break;
					}
				}
				if(i > n)
					deq.pop_back();
			}
		}
	}
	return maxFlow;
}

int main()
{
	while(cin >> m >> n)
	{
		int s, e, c;
		memset(G, 0, sizeof(G));
		for (int i = 0; i < m; i++)
		{
			cin >> s >> e >> c;
			G[s][e] += c;
		}
		st = 1;
		ed = n;
		cout << Dinic() << endl;
	}
	return 0;
}