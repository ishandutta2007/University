/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template <class T>
inline void RD(T &x) {
  char c=getchar(); 
  x=0;
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){ 
    x=x*10+c-'0';
    c=getchar(); 
  }
}
const int oo = 1e9+7;
const int maxn = 1e4+20;

ll n;

int main()
{
  cin >> n;
  ll now = 2;
  for (ll i = 1; i <= n; i++)
  {
    ll k = i*(i+1)*(i+1);
    printf("%I64d\n", k-now/i);
    assert(k-now/i >= 0);
    now = i*i+i;
  }
  return 0;
}

