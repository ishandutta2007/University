#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
 *  求最长回文字串
 *  O(n);
 *  Ma 为增加了分隔符之后的字符串
 *  Mp[i] 表示以i为中心的回文串的半径(包括自身)
 */
const int maxn = 2100000;
int len[maxn*2];
char s[maxn*2];
char bf[maxn];

int inits(char *s, char *str)
{
  int l = 0;
  s[l++] = '$';
  s[l++] = '#';
  for (int i = 0, len = strlen(str); i < len; i++)
  {
    s[l++] = str[i]; s[l++] = '#';
  }
  s[l] = '\0';
  return l;
}
void manacher(char *s)
{
  int mx = 0, id = 0, l = strlen(s);
  for(int i = 0; i < l; i++)
  {
    len[i] = mx>i? min(len[2*id-i],mx-i):1;
    while(s[i+len[i]] == s[i-len[i]]) len[i]++;
    if(i+len[i]>mx)
    {
      mx = i + len[i];
      id = i;
    }
  }
}
int main()
{
  while(scanf("%s", bf) != EOF)
  {
    int l = inits(s, bf);
    manacher(s);
    int ans = 0;
    for(int i = 0; i < l; i++)
    {
      ans = max(ans, len[i]-1);
      // printf("%d ", len[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
