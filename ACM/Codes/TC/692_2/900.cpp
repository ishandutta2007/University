#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = 1e9+9;

ll ans[200];


ll Pow(ll a, ll b, ll p)
{
  ll ret = 1;  
  while(b) {  
    if(b & 1) ret = (ret*a)%p;  
    a = (a*a)%p;  
    b >>= 1;  
  }  
  return ret%p;  
}  

ll cal(ll len, ll k, ll l)
{
  
}

ll calans(ll len, ll k, ll rest, ll l)
{
  memset(ans, 0, sizeof(ans));
  int mx = len / l;
  for (int i = mx; i >= k; i--)
  {
    ans[i] = cal(len, i, l);
    for (int j = i+1; j <= mx; j++)
    {
      ans[i] = (ans[i]-ans[j]+oo)%oo;
    }
  }
  return ans[k];
}

class LinenCenterEasy
{
public:
	int countStrings(string str, int n, int k)
	{
		int l = str.length();
		ll ans = 0;
		for (int rest = 0; rest <= n; rest++)
		{
      ans = (ans + calans(l*k+rest, k, rest, l)) % oo;
			cout << ans << endl;
		}
		return ans;
	}
};

