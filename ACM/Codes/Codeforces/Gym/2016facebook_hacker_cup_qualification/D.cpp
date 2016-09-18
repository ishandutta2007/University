#include <bits/stdc++.h>
#define L first
#define R second

using namespace std;
const int maxn = 320;
const int oo = 1e9+7;
typedef long long ll;

typedef pair<int,int> pii;

string str[maxn];

int n;
int pref[maxn][maxn];
int dp[maxn][maxn];
int len[maxn];


void pre()
{
  memset(pref, 0, sizeof(pref));
  for (int i = 1; i <= n; i++)
  {
    len[i] = str[i].length();
    for (int j = i+1; j <= n; j++)
    {
      int tmp = 0;
      while(tmp < str[i].length() && tmp < str[j].length() && str[i][tmp] == str[j][tmp])
        tmp++;
      pref[i][j] = pref[j][i] = tmp;
    }
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    int k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
      cin >> str[i];
    }
    sort(str+1, str+n+1);
    pre();
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i <= k; i++)
      dp[i][0] = 0;
    int ans = oo;
    /*
    for (int i = 1; i <= n; i++)
    {
      printf("%d :", len[i]);
      for (int j = 1; j <= n; j++)
      {
        printf("%d ", pref[i][j]);
      }
      printf("\n");
    }
    */
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= k; j++)
      {
        for (int p = 0; p < i; p++)
        {
          dp[i][j] = min(dp[i][j], dp[p][j-1] + len[p]-pref[i][p]+len[i]-pref[i][p]);
          if (j == k) ans = min(ans, dp[i][k] + len[i]);
        }
      }
    printf("Case #%d: %d\n", ka, ans+k);
  }

  return 0;
}
