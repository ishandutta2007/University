#include <bits/stdc++.h>
#define next Nnext
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 300000;
const int oo = 10007;
int next[maxn], ex[maxn];
char s[maxn], t[maxn];

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

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    strcpy(t, s);
    getExtend(s, t, ex);
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = (ans + ex[i]) % oo;
    printf("%d\n", ans);
  }
  return 0;
}

