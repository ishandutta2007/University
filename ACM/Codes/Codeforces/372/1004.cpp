#include <bits/stdc++.h>
#define maxn 1020
#define maxm 20200

using namespace std;
typedef long long ll;
const ll inf = 1e17+20;
struct edge {
	int s,t,next,flag;
	ll val;
}e[maxm];
struct tii {
	int x, y;
	ll z;
	tii(){}
	tii(int x, int y, ll z):
	x(x), y(y), z(z){}
};
tii p[maxm];
ll dis[2][maxn];
int vis[maxn], fir[maxn];
int n,m,tot,st,ed;
ll len;

struct node
{
	int id;
	ll dis;
	node(){}
	node(int x,ll y) {
		id=x; dis=y;
	}
};

bool operator < (node a, node b) {
  return a.dis > b.dis;
}


priority_queue<node> q;

void dij(int st, int id)
{
	for (int i=0;i<=n;i++) dis[id][i]=inf;
	memset(vis,0,sizeof(vis));
	while (!q.empty()) q.pop();
	q.push(node(st,0));
	dis[id][st]=0;
	while (!q.empty())
	{
		int i=q.top().id;
		q.pop();
		if (vis[i]) continue;
		vis[i]=1;
		for (int j=fir[i];j;j=e[j].next)
		{
			int k=e[j].t;
			if (!vis[k]&&dis[id][i]+e[j].val<dis[id][k])
			{
				dis[id][k]=dis[id][i]+e[j].val;
				q.push(node(k,dis[id][k]));
			}
		}
	}
}

void add_edge(int x, int y, ll z, int w)
{
	e[++tot].s=x; e[tot].t=y; e[tot].val=z;
	e[tot].flag=w;
	e[tot].next=fir[x]; fir[x]=tot;
}

int main()
{
  int x, y, z;
  cin >> n >> m >> len >> st >> ed;
	for (int i=1;i<=m;i++)
	{
    cin >> x >> y >> z;
		p[i]=tii(x, y, z);
		if (z==0) {
			add_edge(x, y, inf, i);
			add_edge(y, x, inf, i);
		}
		else {
			add_edge(x, y, z, 0);
			add_edge(y, x, z, 0);
		}
	}
	dij(st, 0);
	ll ans1=dis[0][ed];

	for (int i=1;i<=tot;i++)
		if (e[i].flag!=0)
			e[i].val=1;
	dij(st, 0);
	ll ans2=dis[0][ed];

	vector<int> tmp;
	tmp.clear();
	dij(ed, 1);
	if (ans1>=len && ans2<=len)
	{
		memset(vis,0,sizeof(vis));
		x=st;
		vis[st]=1;
		while (x!=ed)
		{
			for (int j=fir[x];j;j=e[j].next)
			{
				y=e[j].t;
				if (!vis[y] && dis[0][x]+e[j].val+dis[1][y]==dis[0][ed])
				{
					x=y;
					vis[y]=1;
					if (e[j].flag!=0)
						tmp.push_back(e[j].flag);
					break;
				}
			}
		}

		for (int j:tmp) p[j].z=1;
		if (tmp.size()>0) p[tmp[0]].z+=(len-ans2);

		for (int i=1;i<=m;i++)
			if (p[i].z==0)
				p[i].z=inf;

    cout << "YES" << endl;
		for (int i=1;i<=m;i++)
      cout << p[i].x << ' ' << p[i].y << ' ' << p[i].z << endl;
	}
	else
    cout << "NO" << endl;
	return 0;
}
