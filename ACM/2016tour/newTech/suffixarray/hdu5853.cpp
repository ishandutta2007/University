#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000020;
const int oo = 0x3f3f3f3f;
int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int low[maxn][30];
int n, sa[maxn];
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

// 查询[s, e](排名)区间中最小的height值
// 即s-1 与 e 的最长公共前缀的长度
int query(int s, int e)
{
  int k = log2(e - s + 1);
  return min(low[s][k], low[e - (1 << k) + 1][k]);
}

// 查询s1, s2开始的后缀的最长公共前缀的长度
// 注意s1 != s2
int callen(int s1, int s2)
{
  int l = Rank[s1], r = Rank[s2];
  if (l > r) swap(l, r);
  return query(l+1, r);
}
void rmqinit()
{
  int mxbit = 20;
  for (int i = 0; i <= n; i++)
    low[i][0] = height[i];
  for (int j = 1; j <= mxbit; j++)
    for (int i = 1; i <= n; i++) if (i + (1<<j) - 1 <= n)
      low[i][j] = min(low[i][j-1], low[i+(1<<(j-1))][j-1]);
}

char bf[maxn];
int s[maxn], a[maxn];
int bflen;
int maxlen[maxn];

int cmp(int mid)
{
  for (int i = 0; i < bflen; i++)
    if (s[sa[mid]+i] < a[i])
      return -1;
    else if (s[sa[mid]+i] > a[i])
      return 1;
  return 0;
}


int solve()
{
  scanf("%s", bf);
  bflen = strlen(bf);
  for (int i = 0; i < bflen; i++)
    a[i] = bf[bflen-i-1]-'a'+1;
  
  int low, high, mid;
  int anslow = oo, anshigh = -1;
  
  low = 0, high = n;
  while(low <= high)
  {
    mid = (low+high)/2;
    if (cmp(mid) == 0)
    {
      anslow = min(anslow, mid);
      high = mid-1;
    }
    else if (cmp(mid) > 0)
    {
      high = mid-1;
    }
    else
      low = mid+1;
  }
  
  low = 0, high = n;
  while(low <= high)
  {
    mid = (low+high)/2;
    if (cmp(mid) == 0)
    {
      anshigh = max(anshigh, mid);
      low = mid+1;
    }
    else if (cmp(mid) > 0)
    {
      high = mid-1;
    }
    else
      low = mid+1;
  }

  if (anslow > anshigh) return 0;
  int mx = maxlen[sa[anslow]];
  if (anslow+1 <= anshigh)
    mx = min(mx, query(anslow+1, anshigh));
  int mi = 0;
  if (anslow > 0) mi = max(mi, query(anslow, anslow));
  if (anshigh <= n) mi = max(mi, query(anshigh+1, anshigh+1));
  return mx - mi;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
  int len, cnt, m;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    len = 0;
    scanf("%d%d", &cnt,&m);
    for (int i = 0; i < cnt; i++)
    {
      scanf("%s", &bf);
      int tlen = strlen(bf);
      for(int j = tlen-1; j >= 0; j--)
      {
        maxlen[len] = tlen--;
        s[len++] = bf[j]-'a'+1;
      }
      s[len++] = i+27;
    }
    s[len] = 0;
    n = len;
    da(s, sa, len+1, 26+cnt+1);
    calheight(s, sa, len);
    rmqinit();
    printf("Case #%d:\n", ka);
    while(m--)
    {
      printf("%d\n", solve());
    }
  }
  return 0;
}

