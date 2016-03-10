#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


class PowerOutage
{
public:

	typedef struct Edge
	{
		int de, c; 
		Edge(){}
		Edge(int de, int c):de(de),c(c){}
	}Edge;

	vector<Edge>G[60];

	int lenth[60]; 

	int bfs()
	{
		int ret = 0;
		memset(lenth, -1, sizeof(lenth));
		deque<int> deq;
		deq.clear();
		lenth[0] = 0;
		deq.push_back(0);
		int now;
		while(!deq.empty())
		{
			now = deq.front();
			deq.pop_front();

			for(int i = 0, len = G[now].size(); i < len ; i++)
			{
				int des = G[now][i].de, c = G[now][i].c;
				lenth[des] = lenth[now] + c;
				ret = max(ret, lenth[des]);
			}
		}

		return ret;

	}



	int estimateTimeOut(vector<int> from, vector<int> to, vector<int> cost)
	{
		int ret = 0;
		int n = from.size();
		for(int i = 0; i <= n; i++)
			G[i].clear();

		for(int i = 0; i < n; i++)
		{
			G[from[i]].push_back(Edge(to[i], cost[i]));
			ret += 2*cost[i];
		}


		return ret - bfs();
	}

};




int main()
{
	PowerOutage pq;
	vector<int> from,to,cost;
	cout << pq.estimateTimeOut(from, to, cost) <<endl;
	return 0;
}