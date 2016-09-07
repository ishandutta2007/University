#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cstdio>

using namespace std;
/*
 *  求最长回文字串
 *  O(n);
 *  Ma 为增加了分隔符之后的字符串
 *  Mp[i] 表示以i为中心的回文串的半径(包括自身)
 */
typedef long long ll;
typedef unsigned int ui;
const int maxn = 2000001;
const int oo = 1e9+7;
const int M = 249997;
map<ui, int> mp;
vector<string> vs;
char Ma[maxn*2];
int Mp[maxn*2];
char bf[maxn];
int n;
int tot, slen[maxn];


void manacher(string s, int len)
{
  int l = 0;
  Ma[l++] = '$';
  Ma[l++] = '#';
  for(int i = 0; i < len; i++)
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

bool check(int l, int r)
{
  if (l > r) return true;
  int len = r-l+1;
  l = 2*l + 2, r = 2*r + 2;
  int mid = (l+r) / 2;
  if (Mp[mid]-1 >= len) return true;
  else return false;
}
unsigned int BKDRHash(string str) 
{ 
  unsigned int seed=131 ;// 31 131 1313 13131 131313 etc..  
  unsigned int hash=0 ; 
  for (int i = 0, len = str.length(); i < len ; i++)
  { 
    hash=hash*seed+str[i]; 
  } 
  return(hash % M); 
} 
unsigned int BKDRHash(char* str) 
{ 
  unsigned int seed=31 ;// 31 131 1313 13131 131313 etc..  
  unsigned int hash=0 ; 
  while(*str) 
  { 
    hash=hash*seed+(*str++); 
  } 
  return(hash % M); 
} 
int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
#endif

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int x;
    scanf("%d%s",&slen[i] ,bf);
    vs.push_back(bf);
    ui ha = BKDRHash(bf);
    if(!mp.count(ha)) mp[ha] = 0;
    mp[ha] ++;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    manacher(vs[i], slen[i]);
    string tmp, pmt;
    for (int j = 0, len = slen[i]; j < len; j++)
    {
      tmp.push_back(vs[i][j]);
      pmt = vs[i][len-j-1] + pmt;
      ui hatmp, hapmt;
      
      hatmp = BKDRHash(tmp);
      hapmt = BKDRHash(pmt);

      if (j == len-1)
      {
        if (mp.count(hatmp))
          tot += mp[hatmp];
        if (mp.count(hapmt))
          tot += mp[hapmt];
      }
      else
      {
        if (check(j+1, len-1))
          if (mp.count(hatmp))
            ans += mp[hatmp];
        if (check(0, j))
          if (mp.count(hapmt))
            ans += mp[hapmt];
      }
    }
  }
  printf("%lld\n", ans + tot/2);
}
