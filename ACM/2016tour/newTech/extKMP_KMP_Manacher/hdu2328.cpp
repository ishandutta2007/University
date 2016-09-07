#include <bits/stdc++.h>
#define next Nnext
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1000000;
const int maxm = 1000000;
int next[maxn], ex[maxn];
char s[maxn], t[maxn];
char bf[4020][220];
int mlen, n;
string ans;


void getExtNext(const char *t, int *next)
{
  int lt = strlen(t);
  next[0] = lt;
  for (int i = 1, j = -1, a, p; i < lt; i++, j--) 
    if (j < 0 || i + next[i-a] >= p)
    {
      if (j < 0) j = 0, p = i;
      while(p < lt && t[j] == t[p]) j++, p++;
      next[i] = j, a = i;
    }
    else next[i] = next[i-a];
}
void getExtend(const char *s, const char *t, int *extend)
{
  int ls = strlen(s), lt = strlen(t);
  getExtNext(t, next);
  // a : 最长匹配的下标
  // p : s中最长匹配的位置+1
  for (int i = 0, j = -1, a, p; i < ls; i++, j--)
    if (j < 0 || i + next[i-a] >= p)
    {
      if (j < 0) j = 0, p = i;
      while(p < ls && j < lt && s[p] == t[j]) j++, p++;
      extend[i] = j, a = i;
    }
    else
      extend[i] = next[i-a];
}

void solve()
{
  int tlen = strlen(t);
  for (int i = 1; i < n; i++)
  {
    int tmp = 0;
    getExtend(bf[i], t, ex);
    for (int j = 0, len = strlen(bf[i]); j < len; j++)
      tmp = max(tmp, ex[j]);
    tlen = min(tlen, tmp);
  }
  if (tlen < mlen) return;
  string ts;
  for (int i = 0; i < tlen; i++)
    ts.push_back(t[i]);
  if (tlen > mlen)
  {
    mlen = tlen;
    ans = ts;
  }
  else
    ans = min(ans, ts);
}
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    if (n == 0) break;
    ans.clear();
    for (int i = 0; i < n; i++)
      scanf("%s", bf[i]);
    if (n == 1)
    {
      printf("%s\n", bf[0]);
      continue;
    }
    mlen = 0;
    for (int i = 0, len = strlen(bf[0]); i < len; i++)
    {
      strcpy(t, bf[0] + i);
      solve();
    }
    if (mlen == 0) printf("IDENTITY LOST\n");
    else cout << ans << endl;
  }
  return 0;
}
