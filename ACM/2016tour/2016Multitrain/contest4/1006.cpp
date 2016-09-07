#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 200020;

char str[maxn], ch, bf[10]; int s[maxn];
int sa[maxn], n;
int Rank[maxn], height[maxn];
int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int sum[maxn];
int low[maxn][33];
int lp[maxn];


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
  int k = log(e-s+1);
  return min(low[s][k], low[e-(1<<k)+1][k]);
}


int main()
{

//  freopen("data.in", "r", stdin);

  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%s", bf);
    ch = bf[0];
    scanf("%s", &str);
    n = strlen(str);
    memset(sum, 0, sizeof(sum));

//    printf("%s %c\n", str, ch);

    for (int i = 0; i < n; i++)
      s[i] = str[i];

    lp[n] = -1;

    for (int i = n-1; i>=0; i--)
    {
      if (i == n-1) sum[i] = (str[i] == ch);
      else sum[i] = sum[i+1] + (str[i] == ch);
      if (str[i] != ch)
        lp[i] = lp[i+1];
      else
        lp[i] = i;
    }
    s[n] = 0;
    da(s, sa, n+1, 128);
    calheight(s, sa, n);
    
    memset(low, 0, sizeof(low));
    for (int i = 0; i <= n; i++)
      low[i][0] = height[i];
    for (int j = 1; j <= 20; j++)
      for (int i = 1; i <= n; i++) if (1 + (1<<j) - 1 <= n)
        low[i][j] = min(low[i][j-1], low[i+(1<<(j-1))][j-1]);
    // build_sa(128);
    // getheight();
    long long ans = 0;

/*
    for (int i = 0; i <= n; i++)
    {
      printf("%d ", sa[i]);
    }
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
      printf("%d ", sum[i]);
    }
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
      printf("%d ", height[i]);
    }
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
      printf("%d ", lp[i]);
    }
    printf("\n");
*/
    int pre = -1;
    for (int i = 1; i <= n; i++)
    {
//      printf("[%d]\n", sa[i]);
      if (sum[sa[i]] == 0) continue;
      if (pre == -1)
      {
        ans += n - sa[i] - (lp[sa[i]] - sa[i]);
        pre = i;
      }
      else
      {
        int tmp = query(pre + 1, i);

        ans += n - sa[i] - max(lp[sa[i]] - sa[i], tmp);
//        if (tmp == 0) ans += n - sa[i] - (lp[sa[i]] - sa[i]);
//        else ans += n - sa[i] - tmp;
//        ans += n - sa[i] - query(pre + 1, i);
        pre = i;
      }
//      printf("%d %d %d sa : %d\n",i, ans, pre, sa[i]);
    }
    printf("Case #%d: %I64d\n", ka, ans);
  }
  return 0;
}
