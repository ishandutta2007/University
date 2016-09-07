#include <bits/stdc++.h>
#define next Nnext
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 180000;
int next[maxn], ex[maxn];
char s[maxn], t[maxn];
char sp[40], tsp[40];

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
//  freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  getchar();
  while(T--)
  {
    scanf("%s", tsp);
    scanf("%s", s);
    for (int i = 0; i < 26; i++)
      sp[tsp[i] - 'a'] = i + 'a';
    int len = strlen(s);
    for (int i = 0; i < len; i++)
      t[i] = tsp[s[i]-'a'];
    getExtend(t, s, ex);
/*
    for (int i = 0; i < len; i++)
      printf("%d ", ex[i]);
    printf("\n");
    for (int i = 0; i < len; i++)
      printf("%c", t[i]);
    printf("\n");
    for (int i = 0; i < len; i++)
      printf("%c", s[i]);
    printf("\n");

*/

    int pos, mid = len/2 + len%2;
    for (pos = 0; pos < len; pos++)
      if (pos >= mid && pos + ex[pos] >= len) break;
    

    for (int i = 0; i < pos; i++)
      printf("%c", s[i]);
    for (int i = 0; i < pos; i++)
      printf("%c", sp[s[i]-'a']);
    
    printf("\n");

  }
  return 0;
}
