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

const int maxn = 2020;
const int oo = 0x3f3f3f3f;

int s[maxn], sa[maxn];
int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int len1, len2;
char str[maxn];
int n, low[maxn][33];

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
int query(int s, int e)
{
  int k = log2(e - s + 1);
  return min(low[s][k], low[e - (1 << k) + 1][k]);
}

int callen(int s1, int s2)
{
  int l = Rank[s1], r = Rank[s2];
  if (l > r) swap(l, r);

  // printf("(%d, %d, %d)\n", s1, s2, query(l+1, r));

  return query(l+1, r);
}
int solve()
{
  int mid = 0, l = 1;

  for (int i = 0; i < len1; i++)
  {
    int t1 = 0;
    if (i+1 < len1) t1 = callen(i+1, 2*len1-i + 1) * 2 + 1;
    int t2 = callen(i, 2*len1-i + 1) * 2;
    if (l < max(t1,t2))
    {
      mid = i, l = max(t1, t2);
    } 
  }

  // printf("%d %d\n", mid, l);

  int start = mid - l/2;
  for (int i = 0; i < l; i++)
    printf("%c", str[i+start]);
  printf("\n");
}

int main()
{
  while(scanf("%s", str) != EOF)
  {
    len2 = len1 = strlen(str);
    for (int i = 0; i < len1; i++)
      s[i] = str[i];
    s[len1] = 0;
    for (int i = 0; i < len2; i++)
      s[i + len1 + 1] = str[len2 - i - 1];
    n = len1 + len2 + 1;
    s[n] = 1;
    da(s, sa, n+1, 128);
    calheight(s, sa, n);

    for (int i = 0; i <= n; i++)
      low[i][0] = height[i];
    for (int j = 1; j <= 20; j++)
      for (int i = 1; i <= n; i++) if (i + (1<<j) - 1 <= n)
        low[i][j] = min(low[i][j-1], low[i+(1<<(j-1))][j-1]);

    solve();
  }
  return 0;
}
