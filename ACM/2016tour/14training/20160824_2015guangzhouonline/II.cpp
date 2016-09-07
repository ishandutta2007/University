#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
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

int query(int s, int e)
{
  int k = log2(e - s + 1);
  return min(low[s][k], low[e - (1 << k) + 1][k]);
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

ll sum[maxn], k;
vector<pii> sg, p;
char bf[maxn];

pii getpos(ll rk)
{
  int p1 = lower_bound(sum+1, sum+n+1, rk)-sum;
  int p2 = height[p1] + rk-sum[p1-1];
  return pii(p1,p2);
}

int cal()
{
  if (sg.size()==0) return 0;
  sort(sg.begin(), sg.end());
  int minR = oo;
  p.clear();
  for(int i=sg.size()-1;i>=0;i--)
  {
    if(minR<=sg[i].Y) continue;
    minR=sg[i].Y;
    p.push_back(sg[i]);
  }
  int ans=0,last=-1;
  sort(p.begin(), p.end());
  for(int i=0;i<p.size();i++)
  {
    if(last>=p[i].X) continue;
    ans++;
    last=p[i].Y;
  }
  return ans;
}

bool go(ll rk)
{
  pii pos = getpos(rk);
  sg.clear();
  int cur = pos.X, len = pos.Y;
  if (sa[cur]+len < n)
    sg.push_back(pii(sa[cur], sa[cur]+len-1));
  for (int i = cur+1; i <= n; i++)
  {
    len = min(len, height[i]);
    if (len == 0) return false;
    if (sa[i]+len<n)
      sg.push_back(pii(sa[i], sa[i]+len-1));
  }

  //return cal() < k;

  sort(sg.begin(), sg.end());
  
  int ans=0,last=-1;
  sort(sg.begin(), sg.end());
  for(int i=0;i<sg.size();i++)
  {
    if(last>=sg[i].X) continue;
    ans++;
    last=sg[i].Y;
  }

  return ans < k;

  for (int i = 0, l = sg.size(); i < l; i++)
  {
    if (sg[i].X < last) continue;
    if (sg[i].X + sg[i].Y != n) ans++;
    last = sg[i].X + sg[i].Y;
  }
  return ans < k;
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
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i-1] + (n-sa[i]) - height[i];
    ll ans = sum[n];
    ll low = 1, high = sum[n], mid;

    while(low<=high)
    {
      mid = (low+high)/2;
      //cout << low << " " << mid << " " << high << endl;
      if (go(mid))
      {
        ans = min(ans, mid);
        high = mid-1;
      }
      else
        low = mid+1;
    }
    /*
    printf("=============\n");
    cout << ans << endl;
    cout << go(ans) << endl;
    printf("=============\n");
    */
    pii tmp = getpos(ans);
    for (int i = 0; i < tmp.Y; i++)
      printf("%c", bf[sa[tmp.X]+i]);
    printf("\n");
  }
  return 0;
}

