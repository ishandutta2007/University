#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 20020;

int s[maxn];
int sa[maxn], n;
int low[maxn][33];
vector<int> h;
int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int k;
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

bool check(int x)
{
  int tmp = 0;
  for (int i = 0; i < n; i++)
  {
    if (height[i] >= x) tmp++;
    else tmp = 1;
    if (tmp >= k) return true;
  }
  return false;
}

int main()
{
  int N, K;
  scanf("%d%d", &N, &K);
  k = K;
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &s[i]);
    h.push_back(s[i]);
  }
  sort(h.begin(), h.end());
  for (int i = 0; i < N; i++)
    s[i] = lower_bound(h.begin(), h.end(), s[i]) - h.begin() + 1;
  s[N] = 0;
  n = N + 1;
  da(s, sa, N+1, n);
  calheight(s, sa, N);

  // int ans = 0;
  // int l = 1, r = n;
  // int mid;

  // while (l <= r)
  // {
  //   mid = (l + r)/2;
  //   if (check(mid))
  //   {
  //     ans = max(ans, mid);
  //     l = mid + 1;
  //   }
  //   else r = mid - 1;
  // }
  // printf("%d\n", ans);

  
  for (int i = 0; i < n; i++)
  {
    low[i][0] = height[i];
    // printf("%d ", low[i][0]);
  }
  // printf("\n");

  
  for (int j = 1; j <= 20; j++)
    for (int i = 0; i < n; i++) if (i + (1<<j) - 1 < n)
      low[i][j] = min(low[i][j-1], low[i+(1<<(j-1))][j-1]);

  int ans = 0;

  K--;
  int tk = log2(K);
  for (int i = 0; i + K - 1 < n; i++)
  {
    ans = max(ans, min(low[i][tk], low[i+K-1 - (1<<tk) + 1][tk]));
  }

  printf("%d\n", ans);
  

  return 0;
}
