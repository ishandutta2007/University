#include "stdio.h"
#include "iostream"
#include "string.h"
#include "algorithm"
#include "stack"
#include "math.h"
#include "stdlib.h"
#include "vector"



#define TEST
#define maxn 5020

using namespace std;



vector<int>v[maxn];
vector<int>strong[maxn];
vector<int>ans;
bool vis[maxn], instack[maxn];
int dfn[maxn], low[maxn];
int n, m;
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
	ans.clear();
	depth = 0;
	strongcnt = 0;
	for (int i = 1; i <= n; ++i)
	{	
		fa[i] = i;
		v[i].clear();
		strong[i].clear();
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
			strong[strongcnt].push_back(to);
		} while (to != u);

	}

}

int main(int argc, char const *argv[])
{

	#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
while(scanf("%d", &n)){	
	if (n == 0)
	{
		return 0;
	}
	scanf("%d", &m);

	clear();
	int x ,y;
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


	for(int i = 1; i <= strongcnt; i++)
	{
		if(outde[i] == 0)
		{
			for (int j = 0; j < strong[i].size(); ++j)
			{
				ans.push_back(strong[i][j]);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0, len = ans.size(); i < len; ++i)
	{
		printf("%d%c", ans[i], i == len - 1? '\n' : ' ');
	}


}
	#ifdef TEST
	fclose(stdin);
	fclose(stdout);
	#endif
	system("pause");
	return 0;
}