#include "stdio.h"
#include "iostream"
#include "string.h"
#include "algorithm"
#include "stack"
#include "math.h"
#include "stdlib.h"
#include "vector"



#define TEST
#define maxn 120

using namespace std;



vector<int>v[maxn];
bool vis[maxn], instack[maxn];
int dfn[maxn], low[maxn];
int n;
int depth, strongcnt;
int belong[maxn], strongsize[maxn];
int stk[maxn], top;
int fa[maxn];
int inde[maxn], outde[maxn];


void clear(){
	memset(vis, 0, sizeof(vis));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, 0, sizeof(instack));
	memset(belong, 0, sizeof(belong));
	memset(strongsize, 0, sizeof(strongsize));
	memset(inde, 0, sizeof(inde));
	memset(outde, 0, sizeof(outde));
	depth = 0;
	strongcnt = 0;
	for (int i = 1; i <= n; ++i)
	{	
		fa[i] = i;
		v[i].clear();
	}
}

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

	#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	scanf("%d", &n);

	clear();
	int x;
	for (int i = 1; i <= n; ++i)
	{
		while(scanf("%d", &x)){
			if(x == 0) break;
			v[i].push_back(x);
		}
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



	if(strongcnt == 1)
	{
		printf("1\n0\n");
		return 0;
	}
	int noin = 0, noout = 0;
	for(int i = 1; i <= strongcnt; i++)
	{
		// printf("%d   out = %d, in = %d\n", i, outde[i], inde[i]);
		if(outde[i] == 0) noout++;
		if(inde[i] == 0) noin++;
	}
	printf("%d\n%d\n", noin, max(noin, noout));

	#ifdef TEST
	fclose(stdin);
	fclose(stdout);
	#endif
	system("pause");
	return 0;
}