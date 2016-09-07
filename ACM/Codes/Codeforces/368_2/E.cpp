#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;

const int maxn = 2220;

struct bit
{
	ll b[maxn][maxn];
	int nx, ny;
	void add(int x,int y,int z)
	{
		for (int i=x;i<=nx;i+=(i&-i))
			for (int j=y;j<=ny;j+=(j&-j))
				b[i][j]+=z;
	}
	ll ask(int x, int y)
	{
		ll tmp=0;
		for (int i=x;i;i-=(i&-i))
			for (int j=y;j;j-=(j&-j))
				tmp+=b[i][j];
		return tmp;
	}
	void init(int x, int y)
	{
		nx=x; ny=y;
		memset(b,0,sizeof(b));
	}
}bit;

typedef pair<int,int> pii;
int n, m, k, q;
vector<pii> pt[maxn];
char cmd[1000200][10];
vector<int> op[1000200], contr[maxn];
ll ans[1000200], mp[maxn][maxn];
set<int> open;

bool check(int x)
{
  return x <= 0 || x > 2000;
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++)
  {
    int tmp, tx, ty, tt;
    scanf("%d", &tmp);
    while(tmp--)
    {
      scanf("%d%d%d", &tx, &ty, &tt);
      mp[tx][ty] = tt;
      pt[i].push_back(pii(tx, ty));
    }
    open.insert(i);
  }

  scanf("%d", &q);
  for (int i = 1; i <= q; i++)
  {
    int tmp;
    scanf("%s", cmd[i]);
    if (cmd[i][0] == 'A')
    {
      for (int j = 0; j < 4; j++)
      {
        scanf("%d", &tmp);
        op[i].push_back(tmp);
      }
      for (auto x : open)
        contr[x].push_back(i);
    }
    else
    {
      scanf("%d", &tmp);
      if (open.count(tmp)) open.erase(tmp);
      else open.insert(tmp);
    }
  }
  bit.init(n+2, m+2);
  for (int i = 1; i <= k; i++)
  {
    for (int j = 0, len = pt[i].size(); j < len; j++)
      bit.add(pt[i][j].X, pt[i][j].Y, mp[pt[i][j].X][pt[i][j].Y]);

    for (int j = 0, len = contr[i].size(); j < len; j++)
    {
      int id = contr[i][j], x1,y1,x2,y2;
      x1 = op[id][0];
      y1 = op[id][1];
      x2 = op[id][2];
      y2 = op[id][3];
      ans[id] += bit.ask(x2, y2)-bit.ask(x2, y1-1)-bit.ask(x1-1, y2)+bit.ask(x1-1,y1-1);
    }
    for (int j = 0, len = pt[i].size(); j < len; j++)
      bit.add(pt[i][j].X, pt[i][j].Y, -mp[pt[i][j].X][pt[i][j].Y]);
  }
  for (int i = 1; i <= q; i++) if (cmd[i][0] == 'A')
    printf("%I64d\n", ans[i]);
  return 0;
}
