#include <bits/stdc++.h>
using namespace std;
const int maxn = 150020;
typedef long long ll;
struct Bit
{
  ll s[maxn*4];
  int num;
  void add(int x, int z)
  {
    for (int i=x;i<=num;i+=(i&-i)) s[i]+=z;
  }
  ll ask(int x)
  {
    ll tmp=0;
    for (int i=x;i;i-=(i&-i)) tmp+=s[i];
    return tmp;
  }
  void clear(int n)
  {
    num=n;
    memset(s,0,sizeof(s));
  }
}bit;

struct Seg {
  int p;
  int s,e;
  Seg(int p, int s, int e):p(p), s(s), e(e){}
  Seg(){}
  void show()
  {
    printf("%d: %d -- %d\n", p, s, e);
  }
}ver[maxn],hor[maxn];

bool cmpp(Seg &a, Seg &b)
{
  return a.p < b.p;
}

bool cmpe(Seg &a, Seg &b)
{
  return a.s < b.s;
}

int n;
int mi[maxn], mx[maxn];
vector<int> ha;
int cntver, cnthor;
int x1[maxn], y1[maxn], x2[maxn], y2[maxn];
map<int, int> mp;
vector<int> pos[maxn*4];

int getha(int x)
{
  return lower_bound(ha.begin(), ha.end(), x) - ha.begin() + 1;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    ll ans = 0;
    ha.clear();
    for (int i = 1; i <= n; i++)
    {
      scanf("%d%d%d%d", &x1[i],&y1[i],&x2[i],&y2[i]);
      ha.push_back(x1[i]);
      ha.push_back(x2[i]);
      ha.push_back(y1[i]);
      ha.push_back(y2[i]);
    }
    sort(ha.begin(), ha.end());
    cntver = cnthor = 0;
    for (int i = 1; i <= n; i++)
    {
      x1[i] = getha(x1[i]);
      y1[i] = getha(y1[i]);
      x2[i] = getha(x2[i]);
      y2[i] = getha(y2[i]);
      if (x1[i] == x2[i])
      {
        ver[cntver].p = x1[i];
        ver[cntver].s = min(y1[i], y2[i]);
        ver[cntver].e = max(y1[i], y2[i]);
        cntver++;
      }
      else
      {
        hor[cnthor].p = y1[i];
        hor[cnthor].s = min(x1[i], x2[i]);
        hor[cnthor].e = max(x1[i], x2[i]);
        cnthor++;
      }
    }
    sort(hor, hor + cnthor, cmpp);
    sort(ver, ver + cntver, cmpe);

    int bk = 0;
    bit.clear(n*4+100);
    mp.clear();
    for (int i = 0; i < cnthor; i++)
    {
      while(bk < cntver && ver[bk].s <= hor[i].p)
      {
        bit.add(ver[bk].p, 1);
        if (!mp.count(ver[bk].e))
        {
          pos[ver[bk].e].clear();
          mp[ver[bk].e] = 0;
        }
        mp[ver[bk].e]++;
        pos[ver[bk].e].push_back(ver[bk].p);
        bk++;
      }
      while(!mp.empty())
      {
        int tmp = mp.begin()->first;
        if (tmp < hor[i].p)
        {
          for (int j = 0,len = mp[tmp]; j < len; j++)
          {
            bit.add(pos[tmp][j], -1);
          }
          pos[tmp].clear();
          mp.erase(tmp);
        }
        else
          break;
      }
      ans += bit.ask(hor[i].e) - bit.ask(hor[i].s - 1);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}

