#include "stdio.h"
#include "iostream"
#include "string.h"
#include "algorithm"
#include "stack"
#include "math.h"
#include "stdlib.h"
#include "vector"
#define maxn 100020
using namespace std;
vector<int>v[maxn];
bool vis[maxn], instack[maxn];
int dfn[maxn], low[maxn];
int n, m;
int depth, strongcnt;
int belong[maxn], strongsize[maxn];
int stk[maxn], top;
int fa[maxn];
int inde[maxn], outde[maxn];


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
		} while (to != u);

	}

}

int root(int a){
    while(a != fa[a])
        a = fa[a] = fa[fa[a]];
    return a;
}

void unionset(int a, int b){
	int ra = root(a), rb = root(b);
	fa[ra] = rb;
}


int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	int x ,y;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		unionset(x, y);
	}

	int rot = root(1);
	for (int i = 2; i <= n; ++i)
	{
		if (root(i) != rot)
		{
			printf("0\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!dfn[i])
		{
			tarjan(i);
		}
	}
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
	int count = 0;
	int ans = 0;
	for(int i = 1; i <= strongcnt; i++)
	{
		if(outde[i] == 0)
		{
			count ++;
			ans += strongsize[i];
		}
	}
	if(count == 1)
	{
		printf("%d\n", ans);
	}else{
		printf("0\n");
	}
	return 0;
}