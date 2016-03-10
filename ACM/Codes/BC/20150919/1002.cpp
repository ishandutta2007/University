#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define INF 1000000007
#define maxn 520
#define maxm 4200

using namespace std;

int a[maxn][maxn];
int n,m,p;

struct bit
{
	int b[maxn][maxn];
	int numx,numy;
	void add(int x, int y, int z)
	{
		for (int i=x;i<=numx;i+=(i&-i))
			for (int j=y;j<=numy;j+=(j&-j))
				b[i][j]^=z;
	}
	int ask(int x, int y)
	{
		int tmp=0;
		for (int i=x;i>=1;i-=(i&-i))
			for (int j=y;j>=1;j-=(j&-j))
				tmp^=b[i][j];
		return tmp;
	}
	void clear(int n, int m)
	{
		numx=n;
		numy=m;
		memset(b,0,sizeof(b));
	}
}s;

int main()
{
	int Case;
	scanf("%d",&Case);
	while (Case--)
	{
		scanf("%d%d%d",&n,&m,&p);
		s.clear(n,m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				s.add(i,j,a[i][j]);
			}
		int u,v,x,y,z,cmd;
		for (int i=1;i<=p;i++)
		{
			scanf("%d",&cmd);
			if (cmd==1)
			{
				scanf("%d%d%d%d",&u,&v,&x,&y);
				int a=s.ask(x,y);
				a^=s.ask(u-1,y);
				a^=s.ask(x,v-1);
				a^=s.ask(u-1,v-1);
				if (a==0) printf("No\n");
				else printf("Yes\n");
			}
			else
			{
				scanf("%d%d%d",&x,&y,&z);
				s.add(x,y,a[x][y]);
				a[x][y]=z;
				s.add(x,y,a[x][y]);
			}
		}
	}
	return 0;
}