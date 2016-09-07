#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 1e5+10;
const int oo = 1e9+7;

typedef long long ll;
typedef vector<int> vi;

int n, m;
int a[maxn], b[maxn];
map<int, vi> mp1, mp2;

void pre(map<int,vi> &mp, int sd)
{
  ll tmp;
  for (int mask = 1; mask < (1<<m); mask++)
  {
    tmp = 1;
    for (int i = 0; i < m; i++) if ((mask>>i)&1)
    {
      tmp *= b[i];
      tmp %= sd;
    }
    if (!mp.count(tmp))
      mp[tmp] = vi(0);
    mp[tmp].push_back(mask);
  }
}

void solve(int mask, int sd, set<int> &st, map<int,vi> &mp)
{
  ll tmp = 1;
  for (int i = 0; i < n; i++) if ((mask>>i)&1)
  {
    tmp *= a[i];
    tmp %= sd;
  }
  if (mp.count(tmp))
    for (int x : mp[tmp])
      st.insert(x);
}


int cal(int mask, int sd, int *a, int sz)
{
  ll tmp = 1;
  for (int i = 0; i < sz; i++) if ((mask>>i)&1)
  {
    tmp *= a[i];
    tmp %= sd;
  }
  return (int)tmp;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  pre(mp1, (int)1e9+7);
  /*
  for (auto v : mp1)
  {
    cout << v.first << " : ";
    for (auto x : v.second)
    {
      cout << x << " ";
    }
    cout << endl;
  }
  */
  int flag = 0;
  int ans1, ans2;
  for (int mask = 1; mask < (1<<n) && !flag; mask++)
  {
    set<int> st1;
    //set<int> st2;
    solve(mask, (int)1e9+7, st1, mp1);
    //solve(mask, 100003, st2, mp2);
    for (int x : st1)
    {
      int tmp1 = cal(mask, (int)1e9+9, a, n);
      int tmp2 = cal(x, (int)1e9+9, b, m);
      if (tmp1 == tmp2)
      {
        flag = 1;
        ans1 = mask;
        ans2 = x;
      }
    }
  }
  if (flag)
  {
    printf("Y\n");
    printf("%d %d\n", __builtin_popcount(ans1), __builtin_popcount(ans2));
    for (int i = 0; i < n; i++) if ((ans1>>i)&1)
      printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < m; i++) if ((ans2>>i)&1)
      printf("%d ", b[i]);
    printf("\n");
  }
  else
    printf("N\n");
  return 0;
}

