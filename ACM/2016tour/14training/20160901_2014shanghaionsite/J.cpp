#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 100020;
const int oo = 1e9+7;

typedef long long ll;
typedef pair<int,int> pii;

ll a, b, c;
ll m, n;
ll at;
ll ansx, ansy;

ll solvex()
{
  ll cntls, ret, cnt;
  cntls = n-m-1;
  cnt = m/2;
  
  /*
  if (m+1 < 2)
    ret = 0;
  else if (m+1 == 2)
    ret = max(b, a);
  else*/
  {
    ret = max(b*m, (a+c)*cnt + (m-cnt*2)*b);
    ret = max(ret, (a+c)*cnt + (m-cnt*2)*c);
  }
  ret += cntls*a;
  return ret;
}

ll solvey()
{
  ll cntwi,cntls,ret,cnt;
  cntwi = m-1;
  cntls = n-cntwi;
  cnt = (cntls-1)/2;
  /*
  if (cntls < 2)
    ret = 0;
  else if (cntls == 2)
    ret = min(b, a);
  else*/
  {
    ret = min(b*(cntls-1), (a+c)*cnt + (cntls-1-cnt*2)*b);
    ret = min(ret, (a+c)*cnt + (cntls-1-cnt*2)*a);
  }
  ret += cntwi*c;
  return ret;
}

int main()
{
  int T;
  cin >> T;
  for (int ka = 1; ka <= T; ka++)
  {
    cin >> n >> m;
    cin >> a >> b >> c;

    at = (n-1)*b;
    ansx = ansy = at;
    if (a < c) swap(a, c);
    ansx = max(ansx, solvex());
    ansy = min(ansy, solvey());
    printf("Case #%d: %lld %lld\n",ka, ansx, ansy);
  }
  return 0;
}
