// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>


using namespace std;
const int maxn = 20020;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int u, v, cap;
}e[maxn*30];

int G[maxn], nxt[maxn*30], layer[maxn], cur[maxn];
int n, st, ed, tot; 	//源点st， 汇点ed, 点数n

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

void dclear()
{
	memset(e, 0, sizeof(e));
	memset(G, -1, sizeof(G));
	memset(nxt, 0, sizeof(nxt));
	memset(cur, 0, sizeof(cur));
	n = st = ed = tot = 0;
}


char mp[40][40], mpi[40][40];
int tn, td, tw;

int main()
{
	int T;
	cin >> T;
	for (int ka = 1; ka <= T; ka++)
	{
		dclear();
		scanf("%d%d", &tn, &td);
		for (int i = 0; i < tn; i++)
			scanf("%s", mpi[i]);
		for (int i = 0; i < tn; i++)
			scanf("%s", mp[i]);
		tw = strlen(mp[0]);
		st = 2*tn*tw;
		ed = 2*tn*tw+1;
		n = ed + 1;
		int cnt = 0;
		for (int i = 0; i < tn; i++)
			for(int j = 0; j < tw; j++)
			{
				if(mp[i][j] == 'L')
					adde1(st, i*tw + j, 1),cnt++;
				if((i-td < 0 || i+td >= tn || j-td < 0 || j+td>=tw) && mpi[i][j] > '0')
					adde1(tn*tw + i*tw + j, ed, INF);
				if(mpi[i][j] > '0') adde1(i*tw + j, tn*tw + i*tw + j, mpi[i][j]-'0');
			}

		for (int i1 = 0; i1 < tn; i1++)
			for (int j1 = 0; j1 < tw; j1++)if(mpi[i1][j1] > '0')
				for (int i2 = 0; i2 < tn; i2++)
					for (int j2 = 0; j2 < tw; j2++)if(mpi[i2][j2] > '0' && 
						(i1 != i2 || j1 != j2) &&
						(abs(i1-i2) + abs(j1-j2) <= td))
					{
						adde1(tn*tw + i1*tw + j1, i2*tw + j2,INF);
					}

		int ans = cnt - dinic();
		if(ans == 0)
			printf("Case #%d: no lizard was left behind.\n", ka);
		else if(ans == 1)
			printf("Case #%d: 1 lizard was left behind.\n", ka);
		else 
			printf("Case #%d: %d lizards were left behind.\n", ka, ans);
	}




	return 0;
}