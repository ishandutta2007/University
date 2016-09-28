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
const int maxn = 1e5+20;

int l, n, m, d;
int w[maxn];

struct Node {
  ll t, d;
  Node (){}
  Node (ll t, ll d):t(t),d(d){}
};

bool operator < (Node a, Node b) {
  if (a.t == b.t) return a.d > b.d;
  return a.t > b.t;
}
priority_queue<Node> M, D;

ll solve()
{
  ll ret = 0;
  while(!M.empty()) M.pop();
  while(!D.empty()) D.pop();
  m = min(m, l);
  for (int i = 1; i <= n; i++)
    M.push({(ll)w[i],(ll)w[i]});
  for (int i = 0; i < m; i++)
    D.push({0,d});
  for (int i = 0; i < l; i++)
  {
    Node tmp = M.top();
    //cout << tmp.t << " " << tmp.d << endl;
    M.pop();
    {
      Node tt = D.top();
      D.pop();
      //cout << tt.t << "-" << tt.d << endl;
      ll tmpt = max(tmp.t, tt.t)+d;
      ret = max(ret, tmpt);
      D.push({tmpt, d});
    }
    M.push({tmp.t+tmp.d, tmp.d});
  }
  return ret;
  /*
  cout << ret << endl;
  cout << "=============" << endl;
  while(!M.empty())
  {
    Node tmp = M.top();
    M.pop();
    tmp.t -= tmp.d;
    if (tmp.t == 0) continue;
    cout <<tmp.t << " " << tmp.d << endl;
    Node tt = D.top();
    D.pop();
    cout <<tt.t << "-" << tt.d << endl;
    ll tmpt = max(tmp.t, tt.t)+d;
    cout << tmpt << endl;
    ret = max(ret, tmpt);
    D.push({tmpt, d});
  }
  return ret;
  */
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif

  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d%d%d%d", &l, &n, &m, &d);
    for (int i = 1; i <= n; i++)
      scanf("%d", &w[i]);
    sort(w+1, w+n+1);
    ll ans = solve();
    printf("Case #%d: %I64d\n", ka, ans);
  }



  return 0;
}

