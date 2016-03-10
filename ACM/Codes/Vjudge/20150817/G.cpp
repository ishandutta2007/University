#include "stdio.h"
#include "iostream"
#include "string.h"
#include "algorithm"
#include "stack"
#include "math.h"
#include "stdlib.h"
#include "vector"



#define TEST
#define maxn 100020

using namespace std;



vector<int>v[maxn];
bool vis[maxn], instack[maxn];
int dfn[maxn], low[maxn];
int n;
int depth, strongcnt;
int belong[maxn], strongsize[maxn];
int stk[maxn], top;
int inde[maxn], outde[maxn];
int cost[maxn];
struct Strong
{
	int cost, cnt;
}strong[maxn];


void tarjan(int u){
	dfn[u] = low[u] = ++depth;
	instack[u] = true;
	stk[++top] = u;

	int to;
	for (int i = 0; i < v[u].size(); ++i)
	{
		to = v[u][i];
		if(!dfn[to]){
			tarjan(to);
			low[u] = min(low[to], low[u]);
		}else if (instack[to])
		{
			//why dfn[i] not low[i];
			low[u] = min(low[u], dfn[to]);
		}

	}
	if (dfn[u] == low[u])
	{
		strongcnt++;
		do
		{
			to = stk[top--];
			instack[to] = false;
			belong[to] = strongcnt;
			strongsize[strongcnt]++;
			if(cost[to] < strong[strongcnt].cost)
			{
				strong[strongcnt].cost = cost[to];
				strong[strongcnt].cnt = 1;
			}
			else if(cost[to] == strong[strongcnt].cost)
				strong[strongcnt].cnt++;
		} while (to != u);

	}

}


int main(int argc, char const *argv[])
{

	#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	scanf("%d", &n);

	int x, y, m;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &cost[i]);
		strong[i].cost = 1000002000;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}


	for (int i = 1; i <= n; ++i)
	{
		if (!dfn[i])
		{
			tarjan(i);
		}
	}



	// for (int i = 1; i <= n; ++i)
	// {
	// 	printf("%d belongs to strong[%d] !!\n", i, belong[i] );
	// }
	int to;
	for(int i = 1; i <= n; i++)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			to = v[i][j];
			if(belong[i] != belong[to]){
				outde[belong[i]]++;
				inde[belong[to]]++;
			}
		}
	}


	long long ans = 0LL, cnt = 1LL;
	for(int i = 1; i <= strongcnt; i++)
	{
		ans += (long long)strong[i].cost;
		cnt *= (long long)strong[i].cnt;
	}
	printf("%I64d %I64d\n", ans, cnt % 1000000007);
	#ifdef TEST
	fclose(stdin);
	fclose(stdout);
	#endif
	system("pause");
	return 0;
}