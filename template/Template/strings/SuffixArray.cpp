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
const int maxn = 1000020;
const int oo = 0x3f3f3f3f;
int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
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

// dc3 算法
#define N 1000005  
#define MOD 1000000007  
#define F(x) ((x)/3+((x)%3==1?0:tb))  
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wsf[N],wa[N],wb[N],wv[N],sa[N],rank[N],height[N],f[N];  
int s[N],a[N];  
char str[N],str1[N],str2[N];  
//sa:字典序中排第i位的起始位置在str中第sa[i]  
//rank:就是str第i个位置的后缀是在字典序排第几  
//height：字典序排i和i-1的后缀的最长公共前缀  
int c0(int *r,int a,int b)  
{  
  return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];  
}  
int c12(int k,int *r,int a,int b)  
{  
  if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);  
  else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];  
}  
void sort(int *r,int *a,int *b,int n,int m)  
{  
  int i;  
  for(i=0; i<n; i++) wv[i]=r[a[i]];  
  for(i=0; i<m; i++) wsf[i]=0;  
  for(i=0; i<n; i++) wsf[wv[i]]++;  
  for(i=1; i<m; i++) wsf[i]+=wsf[i-1];  
  for(i=n-1; i>=0; i--) b[--wsf[wv[i]]]=a[i];  
  return;  
}  
void dc3(int *r,int *sa,int n,int m)  
{  
  int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;  
  r[n]=r[n+1]=0;  
  for(i=0; i<n; i++) if(i%3!=0) wa[tbc++]=i;  
  sort(r+2,wa,wb,tbc,m);  
  sort(r+1,wb,wa,tbc,m);  
  sort(r,wa,wb,tbc,m);  
  for(p=1,rn[F(wb[0])]=0,i=1; i<tbc; i++)  
    rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;  
  if(p<tbc) dc3(rn,san,tbc,p);  
  else for(i=0; i<tbc; i++) san[rn[i]]=i;  
  for(i=0; i<tbc; i++) if(san[i]<tb) wb[ta++]=san[i]*3;  
  if(n%3==1) wb[ta++]=n-1;  
  sort(r,wb,wa,ta,m);  
  for(i=0; i<tbc; i++) wv[wb[i]=G(san[i])]=i;  
  for(i=0,j=0,p=0; i<ta && j<tbc; p++)  
      sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];  
  for(; i<ta; p++) sa[p]=wa[i++];  
  for(; j<tbc; p++) sa[p]=wb[j++];  
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

int main()
{
  s[len] = 0;
  da(s, sa, len+1, 256);
  calheight(s, sa, len);
  return 0;
}
