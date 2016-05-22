#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000;



class Graph_basic{
private:
	vector <int> G[maxn];     	//邻接表储存边
	int n, m;
	int dist[maxn];				//dist[i]储存到达 i 的最短距离
	void addedge(int u, int v)
	{
		G[u].push_back(v);
	}

public:
	void cleardist()
	{
		memset(dist, -1, sizeof(dist));
	}
	void clear()
	{
		for(int i = 0; i < maxn; i++) G[i].clear();
		n = m = 0;
	}


	void input()
	//输入一个图，这里的边长度都为1
	{
		printf("please input the number of the vertexs and the edges\n");
		scanf("%d%d", &n,&m);
		int x, y;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);
			addedge(x, y);
			addedge(y, x);
		}
	}

	void dfs(int s)
	{
		dist[s] = 1;
		cout << s << endl;
		for(int i = 0, len = G[s].size(); i < len; i++)if(dist[G[s][i]] == -1)
		{
			dist[G[s][i]] = 1;
			dfs(G[s][i]);
		}
	}

	void dfs_none_reverse(int s)
	{
		memset(dist, -1, sizeof(dist));
		deque<int > deq; 				//栈来储存节点
		deq.clear();
		deq.push_front(s);
		int now, to;
		while(!deq.empty())
		{
			now = deq.front();
			deq.pop_front();
			if(dist[now] == 1) continue;
			cout << now << endl;
			dist[now] = 1;
			for(int i = 0, len = G[now].size(); i < len; i++)if(dist[G[now][i]] == -1)
			{
				deq.push_front(G[now][i]);
			}
		}
	}

	void bfs(int s)
	{
		//memset(dist,-1,sizeof(dist));
		deque<int> deq;
		deq.clear();
		dist[s] = 0;
		deq.push_back(s);
		int now;
		while(!deq.empty())
		{
			now = deq.front();
			deq.pop_front();
			cout << now << endl;
			for(int i = 0, len = G[now].size(); i < len; i++)if(dist[G[now][i]] == -1)
			{
				dist[G[now][i]] = dist[now]+1;
				deq.push_back(G[now][i]);
			}
		}
	}
	void showdist()
	{
		for(int i = 1; i <= n; i++)
			printf("%d%c", dist[i], i == n ? '\n' : ' ');
	}
}g;




int main()
{
	g.clear();
	g.input();
	g.cleardist();
	g.dfs_none_reverse(1);
	// g.dfs(1);
	// g.bfs(1);

	return 0;
}
