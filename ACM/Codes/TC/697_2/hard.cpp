#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
int n, m;
int cnt[40];
ll pow2[60];


ll solve(int p)
{
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) if (i!=p)
  {
    for (int j = m-1; j >= 0; j--)
    {
      if ((v[i]>>j) != (v[p]>>j))
      {
        cnt[j]++;
        break;
      }
    }
  }
  /*
  for (int i = 0; i < m; i++)
  	printf("cnt[%d] = %d\n", i, cnt[i]);
  */
  ll ret = 0;
  for (int i = 0; i < m; i++)
  {
    ret += (ll)cnt[i]*cnt[i] * pow2[m-1];
    for (int j = 0; j < m; j++) if (i != j)
    {
      ret += (ll)cnt[i]*cnt[j]*pow2[m-2];
    }
  }
  return ret;
}

class XorOrderDiv2
{
  public:
  vector<ll> getExpectation(int mm, vector <int> a)
  {
    pow2[0] = 1;
    m = mm;
    for (int i = 1; i <= 40; i++)
      pow2[i] = pow2[i-1]*2;
    vector<ll> ans;
    v = a;n = a.size();
    for (int i = 0; i < n; i++)
    ans.push_back(solve(i));
    /*
    for (int i = 0; i < n; i++)
    cout << ans[i] << " " ;
    */
    return ans;
  }
};
