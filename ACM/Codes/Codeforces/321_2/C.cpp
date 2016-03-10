#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int>G[100020];
int n, d;
int cat[100020];
bool vis[100020];


typedef struct Node
{
	int id, len;
	Node(){}
	Node(int id, int len):id(id),len(len){}
}nd;


deque<nd>deq;
int bfs()
{
	int ans = 0;
	nd now, nex;
	deq.push_back(nd(1,cat[1]));
	while(!deq.empty())
	{
		now = deq.front();
		deq.pop_front();
		vis[now.id] = true;

		if(G[now.id].size() == 1 && now.len <= d && now.id != 1)
		{
			ans++;
			continue;
		}

		for(int i = 0, len = G[now.id].size(); i < len ;i++)
		{
			int to = G[now.id][i];
			if(vis[to]) continue;

			nex = nd(to, cat[to]? now.len+1:0);
			if(nex.len > d)
				continue;
			deq.push_back(nex);
		}

	}

	return ans;
}


int main()
{


	scanf("%d%d", &n, &d);

	for(int i = 1; i <= n; i++)
		scanf("%d", &cat[i]);
	int u, v;
	for(int i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	printf("%d\n", bfs());

	return 0;
}
