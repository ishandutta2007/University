#include <bits/stdc++.h>
#define next Nnext
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 20000;
const int maxm = 20000;
int next[maxn], exst[maxn], exts[maxn];
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

int check(int len)
{
  for (int i = 0; i < len; i++)
  {
    if (i + exst[i] >= len)
    {
      int pos = len - i;
      if (pos + exts[pos] >= len)
        return 1;
    }
  }
  return 0;
}

int main()
{
  while(scanf("%s%s", s, t) != EOF)
  {
    int len = strlen(s);
    getExtend(s, t, exst);
    getExtend(t, s, exts);
    
    for (int i = 1; i <= len; i++)
      printf("%d", check(i));
    printf("\n");
  }
  return 0;
}
