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

int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int s[maxn], sa[maxn], n, mpos;
int low[maxn][33];

char bf[maxn];

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
  return min(low[s][k], low[e-(1<<k)+1][k]);
}

int callen(int s1, int s2)
{
  int l = Rank[s1], r = Rank[s2];
  if (l > r) swap(l, r);
  return query(l+1, r);
}

int solve()
{
  for (int i = 0; i < mpos; i++)
  {
    int tlen = callen(i, mpos + 1);

//    printf("%d - %d : %d\n", i, mpos + 1, tlen);

    if (i + tlen >= mpos)
      return tlen;
  }
  return 1;
/*
  int low = 1, high = mpos, mid, ans = 1;
  while(low <= high)
  {
    mid = (low + mid) / 2;
    if (check(mid))
    {
      ans = max(ans, mid);
      low = mid + 1;
    }
    high = mid - 1;
  }
  return ans;
  */
}


int main()
{
//  freopen("data.in", "r", stdin);
  while(scanf("%s", bf) != EOF)
  {
    //printf("%s\n" , bf);
    int len = strlen(bf);
    mpos = len;
    for (int i = 0; i < len; i++)
      s[i] = bf[i];
    s[len] = '#';
    for (int i = len - 1, j = len + 1; i >= 0; i--)
      s[j++] = bf[i];
    n = 2*len + 1;

    s[n] = 0;

    da(s, sa, n+1, 256);
    calheight(s, sa, n);

    for (int i = 0; i <= n; i++)
      low[i][0] = height[i];
    for (int j = 1; j <= 20; j++)
      for (int i = 1; i <= n; i++) if (i + (1<<j) - 1 <= n)
        low[i][j] = min(low[i][j-1], low[i+(1<<(j-1))][j-1]);


    /*
    for (int i = 0; i <= n; i++)
      printf("%d ", s[i]);
    printf("\n");

    for (int i = 0; i <= n; i++)
      printf("%d ", sa[i]);
    printf("\n");

    for (int i = 0; i <= n; i++)
      printf("%d ", Rank[i]);
    printf("\n");
    */
    int plen = solve();
//    cout << plen << endl;
    printf("%s", bf);
    for (int i = len - plen - 1; i >= 0; i--)
      printf("%c", bf[i]);
    printf("\n");
  }
  return 0;
}
