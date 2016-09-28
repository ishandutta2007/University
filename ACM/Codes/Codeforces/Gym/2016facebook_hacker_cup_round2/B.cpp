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
const int maxn = 3e3+20;

double f[maxn][maxn];
double sum[maxn][maxn];
double dp[maxn];

int n, k;
double p, q;


double cal(int x) {
  if (x < k) return 0.0;
  return sum[x][x] - sum[x][k-1];
}

double solve(int c) {
  //cout << c << ": " ;
  int t = n/c, r = n%c;
  double ret = (sum[c][c]-sum[c][k-1])*t;
  if (r && r >= k) ret += sum[r][r]-sum[r][k-1];
  //cout << ret << endl;
  return ret;
}


int main() {
  
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++) {
    scanf("%d%d%lf", &n, &k, &p);
    memset(f, 0, sizeof(f));
    memset(sum, 0, sizeof(sum));
    q = 1.0-p;
    f[0][0] = 1.0;
    double tmp = 1.0;
    for (int i = 1; i <= n; i++) {
      tmp *= q;
      f[i][0] = tmp;
      sum[i][0] = tmp;
      for (int j = 1; j <= i; j++) {
        f[i][j] = f[i-1][j-1]*p + f[i-1][j]*q;
        sum[i][j] = sum[i][j-1] + f[i][j];
      }
    }
    double ans = 0.0;
    
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        dp[i] = max(dp[i], dp[j]+cal(i-j));
      }
      ans = max(ans, dp[i]);
    }

    printf("Case #%d: %.9f\n", ka,ans);
  }
  return 0;
}

