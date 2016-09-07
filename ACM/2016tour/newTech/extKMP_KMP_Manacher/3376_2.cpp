#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
const int maxn = 2000001;
const int oo = 1e9+7;
const ui M = 249997;
map<ull, ll> mp;
vector<string> vs;
char Ma[maxn*2];
int Mp[maxn*2];
char s[maxn], bf[maxn];
int n;
int slen[maxn], st[maxn];
char src[maxn], rsrc[maxn];

void manacher(char *s, int bg, int len)
{
  int l = 0;
  Ma[l++] = '$';
  Ma[l++] = '#';
  for(int i = 0; i < len; i++)
  {
    Ma[l++] = s[i+bg];
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

bool check(int l, int r)
{
  if (l > r) return true;
  int len = r-l+1;
  l = 2*l + 2, r = 2*r + 2;
  int mid = (l+r) / 2;
  if (Mp[mid]-1 >= len) return true;
  else return false;
}

const ull xxx = 131;
ull H[maxn], HR[maxn], xl[maxn];
void prepre()
{
  xl[0] = 1;
  for (int i = 1; i < maxn; i++)
    xl[i] = xxx * xl[i-1];
}
void pre(char *str, ull *H)
{
  memset(H, 0, sizeof(H));
  int len = strlen(str);
  H[len] = 0;  
  for (int i = len-1; i >= 0; i--)
  {
    H[i] = H[i+1]*xxx + str[i];
  }
}

ull getH(int s, int l, ull *H)
{
  return H[s] - H[s+l] * xl[l];
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  prepre();
  scanf("%d", &n);
  int pos = 0;
  for (int i = 0; i < n; i++)
  {
    st[i] = pos;
    scanf("%d%s",&slen[i] ,src+pos);
    pos += slen[i];
    for (int j = 0; j < slen[i]; j++)
      rsrc[st[i]+j] = src[st[i] + slen[i] - 1 - j];
    src[pos] = rsrc[pos] = 0;
  }
  //printf("%s\n%s\n", src, rsrc);
  pre(src, H);
  pre(rsrc, HR);
  for (int i = 0; i < n; i++)
  {
    ull ha = getH(st[i], slen[i], H);
    if (!mp.count(ha)) mp[ha] = 0;
    mp[ha]++;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    int len = slen[i]; 
    manacher(src, st[i], len);
    for (int j = 0; j < len; j++)
    {
      ull hapmt = getH(st[i] + 0, len-j-1, HR);
      ull hatmp = getH(st[i] + len - j - 1, j+1, HR);
      if (check(j+1, len-1))
        if (mp.count(hatmp))
          ans += mp[hatmp];
      if (check(0, j))
        if (mp.count(hapmt))
          ans += mp[hapmt];
    }
  }
  printf("%lld\n", ans);
}

