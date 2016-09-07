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
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 200020;
const int oo = 0x3f3f3f3f;

int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int s[maxn], sa[maxn];
int k;
int len1, len2, n;
char bf[maxn];


ll stk[maxn], top, sum[maxn], cnt[maxn];


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


ll solve(int func)
{
  ll ret = 0;
  int tcnt = 0;
  sum[0] = 0, top = 0, cnt[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    tcnt = 0;
    while(top > 0 && stk[top] > height[i])
      tcnt += cnt[top--];

    if (tcnt > 0 && height[i] >= k)
    {
      stk[++top] = height[i];
      cnt[top] = tcnt;
      sum[top] = sum[top-1] + ((ll)height[i] - k + 1)*tcnt;
    }
    if ((sa[i]>len1) ^ func)
    {
      stk[++top] = maxn;
      cnt[top] = 1;
    }
    else
      ret += sum[top];
  }
  return ret;
}

int main()
{
  while(scanf("%d", &k))
  {
    if (k == 0) break;
    scanf("%s", bf);
    len1 = strlen(bf);
    for (int i = 0; i < len1; i++)
      s[i] = bf[i];
    s[len1] = '#';
    scanf("%s", bf);
    len2 = strlen(bf);
    for (int i = 0; i < len2; i++)
      s[i+len1+1] = bf[i];
    n = len1 + len2 + 1;
    s[n] = 0;
    da(s, sa, n + 1, 128);
    calheight(s, sa, n);
    printf("%I64d\n", solve(0) + solve(1));
  }
  return 0;
}
