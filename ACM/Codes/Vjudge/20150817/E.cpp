#include "stdio.h"
#include "iostream"
#include "string.h"
#include "algorithm"
#include "stack"
#include "math.h"
#include "stdlib.h"
#include "vector"



// #define TEST
#define maxn 1020

using namespace std;


struct Edge
{
	int u, v;
}edge[maxn];

int fa[maxn];
int n, m;
vector<int>v[maxn];
bool isbridge[maxn];
int de[maxn];

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
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &edge[i].u, &edge[i].v);
	}

	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
			fa[j] = j;

		for(int j = 1; j <= m; j++)
		{
			if(j == i) continue;
			unionset(edge[j].u, edge[j].v);
		}
		int rot = root(1);
		for(int j = 2; j <= n; j++)
			if(root(j) != rot)
			{
				isbridge[i] = true;
				break;
			}



	}

	// for(int i = 1; i <= m; i++)if(isbridge[i])
	// 	printf("%d is bridge\n", i);

	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)if(!isbridge[i])
	{
		unionset(edge[i].u,edge[i].v);
	}

	for(int i = 1; i <= m; i++)if(isbridge[i])
	{
		de[root(edge[i].u)]++;
		de[root(edge[i].v)]++;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)if(de[i] == 1)
		cnt++;

	printf("%d\n", (cnt + 1) / 2);

	#ifdef TEST
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}