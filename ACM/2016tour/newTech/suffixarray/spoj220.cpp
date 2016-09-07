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

const int maxn = 1000020, maxm = 20;
const int oo = 0x3f3f3f3f;

int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int cnt, n;
int s[maxn], sa[maxn], id[maxn];
char bf[maxn];

int mmax[maxm], mmin[maxm];

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


bool check(int l)
{
  if (l == 0) return true;
  memset(mmax, -1, sizeof(mmax));
  memset(mmin, 0x3f, sizeof(mmin));

  for (int i = 0; i <= n; i++)
  {
    if (height[i] < l)
    {
      bool ok = true;
      for (int j = 0; j < cnt; j++)
      {
        if (mmax[j] - mmin[j] < l) ok = false;
      }
      if (ok) return true;
      memset(mmax, -1, sizeof(mmax));
      memset(mmin, 0x3f, sizeof(mmin));
      int tp = id[sa[i]];
      mmax[tp] = max(mmax[tp], sa[i]);
      mmin[tp] = min(mmin[tp], sa[i]);
    }
    else
    {
      int tp = id[sa[i]];
      mmax[tp] = max(mmax[tp], sa[i]);
      mmin[tp] = min(mmin[tp], sa[i]);
    }
  }
  return false;
}

int solve()
{
  int low = 0, high = maxn, mid;
  int ans = 0;
  while(low <= high)
  {
    mid = (low + high) / 2;
    // printf("[%d]\n", mid);
    if (check(mid))
    {
      ans = max(ans, mid);
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return ans;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
  #endif

  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &cnt);
    if (cnt == 0)
    {
      printf("0\n");
      continue;
    }
    int nowpos = 0;
    for (int i = 0; i < cnt; i++)
    {
      scanf("%s", bf);
      for(int j = 0, len = strlen(bf); j < len; j++)
      {
        id[nowpos] = i;
        s[nowpos++] = bf[j] - 'a' + 1;
      }
      id[nowpos] = i;
      s[nowpos++] = i + 30;
    }
    n = nowpos;
    s[n] = 0;
    da(s, sa, n+1, 50);
    calheight(s, sa, n);
    printf("%d\n", solve());
  }

  return 0;
}


