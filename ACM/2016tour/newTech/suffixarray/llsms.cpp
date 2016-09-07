#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 200020;
const int oo = 0x3f3f3f3f;

int s[maxn], sa[maxn];
int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int len1, len2;
char str[maxn];
int n;

int cmp(int *r,int a,int b,int l)
{
  return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
  int i,j,p,*x=tta,*y=ttb,*t;
  for(i=0;i<m;i++) tts[i]=0;
  for(i=0;i<n;i++) tts[x[i]=r[i]]++;
  for(i=1;i<m;i++) tts[i]+=tts[i-1];
  for(i=n-1;i>=0;i--) sa[--tts[x[i]]]=i;
  for(j=1,p=1;p<n;j*=2,m=p)
  {
    for(p=0,i=n-j;i<n;i++) y[p++]=i;
    for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
    for(i=0;i<n;i++) wv[i]=x[y[i]];
    for(i=0;i<m;i++) tts[i]=0;
    for(i=0;i<n;i++) tts[wv[i]]++;
    for(i=1;i<m;i++) tts[i]+=tts[i-1];
    for(i=n-1;i>=0;i--) sa[--tts[wv[i]]]=y[i];
    for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
    x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
  }
  return;
}
void calheight(int *r,int *sa,int n)
{
  int i,j,k=0;
  for(i=1;i<=n;i++) Rank[sa[i]]=i;
  for(i=0;i<n;height[Rank[i++]]=k)
  for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
  return;
}

int solve()
{
  int ret = 0;
  for (int i = 2; i <= n; i++)
  {
    if ((sa[i] < len1 && sa[i-1] > len1) || (sa[i] > len1 && sa[i-1] < len1))
      ret = max(ret, height[i]);
  }
  return ret;
}

int main()
{
  while(scanf("%s", str) != EOF)
  {
    
    len1 = strlen(str);
    for (int i = 0; i < len1; i++)
      s[i] = str[i] - 'a' + 1;

    s[len1] = 28;
    scanf("%s", str);
    len2 = strlen(str);
    for (int i = 0; i < len2; i++)
      s[i + len1 + 1] = str[i] - 'a' + 1;
    n = len1 + len2 + 1;
    s[n] = 0;

    da(s, sa, n+1, 30);
    calheight(s, sa, n);
    printf("%d\n", solve());
  }
  return 0;
}
