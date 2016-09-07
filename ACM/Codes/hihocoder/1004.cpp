#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1000020;

map<int, int> mp;
set<pii> st;
int n, a[maxn];

void solve()
{
  for (int i = 1; i <= n; i++)
  {
    int tmp;
    if ((--st.end())->X*2 > n-i+1)
    {
      tmp = (--st.end())->Y;
    }
    else
    {
      tmp = mp.begin()->X;
      if (tmp == a[i-1])
        tmp = (++mp.begin())->X;
    }
    st.erase(pii(mp[tmp], tmp));
    mp[tmp]--;
    if (mp[tmp] == 0) mp.erase(tmp);
    else st.insert(pii(mp[tmp], tmp));
    a[i] = tmp;
  }
  for (int i = 1; i <= n; i++)
  {
    printf("%d%c", a[i], i==n? '\n':' ');
  }
}

int main()
{
  int mx = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
    if (!mp.count(a[i])) mp[a[i]] = 0;
    mp[a[i]]++;
    mx = max(mx, mp[a[i]]);
  }
  if (mx > n/2 + n%2)
  {
    printf("-1\n");
    return 0;
  }
  for (auto x : mp)
    st.insert(pii(x.Y, x.X));
  solve();
  return 0;
}
