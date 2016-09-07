#include <bits/stdc++.h>
#define X first
#define Y second
#define pow pow2

using namespace std;
const int maxn = 200020;
typedef pair<int,int> pii;
typedef long long ll;

const ll oo = 1e9+7;
int r[maxn], vis[maxn];
int n;
ll cnt1, tot, totc;
set<int> path;
int tmp;
int pow[maxn];


void findc(int st)
{
  //cout << "circle" << endl;
  int now = r[st];
  int tmp = 1;
  while(now != st)
  {
    tmp++;
    now = r[now];
  }
  tot = tot*(pow[tmp]-2+oo)%oo;
  totc += tmp;
  //cout << tmp << endl;
}


void go(int x)
{
  if (path.count(x))
  {
    findc(x);
  }
  else if (vis[x] == 0)
  {
    path.insert(x);
    vis[x] = 1;
    go(r[x]);
  }
}

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &r[i]);
  pow[0] = 1;
  for (int i = 1; i <= n; i++)
    pow[i] = pow[i-1]*2%oo;
  tot = 1;
  for (int i = 1; i <= n; i++) if (vis[i] == 0)
  {
    tmp = 0;
    path.clear();
    go(i);
  }
  cnt1 = n - totc;
  for (int i = 0; i < cnt1; i++)
    tot = tot*2 % oo;
  printf("%I64d\n", tot);
  return 0;
}
