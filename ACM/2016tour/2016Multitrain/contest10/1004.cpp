#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef ll LL;

const int maxn = 3000200;
int n, k, m;
set<int> st;
int ans[maxn];
vector<int> del;

struct bit
{
  int b[maxn];
  int num;
  void add(int x,int z)
  {
    for (int i=x;i<=num;i+=(i&-i)) b[i]+=z;
  }
  int ask(int x)
  {
    int tmp=0;
    for (int i=x;i;i-=(i&-i)) tmp+=b[i];
    return tmp;
  }
  void init(int n)
  {
    num=n;
    memset(b,0,sizeof(b));
  }
}s,t;



int findk(int k)
{
  int l=1,r=n,tmp;
  while (l<=r)
  {
    int mid=(l+r)>>1;
    if (s.ask(mid)<=k)
    {
      tmp=mid;
      l=mid+1;
    }
    else
      r=mid-1;
  }
  return tmp;
}


void solve()
{
  int tot = n;
  int now = 1; 
  s.init(n+1);
  for (int i = 1; i <= n; i++) s.add(i, 1);
  for (int i = 1; i <= n; i++)
  {
    int x = findk(now);
    del.push_back(x);
    ans[i] = x;
    now = now + k;

    if (now > tot)
    {
      tot -= del.size();
      for (int i = 0, len = del.size(); i < len; i++)
        s.add(del[i],-1);
      now = 1;
      del.clear();
    }
  }
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
    scanf("%d%d%d", &n, &k, &m);

    st.clear();
    for (int i = 1; i <= n; i++)
      st.insert(i);

    solve();
    int t;
    while(m--)
    {
      scanf("%d", &t);
      printf("%d\n", ans[t]);
    }
  }
  return 0;
}
