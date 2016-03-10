#include <bits/stdc++.h>
using namespace std;

const int maxn = 20020;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int u, v, cap;
}e[maxn*30];

int G[maxn], nxt[maxn*30], layer[maxn], cur[maxn];
int n, m, st, ed, tot; 	//源点st， 汇点ed, 点数n

void adde1(int a, int b, int val)
{
	e[tot].u = a;
	e[tot].v = b;
	e[tot].cap = val;
	nxt[tot] = G[a];
	G[a] = tot++;
	e[tot].u = b;
	e[tot].v = a;
	e[tot].cap = 0;
	nxt[tot] = G[b];
	G[b] = tot++;
}
void adde2(int a, int b, int val)
{
	e[tot].u = a;
	e[tot].v = b;
	e[tot].cap = val;
	nxt[tot] = G[a];
	G[a] = tot++;
	e[tot].u = b;
	e[tot].v = a;
	e[tot].cap = val;
	nxt[tot] = G[b];
	G[b] = tot++;
}

int calc_layer()
{
	queue<int> q;
	memset(layer, 0, sizeof(layer));
	q.push(st);
	layer[st] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = G[u]; i != -1; i = nxt[i])if(e[i].cap && layer[e[i].v] == 0)
		{
			layer[e[i].v] = layer[u] + 1;
			q.push(e[i].v);
		}
	}
	return layer[ed];
}

int dfs(int x, int a)
{
	if (x == ed || a == 0) return a;
	int f, flow = 0;
	for(int& i = cur[x]; i != -1; i = nxt[i])
		if(layer[x] + 1 == layer[e[i].v] && (f = dfs(e[i].v, min(a,e[i].cap))))
		{
			e[i].cap -= f;
			e[i^1].cap += f;
			flow += f;
			a -= f;
			if(!a) break;
		}
	return flow;
}

int dinic()
{
	int flow = 0;
	while(calc_layer())
	{
		//当前弧优化
		for(int i = 0; i <= n; i++)
			cur[i] = G[i];
		flow += dfs(st, INF);
	}
	return flow;
}
int main()
{
    int i,a,b,val;
    while(~scanf("%d%d",&n,&m))
    {
        tot = 0;
        memset(G, -1, sizeof(G));
        st=0,ed=n+1;
        for(i=1;i<=n;i++){
            scanf("%d%d",&a,&b);
            adde1(st,i,a);
            adde1(i,ed,b);
        }
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&val);
            adde2(a,b,val);
        }
        printf("%d\n",dinic());
    }
    return 0;
}