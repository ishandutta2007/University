#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#define maxn 120000
#define maxm 120000
#define oo 1000000007
using namespace std;

int fir[maxn],vis[maxn],low[maxn],dfn[maxn];
int pre[maxm],bridge[maxm];
int bel[maxn],dg[maxn];
int n,m,num,cnt,ans,tot;

struct edge
{
	int s,t,next;
}e[maxm];

void add(int x,int y)
{
	e[++tot].s=x; e[tot].t=y; e[tot].next=fir[x]; fir[x]=tot;
}

void tarjan(int i)
{
	vis[i]=1;
	dfn[i]=low[i]=++cnt;
	for (int j=fir[i];j;j=e[j].next)
	{
		int k=e[j].t;
		if (!vis[k])
		{
			pre[k]=j^1;
			tarjan(k);
			low[i]=min(low[i],low[k]);
		}
		else if (j!=pre[i])
			low[i]=min(low[i],dfn[k]);
	}
	if (pre[i]&&dfn[i]==low[i]) bridge[pre[i]]=bridge[pre[i]^1]=1;
}

void dfs(int i,int num)
{
	vis[i]=1;
	bel[i]=num;
	for (int j=fir[i];j;j=e[j].next)
		if (!bridge[j])
		{
			int k=e[j].t;
			if (!vis[k]) dfs(k,num);
		}
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		memset(pre,0,sizeof(pre));
		memset(fir,0,sizeof(fir));
		memset(bridge,0,sizeof(bridge));
		memset(dg,0,sizeof(dg));

		tot=1;
		int x,y;
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		cnt=0;
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++)
			if(!vis[i])
				tarjan(i);

		num=0;
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++)
			if (!vis[i])
				dfs(i,++num);

		for (int j=2;j<=tot;j+=2)
		{

			x=bel[e[j].s],y=bel[e[j].t];
			if (x!=y)
			{
				dg[x]++;
				dg[y]++;
			}
		}
		ans=1;
		for (int i=1;i<=num;i++) if (dg[i]>2) ans=0;
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}