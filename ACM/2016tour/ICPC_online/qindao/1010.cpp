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

struct item {
  int t, sc;
  double d;
  item(){}
  item(int a, int b) {
    t = a, sc = b;
    d = b*1.0/a;
  }
}it[120];

bool operator < (item a, item b) {
  return a.d > b.d;
}

int n, m;
ll ans;
int tot;
const int MX = 7e7;

void dfs(int t, ll now, int r)
{
  tot++;
  if (now > ans) ans = now;
  if (t > n || tot > MX) return;
  if (it[t].t <= r)
    dfs(t+1, now+it[t].sc, r-it[t].t);
  dfs(t+1, now, r);
}

int main()
{
  while(scanf("%d%d", &n, &m) != EOF)
  {
    int ta, tb;
    for (int i = 1; i <= n; i++)
    {
      scanf("%d%d", &ta, &tb);
      it[i] = item(ta, tb);
    }
    sort(it+1, it+n+1);
    ans = 0;
    tot = 0;
    dfs(1, 0, m);
    printf("%I64d\n", ans);
  }
  return 0;
}

