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
const int oo = 1e9+7;
const int maxn = 1e4+20;
int n;

typedef ll LL;

ll fac[200];
LL inv(LL x, LL m)
{
  if (x == 1) return x;
  return inv(m % x, m)*(m - m / x) % m;
}
ll cal(int a, int b) {
  if (a < b) return 0;
  if (b < 0) return 0;
  return fac[a]*inv(fac[b], oo)%oo*inv(fac[a-b], oo)%oo;
}
vector <int> px, py;
bool onright(int a, int b, int i)
{
  ll x1 = px[a]-px[b];
  ll y1 = py[a]-py[b];
  ll x2 = px[i]-px[b];
  ll y2 = py[i]-py[b];
  return x1*y2-x2*y1 > 0;
}
class IntersectingConvexHull
{
  public:
    ll solve(int a, int b)
    {
      ll cntl = 0, cntr = 0;
      for (int i = 0; i < n; i++) if (i != a && i != b)
      {
        if (onright(a, b, i)) cntr++;
        else cntl++;
      }
      ll tmp1 = 0;
      ll tmp2 = 0;
	  
	  //cout << cntl << " " << cntr << endl;
	  
      for (int i = 2; i <= cntl; i++)
        tmp1 = (tmp1+cal(cntl,i))%oo;
      for (int i = 2; i <= cntr; i++)
        tmp2 = (tmp2+cal(cntr,i))%oo;
      return tmp1*tmp2%oo;
    }
    int count(vector <int> x, vector <int> y)
    {
      n = x.size();
      px = x;
      py = y;
      fac[0] = 1;
      for (int i = 1; i <= 120; i++)
        fac[i] = fac[i-1]*i%oo;
      ll tot = 0;

      
      for (int i = 3; i <= n; i++)
      	for (int j = 3; j <= n; j++) if (i + j <= n)
      	  tot = (tot + cal(n, i)*cal(n-i,j)%oo)%oo;
      cout << tot << endl; 
       
      ll tmp = 0;  
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (i != j)
          tmp = (tmp + solve(i, j));
      tot = ((tot-tmp)%oo+oo)%oo;
      return (int)tot;
    }
};
