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

ll a[4] = {2, 3, 5, 7};
vector<ll> vll;

void dfs(int t, ll now)
{
  //cout << t << " " << now << endl;
  //system("pause");
  if (t >= 4)
  {
    vll.push_back(now);
    return;
  }
  ll tmp = 1;
  for (ll tmp = 1; tmp*now <= 2*oo; tmp*=a[t])
  {
    dfs(t+1, tmp*now);
  }
}

int main()
{
  dfs(0, 1);
  //system("pause");
  int T;
  sort(vll.begin(), vll.end());
  scanf("%d", &T);
  int tmp;
  while(T--)
  {
    scanf("%d", &tmp);
    int id = lower_bound(vll.begin(), vll.end(), tmp)-vll.begin();
    printf("%I64d\n", vll[id]);
  }
  return 0;
}

