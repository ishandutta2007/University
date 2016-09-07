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

const int maxn = 1000020;
const int oo = 0x3f3f3f3f;

int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int s[maxn], sa[maxn];
int n, low[maxn][33];
char bf[10];

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
  return query(l+1, r);
}

int main()
{
  int T;
  scanf("%d", &T);

  while (T--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%s", bf);
      s[i] = bf[0];
    }
    s[n] = 0;
    da(s, sa, n+1, 128);
    calheight(s, sa, n);

    for (int i = 0; i <= n; i++)
      low[i][0] = height[i];
    for (int j = 1; j <= 20; j++)
      for (int i = 1; i <= n; i++) if (i + (1<<j) - 1 <= n)
        low[i][j] = min(low[i][j-1], low[i+(1<<(j-1))][j-1]);
    int ans = 1;
    for (int l = 1; l <= n/2; l++)
    {
      for (int s1 = 0, s2 = l; s2 < n; s1 += l, s2 += l)
      {
        int tmplen = callen(s1, s2);
        ans = max(ans, tmplen/l + 1);
        if (tmplen % l)
        {
          int tmp = l - tmplen % l;
          if (s1 - tmp >= 0)
            ans = max(ans, callen(s1-tmp, s2-tmp)/l + 1);
        }
      }
    }

    printf("%d\n", ans);

  }
  return 0;
}
