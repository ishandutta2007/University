#pragma comment(linker, "/STACK:202400000,202400000")
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>


using namespace std;


vector<int>Edge[200020];
int n;
int depth[200020];
int pre[200020];
int branch[200020];
int vis[200020];
int got;
int maxdep;
vector<int>path;

queue<int> qu;



// void dfs(int now , int t)
// {
// 	depth[now] = t;
// 	vis[now] = 1;
// 	for(int i = 0, len = Edge[now].size(); i < len ; i++)
// 	{
// 		int to = Edge[now][i];
// 		if(!vis[to])
// 		{
// 			// vis[to] = 1;
// 			dfs(to, t + 1);
// 		}
// 	}
// }


void bfs(int st)
{
	while(!qu.empty())
	{
		// qt.pop();
		qu.pop();
	}

	memset(depth, 0, sizeof(depth));

	qu.push(st);
	depth[st] = 1;
	int nowv;

	while(!qu.empty())
	{
		nowv = qu.front();
		// nowt = qt.front();
		qu.pop();
		// qt.pop();

		for(int i = 0, l = Edge[nowv].size(); i < l; i++)
		{
			int to = Edge[nowv][i];
			if(depth[to] == 0)
			{
				depth[to] = depth[nowv]+1;
				qu.push(to);
			}
		}
	}
}


void bfs2(int now, int dest)
{
	memset(pre, -1, sizeof(pre));
	while(!qu.empty())
	{
		qu.pop();
	}

	qu.push(now);
	pre[now] = 0;

	while(!qu.empty())
	{
		now = qu.front();
		qu.pop();
		if(now == dest)
		{
			return;
		}

		for(int i = 0, len = Edge[now].size(); i < len; i++)
		{
			int to = Edge[now][i];
			if(pre[to] != -1)
				continue;

			pre[to] = now;
			qu.push(to);
		}
	}
}


void dfs3(int now, int t)
{

	vis[now] = 1;
	if(t > maxdep)
	{
		maxdep = t;
	}

	for(int i = 0, len = Edge[now].size(); i < len ;i++)
	{
		int to = Edge[now][i];
		if(vis[to]) continue;
		dfs3(to, t+1);
	}
}


int getbranch(int id)
{
	maxdep = 0;
	dfs3(id, 0);
	return maxdep;
}


int main()
{

	// freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);


	while(T--)
	{
		scanf("%d", &n);
		int u, v;


		for(int i = 1; i <= n; i++)
			Edge[i].clear();
		for(int i = 1; i < n; i++)
		{
			scanf("%d%d", &u, &v);

			Edge[u].push_back(v);
			Edge[v].push_back(u);
		}

		// memset(depth, 0, sizeof(depth));
		// memset(vis, 0, sizeof(vis));
		// vis[1] = true;
		// dfs(1, 1);
		bfs(1);


		// continue;
		// cout << 1 << endl;

		int startdep = 0;
		int startid = 0;

		for(int i = 1; i <= n; i++)if(startdep < depth[i])
		{
			startdep = depth[i];
			startid = i;
		}

		memset(depth, 0, sizeof(depth));

		memset(vis, 0, sizeof(vis));
		bfs(startid);
		int enddep = 0, endid = 0;

		for(int i = 1; i <= n; i++)if(enddep < depth[i])
		{
			enddep = depth[i];
			endid = i;
		}

		bfs2(startid, endid);
		// cout << "here" <<endl;
		path.clear();
		memset(vis, 0, sizeof(vis));


		while(pre[endid] != -1)
		{
			vis[endid] = 1;
			path.push_back(endid);
			endid = pre[endid];
		}

		int len = path.size();

		memset(branch, 0, sizeof(branch));

		for(int i = 1; i < len - 1; i++)
		{
			int id = path[i];
			if(Edge[id].size() > 2)
			{
				branch[i] = getbranch(id);
			}
		}



		// for(int i = 0, n = path.size(); i < n; i++)
		// {
		// 	printf("branch:%d %d\n", path[i], branch[i]);
		// }
	
		int cut = len/2;


		int ans1, ans2, maxlen;

		maxlen = 0;


		for(int i = 0; i < cut; i++)if(maxlen < i+1+branch[i])
		{
			maxlen = i+1+branch[i];
		}

		int ans = maxlen / 2;
		ans1 = path[ans];

		maxlen = 0;
		for(int i = cut; i < len ; i++)if(maxlen < len - i + branch[i])
		{
			maxlen = len-i+branch[i];
		}

		ans2 = path[len - maxlen / 2 - 1];

		ans = max(ans, maxlen / 2);

		printf("%d %d %d\n", ans, ans1, ans2);

		// int maxlen = 0;
		// for(int i = cut; i < len; i++)
		// {
		// 	int tmp = len  - i + branch[i];
		// 	if(tmp > maxlen)
		// 	{
		// 	 	maxlen = tmp;
		// 	}
		// }



		// printf("!!!%d %d\n", maxlen, maxpos);

	// 	int ans1 = 0, ans2 = 0, minlen = 20000000;


	// 	for(int i = cut-1; i >= 0; i--)
	// 	{
	// 		int tmp = max(i, maxlen/2);
	// 		if(tmp < minlen)
	// 		{
	// 			ans1 = path[i], ans2 = path[len - maxlen/2 - 1];
	// 			minlen = tmp;
	// 		}


	// 		tmp = len - i + branch[i];
	// 		if(tmp > maxlen)
	// 		{
	// 			maxlen = tmp;
	// 		}

	// 	}

	// 	printf("%d %d %d\n", minlen, ans1, ans2);

	}

	return 0;
}
