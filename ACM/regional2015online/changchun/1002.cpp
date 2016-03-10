#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;


typedef long long LL;



LL sum, tmp;
int num;

struct Edge{
	int v;
	Edge(){}
	Edge(int v):v(v){}
}edges[200020];

int tot;

int de[100020];
int v[100020];

bool vis[10020];

int p, m;
deque<int>deq;
vector<int>G[10020];

void addedge(int u, int v)
{
	G[u].push_back(tot);
	edges[tot++] = Edge(v);
}


int main()
{
	int T;
	scanf("%d", &T);


	while(T--)
	{
		sum = 0LL;
		tot = 0;
		memset(de, 0, sizeof(de));
		memset(v, 0, sizeof(v));
		memset(vis, 0, sizeof(vis));
		deq.clear();
		scanf("%d%d", &p, &m);
		for(int i = 0; i <= p; i++) G[i].clear();


		for(int i = 1; i <= p; i++)
		{
			scanf("%d", &v[i]);
			// sum += v[i];
		}


		int x, y;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			de[x] ++;
			de[y] ++;
			addedge(x, y);
			addedge(y, x);
		}


		for(int i = 1; i <= p; i++)
		{
			if(de[i] <= 1)
			{
				deq.push_back(i);
				vis[i] = true;
			}
		}


		int nowi;
		while(!deq.empty())
		{
			nowi = deq.front();
			deq.pop_front();
			vis[nowi] = true;
			sum -= v[nowi];


			for(int i = 0, len = G[nowi].size(); i < len; i++)
			{
				int to = edges[G[nowi][i]].v;
				de[to] --;
				if(!vis[to] && de[to] <= 1)
				{
					deq.push_back(to);
					vis[to] = true;
				}

			}


		}

		tmp = sum = 0LL;
		num = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= p; i++)
		{
			if(!vis[i] && de[i] > 1)
			{
				num = 0, tmp = 0LL;
				vis[i] = true;
				deq.push_back(i);
				while(!deq.empty())
				{
					int now = deq.front();
					deq.pop_front();
					tmp += v[now];
					num ++;
					for(int j = 0, len = G[now].size(); j < len ; j++)
					{
						int to = edges[G[now][j]].v;
						if(vis[to]) continue;
						if(de[to] > 1)
						{
							deq.push_back(to);
							vis[to] = true;
						}
					}
				}
				// cout << num << "  " << tmp << endl;
				if(num % 2 && num > 1)
				{
					sum += tmp;
				}
			}
		}



		printf("%I64d\n", sum);
	}
	return 0;
}