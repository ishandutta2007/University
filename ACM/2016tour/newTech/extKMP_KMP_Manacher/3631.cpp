#include <bits/stdc++.h>
using namespace std;

/*
 *  求最长回文字串
 *  O(n);
 *  Ma 为增加了分隔符之后的字符串
 *  Mp[i] 表示以i为中心的回文串的半径(包括自身)
 */
const int maxn = 600000;
const int oo = 1e9+7;
char Ma[maxn*2];
int Mp[maxn*2], v[30], sum[maxn];
char s[maxn];
void manacher(int len)
{
  int l = 0;
  Ma[l++] = '$';
  Ma[l++] = '#';
  for(int i = 0; i <len; i++)
  {
    Ma[l++] = s[i];
    Ma[l++] = '#';
  }
  Ma[l] = 0;
  int mx = 0, id = 0;
  for(int i = 0; i < l; i++)
  {
    Mp[i] = mx>i? min(Mp[2*id-i],mx-i):1;
    while(Ma[i+Mp[i]] == Ma[i-Mp[i]]) Mp[i]++;
    if(i+Mp[i]>mx)
    {
      mx = i + Mp[i];
      id = i;
    }
  }
}

int check(int l, int r)
{
  int len = r-l+1;
  l = 2*l + 2, r = 2*r + 2;
  int mid = (l+r) / 2;

  if (Mp[mid]-1 >= len) return true;
  else return false;
}

int main()
{
  //freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  while(T--)
  {
    for (int i = 0; i < 26; i++)
      scanf("%d", &v[i]);
    scanf("%s", s);
    int len = strlen(s);
    
    sum[0] = v[s[0]-'a'];
    for (int i = 1; i < len; i++)
      sum[i] = sum[i-1] + v[s[i]-'a'];

    manacher(len);
    int ans = -oo;


    for (int i = 0; i < len-1; i++)
      ans = max(ans, check(0, i)*sum[i] + check(i+1, len-1)*(sum[len-1]-sum[i]));
    printf("%d\n", ans);
  }
  return 0;
}
