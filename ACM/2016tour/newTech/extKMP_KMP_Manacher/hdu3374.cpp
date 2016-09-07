#include <bits/stdc++.h>
#define X first
#define Y second
#define next Nnext
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2100000;
const int maxm = 2100000;

char str[maxn], bf[maxn];

pii minstr(char *s)
{
  int l = strlen(s);
  for (int i = 0; i < l; i++) s[i+l] = s[i];
  s[2*l] = 0;
  int i = 0, j = 1;
  while(i < l && j < l)
  {
    int k = 0;
    while(s[i+k] == s[j+k] && k < l) k++;
    if (k == l)
      return pii(min(i, j), l/(abs(i-j)));
    else if(s[i+k] > s[j+k]) i = max(i+k+1, j+1);
    else j = max(j+k+1, i+1);
  }
  return pii(min(i, j), 1);
}

pii maxstr(char *s)
{
  int l = strlen(s);
  for (int i = 0; i < l; i++) s[i+l] = s[i];
  s[2*l] = 0;
  int i = 0, j = 1;
  while(i < l && j < l)
  {
    int k = 0;
    while(s[i+k] == s[j+k] && k < l) k++;
    if (k == l)
      return pii(min(i, j), l/(abs(i-j)));
    else if(s[i+k] < s[j+k]) i = max(i+k+1, j+1);
    else j = max(j+k+1, i+1);
  }
  return pii(min(i, j), 1);
}


int main()
{
//  freopen("data.in", "r", stdin);
  pii pmax, pmin;
  while(scanf("%s", bf)!=EOF)
  {
    strcpy(str, bf);
    pmin = minstr(str);
    strcpy(str, bf);
    pmax = maxstr(str);
    printf("%d %d %d %d\n", pmin.X + 1, pmin.Y, pmax.X + 1, pmax.Y);

  }
  return 0;
}
