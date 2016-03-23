/*
    给定 n 个点以及 m 条无向边，每条边的长度和花费是已知的，求两个点的最短距离，输出最短的距离并且最短距离下最小的费用。
    输入样例：
    3 2     //三个点， 两条边。
    1 2 5 6 //1 到 2 的边 长度5 花费6
    2 3 4 5 //2 到 3 的边 长度4 花费5
    1 3     //求 1 到 3 的最短距离和最小消费
*/



#include <bits/stdc++.h> // 包含所有 c++ 标准库
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> PII;

const int maxn = 10000;

struct Edge
{
    int u, v, l, c;
    Edge();
    Edge(int u, int v, int l, int c):u(u),v(v),l(l),c(c){}
};

struct Node
{
    int v, l, c;
    Node(){}
    Node(int v, int l, int c):v(v),l(l),c(c){}
    bool operator < (const Node &a) const
    {
        if(l == a.l) return c > a.c;
        return l > a.l;
    }
};

vector<Edge> G[maxn];
priority_queue<Node>pq;
int dist[maxn],cost[maxn],vis[maxn],n,m,tot;

void add_edge(int u, int v, int l , int c)
{
    G[u].push_back(Edge(u,v,l,c));
}


// 返回 pair <int , int > 类型， first 为长度， second 为花费。
PII dijstra(int s, int d)
{
    memset(dist, INF, sizeof(dist));
    memset(cost, INF, sizeof(cost));
    memset(vis, 0, sizeof(vis));
    while(!pq.empty()) pq.pop();
    pq.push(Node(s, 0, 0));
    while(!pq.empty())
    {
        const Node nd = pq.top();
        pq.pop();
        if(vis[nd.v]) continue;
        vis[nd.v] = true;
        dist[nd.v] = nd.l;
        cost[nd.v] = nd.c;
        if(nd.v == d) return make_pair(dist[d], cost[d]);
        for(int i = 0, len = G[nd.v].size(); i < len; i++)
        {
            Edge& e = G[nd.v][i];
            if(!vis[e.v])
            {
                pq.push(Node(e.v, nd.l + e.l, nd.c + e.c));
            }
        }
    }
    return make_pair(dist[d], cost[d]);
}
int main()
{
	while(scanf("%d%d", &n, &m) != EOF && n && m)
	{
		for(int i = 0; i <= n; i++) G[i].clear();
		tot = 0;
		int a, b, c, d;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			add_edge(a, b, c, d);
			add_edge(b, a, c, d);
		}
		int s, t;
		scanf("%d%d", &s, &t);
		PII p = dijstra(s, t);
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}
