#include <bits/stdc++.h>
#define next Nnext
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1200000;
const int maxm = 1200000;
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

int n;
bool check(int l)
{
  if (l == 0) return true;
  if (ex[0] < l || ex[n-l] < l) return false;
  for (int i = l; i + l <= n-l; i++)
    if (ex[i] >= l) return true;
  return false;
}
int solve()
{
  for (int i = n/3; i >= 0; i--)
    if (check(i)) return i;
  return 0;
}

int solve1()
{
  int mx = 0;
  int l = n / 3;
  int p1 = l, p2 = n - 2*l;
  for (int i = p1; i <= p2; i++)
    mx = max(mx, ex[i]);
  for (int i = l; i >= 0; i--)
  {
    if (ex[0] >= i && ex[n-i] >= i && mx >= i)
      return i;
    mx = max(mx, ex[--p1]);
    mx = max(mx, ex[++p2]);
    mx = max(mx, ex[++p2]);
    //cout << p1 << " " << p2 << endl;
  }
  return 0;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%s", s);
    strcpy(t, s);
    n = strlen(s);
    getExtend(t, s, ex);
//    cout << check(3) << endl;
    /*
    for (int i = 0; i < n; i++)
      printf("%d %d\n", ex[i], next[i]);
    */
    printf("%d\n", solve1());
  }
  return 0;
}
