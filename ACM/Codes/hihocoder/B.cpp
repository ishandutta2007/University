#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define maxn 220000
#define maxm 220000
#define oo 1000000007
using namespace std;

struct edge
{
	int s,t,next;
}e[maxm];
int fir[maxn],flag[maxn],dep[maxn],mxdep[maxn],way[maxn],mxway[maxn];
int tot,n;
void add(int x,int y)
{
	e[++tot].s=x; e[tot].t=y; e[tot].next=fir[x]; fir[x]=tot;
}

void dfs(int x)
{
	mxdep[x]=dep[x];
	for (int j=fir[x];j;j=e[j].next)
	{
		int k=e[j].t;
		dep[k]=dep[x]+1;
		dfs(k);
		mxdep[x]=max(mxdep[x],mxdep[k]);
	}
}

void color(int x)
{
	flag[x]=1;
	for (int j=fir[x];j;j=e[j].next)
	{
		int k=e[j].t;
		if (mxdep[k]==mxdep[1])
		{
			color(k);
			break;
		}
	}
}

void getway(int x)
{
	mxway[x]=way[x];
	for (int j=fir[x];j;j=e[j].next)
	{
		int k=e[j].t;
		if (!flag[k])
		{
			way[k]=way[x]+1;
			getway(k);
			mxway[x]=max(mxway[x],mxway[k]);
		}
	}
}

int main()
{
	scanf("%d",&n);
	int x,y;
	tot=0;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	dep[1]=0;
	dfs(1);
	color(1);
	int ans=0;
	for (int i=1;i<=n;i++)
		if (flag[i])
		{
			way[i]=0;
			getway(i);
			ans=max(ans,mxdep[1]+mxway[i]);
		}
	printf("%d\n",ans);
	return 0;
}