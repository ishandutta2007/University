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

int n;
char str1[maxn], str2[maxn];
int pre[maxn], suf[maxn];

int solve() {
  pre[0] = 0;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (str2[i] != str2[i-1])
      sum++;
    if (str1[i] == str2[i]) {
      pre[i] = pre[i-1];
    } else {
      pre[i] = sum;
    }
  }
  suf[n+1] = 0;
  sum = 0;
  for (int i = n; i >= 1; i--) {
    if (str2[i] != str2[i+1]) {
      sum++;
    }
    if (str1[i] == str2[i]) {
      suf[i] = suf[i+1];
    } else {
      suf[i] = sum;
    }
  }
  int ans = n;
  for (int i = 1; i <= n+1; i++) {
    ans = min(ans, max(pre[i-1], suf[i]));
  }
  return ans;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif

  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++) {
    scanf("%d", &n);
    scanf("%s%s", str1+1, str2+1);
    
    int ans = solve();
    
    printf("Case #%d: %d\n", ka, ans);

  }

  return 0;
}

