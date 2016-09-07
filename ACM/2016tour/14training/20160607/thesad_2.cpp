#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 400020;
const int oo = 1e9+7;

int n, m, L;
int S[maxn];
int h[2][maxn];

ll calans()
{
  ll ans = 0, tmp = 0;
  int l = 0;
  for (int r = 1; r <= 400000; r++)
  {
    tmp += S[r];
    if (r - l > L)
    {
      l++;
      tmp -= S[l];
    }
    if (r - l == L)
    {
      ans = max(ans, tmp);
    }
  }
  return ans;
}

int main()
{
  freopen("in.txt", "r", stdin);
  int T;
  scanf("%d", &T);
  int h1, h3;
  for (int ka = 1; ka <= T; ka++)
  {
    memset(S, 0, sizeof(S));
    scanf("%d%d%d", &n, &m, &L);
    L *= 4;
    memset(h, 0, sizeof(h));
    int tx, tk, tl;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &tx, &tk, &tl);
      tx *= 4;
      tl *= 4;
      if (tk == 1)
        h[0][tx] = max(h[0][tx], tl);
      else
        h[1][tx] = max(h[1][tx], tl*3);
    }
    h1 = h3 = 0;
    for (int i = 400000; i > 0; i--)
    {
      h1 = max(h1, h[0][i]);
      h3 = max(h3, h[1][i]);
      
      S[i] = max(S[i], h1*2 - 1);
      S[i] = max(S[i], h3*2 - 3);
      h1 -= 1;
      h3 -= 3;
    }
    memset(h, 0, sizeof(h));
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d%d", &tx, &tk, &tl);
      tx *= 4;
      tl *= 4;
      if (tk == 1)
        h[0][tx] = max(h[0][tx], tl);
      else
        h[1][tx] = max(h[1][tx], tl*3);
    }
    h1 = h3 = 0;
    for (int i = 0; i < 400000; i++)
    {
      h1 = max(h1, h[0][i]);
      h3 = max(h3, h[1][i]);
      S[i+1] = max(S[i+1], h1*2 - 1);
      S[i+1] = max(S[i+1], h3*2 - 3);
      h1 -= 1;
      h3 -= 3;
    }
    printf("Case #%d: %.6f\n", ka, calans()*1.0 / 32.0);
  }
  return 0;
}
