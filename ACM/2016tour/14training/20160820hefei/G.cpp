#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 1000200;
/*
 * getH(s, l, H)
 * 求从位置s开始长度为l的字符串的hash值
 * O(n) 预处理，O(1) 查询
 */
const ull xxx = 131;
ull H[maxn], HR[maxn], xl[maxn];
void prepre()
{
  xl[0] = 1;
  for (int i = 1; i < maxn; i++)
    xl[i] = xxx * xl[i-1];
}
void pre(char *str, ull *H)
{
  memset(H, 0, sizeof(H));
  int len = strlen(str);
  H[len] = 0;  
  for (int i = len-1; i >= 0; i--)
  {
    H[i] = H[i+1]*xxx + str[i];
  }
}

ull getH(int s, int l, ull *H)
{
  return H[s] - H[s+l] * xl[l];
}

// BKDR Hash Function
// 也可以将返回类型设为ull, 免去取模运算(&)
unsigned int BKDRHash(char *str)
{
  unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
  unsigned int hash = 0;
  while (*str)
  {
    hash = hash * seed + (*str++);
  }
  return (hash & 0x7FFFFFFF);
}
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
    low[i][0] = sa[i];
  for (int j = 1; j <= mxbit; j++)
    for (int i = 1; i <= n; i++) if (i + (1<<j) - 1 <= n)
      low[i][j] = min(low[i][j-1], low[i+(1<<(j-1))][j-1]);
}

int s[maxn];
char bf[maxn];

int cmp(int mid, int st, int l)
{
  int st1 = sa[mid], st2 = st;
  ull h1 = getH(st1, min(l, n-st1), H);
  ull h2 = getH(st2, min(l, n-st2), H);
  if (h1 == h2) return 0;
  int tmpsa = Rank[st];
  if (mid < tmpsa) return -1;
  else return 1;
/*
  for (int i = 0; i < l; i++)
    if (s[sa[mid]+i] < s[st+i])
      return -1;
    else if (s[sa[mid]+i] > s[st+i])
      return 1;
  return 0;
*/
}

int check(int l, int st)
{

  int low, high, mid;
  int anslow = oo, anshigh = -1;
  low = 0, high = n;
  while(low <= high)
  {
    mid = (low+high)/2;
    if (cmp(mid, st, l) == 0)
    {
      anslow = min(anslow, mid);
      high = mid-1;
    }
    else if (cmp(mid, st, l) > 0)
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
    if (cmp(mid, st, l) == 0)
    {
      anshigh = max(anshigh, mid);
      low = mid+1;
    }
    else if (cmp(mid, st, l) > 0)
    {
      high = mid-1;
    }
    else
      low = mid+1;
  }

  //printf("%d -- %d\n", anslow, anshigh);
  
  if (anslow > anshigh)
  {
    return -1;
  }
  else
  {
    int tmp = query(anslow, anshigh);
    if (tmp >= st) return -1;
    else return tmp;
  }
}

pii getans(int p)
{
  int len = -1, spos;
  int low = 0, high = n-p, mid;
  while(low <= high)
  {
    mid = (low+high) / 2;
    int tmppos = check(mid, p);
    if (tmppos >= 0)
    {
      if (mid > len)
      {
        len = mid;
        spos = tmppos;
      }
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return pii(len, spos);
}

int solve()
{
  int now = 0;
  pii tmp;
  while(now < n)
  {
    //printf("now = %d\n", now);
    tmp = getans(now);
    if (tmp.X <= 0)
    {
      printf("-1 %d\n", s[now] + 'a' - 1);
      now = now+1;
    }
    else
    {
      printf("%d %d\n", tmp.X, tmp.Y);
      now = now + tmp.X;
    }
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  
  int T;
  scanf("%d", &T);
  prepre();
  for (int ka = 1; ka <= T; ka++)
  {
    printf("Case #%d:\n", ka);
    scanf("%s", bf);
    n = strlen(bf);
    pre(bf, H);
    for (int i = 0; i < n; i++)
      s[i] = bf[i] - 'a' + 1;
    s[n] = 0;
    da(s, sa, n+1, 40);
    calheight(s, sa, n);
    rmqinit();
//    printf("ck = %d\n", check(4, 1));
    solve();
  }
  return 0;
}

