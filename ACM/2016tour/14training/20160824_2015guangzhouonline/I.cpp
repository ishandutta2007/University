#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> pii;


/*
 * 后缀数组
 * dc3 的时间是 da的 3/4
 * da/dc3(int *r, int *sa, int n, int m);
 * n 为字符串的长度+1，m 为 r中值的范围
 *
 * calheight(int *r, int *sa, int n)
 * n 为字符串的长度
 *
 * r 数组为处理的串的int值
 * sa[i] 表示排名第i的后缀的起始下标
 * heigh[i] 表示排名第i的后缀于排名第 i-1 的后缀的最长公共前缀
 * Rank[i] 表示以i开始的后缀的排名
 *
 */
const int maxn = 100020;
const int oo = 0x3f3f3f3f;
int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int s[maxn], sa[maxn], n;
int low[maxn][22];

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

int k;
char bf[maxn];
vector<pii> sg;
int ans[maxn];

bool check(int len, int cur)
{
  int pos = cur;
  int low = 1, high = cur, mid;
  while(low <= high)
  {
    mid = (low+high)/2;
    if (mid == cur)
    {
      pos = min(pos, mid);
      high = mid-1;
    }
    else if (query(mid+1, cur) >= len)
    {
      pos = min(pos, mid);
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  //printf("lowpos = %d\n", pos);
  sg.clear();
  for (int i = pos; i <= cur; i++)
    sg.push_back(pii(sa[i], len));
  int tmp;
  if (cur+1 <= n)
    tmp = min(query(cur+1, n), len);
  else
    tmp = 0;
  for (int i = cur+1; i <= n; i++)
    sg.push_back(pii(sa[i], tmp));

  sort(sg.begin(), sg.end());
  //for (int i = 0, l = sg.size(); i < l; i++)
    //printf("|%d--%d|\n", sg[i].X, sg[i].Y);

  tmp = 0;
  int bk = -1;
  for (int i = 0, l = sg.size(); i < l; i++)
  {
    if (sg[i].X < bk) continue;
    if (sg[i].X + sg[i].Y != n) tmp++;
    bk = sg[i].X + sg[i].Y;
    //printf("tmp = %d\n", tmp);
  }
  return tmp+1 <= k;
}

int solve(int cur)
{
  int ret = n + 1;
  int low = 1, high = n-sa[cur], mid;
  while(low <= high)
  {
    int mid = (low+high)/2;
    if (check(mid, cur))
    {
      ret = min(ret, mid);
      high = mid-1;
    }
    else
      low = mid+1;
  }
  if (ret == n + 1)
    ret = -1;
  return ret;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif

  int len;
  while(scanf("%d", &k) != EOF)
  {
    if (k == 0) break;
    scanf("%s", bf);
    len = strlen(bf);
    for (int i = 0; i < len; i++)
      s[i] = bf[i] - 'a' + 1;
    s[len] = 0;
    n = len;
    da(s, sa, len+1, 28);
    calheight(s, sa, len);
    rmqinit();

    //cout << check(3, 6) << endl;
    //continue;


    /*
    ans[n] = solve(n);
    for (int i = 0; i < ans[n]; i++)
      printf("%c", bf[sa[n]+i]);
    printf("\n");
    continue;
    */
    for (int i = n; i > 0; i--) 
    {
      if (bf[sa[i]] == bf[sa[n]])
        ans[i] = solve(i);
      else
        ans[i] = -1;
    }
    /*
    for (int i = 0; i <= n; i++)
      printf("ans[%d] = %d\n",i, ans[i]);
      */
    int anslen = n+1;
    int anspos = 0;
    for (int i = 1; i <= n; i++) if (ans[i] != -1)
    {
      if (ans[i] < anslen)
      {
        anslen = ans[i];
        anspos = i;
      }
    }
    for (int i = 0; i < anslen; i++)
      printf("%c", bf[sa[anspos]+i]);
    printf("\n");
  }
  return 0;
}

