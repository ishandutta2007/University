#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 50020;

char str[maxn];
int s[maxn];
int sa[maxn], n;
int Rank[maxn], height[maxn];
int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
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


int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%s", &str);
    n = strlen(str);
    for (int i = 0; i < n; i++)
      s[i] = str[i];
    s[n] = 0;
    da(s, sa, n+1, 128);
    calheight(s, sa, n);
    // build_sa(128);
    // getheight();
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
      ans += n - sa[i] - height[i];
    }
    cout << ans << endl;
  }
  return 0;
}
