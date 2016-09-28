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
const ll oo = 1e15+7;
const int maxn = 2e5+20;

int n, m;
int t[maxn];
int minst[maxn];
int mpcnt;
map<int,int> mp;

void add(int x) {
  mpcnt++;
  if (!mp.count(x)) mp[x] = 0;
  mp[x]++;
}
void dele(int x) {
  mpcnt--;
  mp[x]--;
  if (mp[x] == 0) 
    mp.erase(x);
}

void pre() {
  mpcnt = 1;
  mp[0] = 1;
  for (int i = 0; i < n; i++) {
    int tmp = mp.begin()->first;
    minst[i] = tmp;
    dele(tmp);
    tmp += t[i];
    while(mpcnt <= n-i-1) {
      add(tmp);
      tmp += t[i];
    }
    while((--mp.end())->first > tmp) {
      int del = (--mp.end())->first;
      dele(del);
      add(tmp);
      tmp+=t[i];
    }
  }
}


bool check(ll mid, ll cnt) {
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (minst[i] >= mid) break;
    sum += (mid-minst[i])/t[i];
    if (sum >= cnt) return true;
  }
  return sum >= cnt;
}


ll solve(ll cnt) {
  ll l = 0, r = oo, ret = oo;
  ll mid;
  while (l <= r) {
    mid = (l+r)/2;
    if (check(mid, cnt)){
      ret = min(ret, mid);
      r = mid-1;
    }
    else
      l = mid+1;
  }
  return ret;
}


int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  sort(t, t+n);
  
  memset(minst, 0x3f, sizeof(0x3f));
  pre();
  
  int cnt;
  for (int i = 0; i < m; i++) {
    scanf("%d", &cnt);
    ll ans = solve(cnt);
    printf("%I64d\n", ans);
  }

  return 0;
}

