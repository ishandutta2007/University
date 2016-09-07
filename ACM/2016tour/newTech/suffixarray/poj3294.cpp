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
const int maxm = 120;
const int oo = 0x3f3f3f3f;

int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int pos[maxm];
int s[maxn], sa[maxn];
int cnt, n;
int vis[maxm];
int maxlen;

char bf[maxm][1020];

vector<string> ans;

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

bool check(int l)
{
  memset(vis, 0, sizeof(vis));
  int tmpcnt = 0;
  bool ret = false;
  vector<int> tmpans;
  for (int i = 0; i <= n; i++)
  {
    if (height[i] < l)
    {
      if (tmpcnt >= cnt/2 + 1)
      {
        // printf("tmpcnt = %d, i = %d\n", tmpcnt, i);
        // for (int k = 0; k < cnt; k++)
        //   printf("%d ", vis[k]);
        // printf("\n");
        ret = true;
        tmpans.push_back(sa[i-1]);
      }
      tmpcnt = 1;
      memset(vis, 0, sizeof(vis));
      vis[upper_bound(pos, pos+cnt, sa[i]) - pos] = 1;
    }
    else
    {
      int pp = upper_bound(pos, pos+cnt, sa[i]) - pos;
      if (vis[pp] == 0)
      {
        tmpcnt++;
        vis[pp] = 1;
      }
    }
  }
  if (ret && l > maxlen)
  {
    string bff;
    ans.clear();
    for (int i = 0, len = tmpans.size(); i < len; i++)
    {
      bff.clear();
      for (int j = 0; j < l; j++)
      {
        bff.push_back(s[tmpans[i] + j] + 'a' - 1);
      }
      ans.push_back(bff);
    }
    maxlen = max(maxlen, l);
  }
  return ret;
}

int solve()
{
  ans.clear();
  maxlen = 0;
  int low = 1, high = 1000, mid;
  while(low <= high)
  {
    mid = (low+high) / 2;
    if (check(mid))
    {
      maxlen = max(maxlen, mid);
      low = mid+1;
    }
    else
      high = mid-1;
  }
  return maxlen;
}

int main()
{
  // freopen("data.in", "r", stdin);
  bool fst = 1;
  while(scanf("%d", &cnt))
  {
    if (cnt == 0) break;
    if (fst)
      fst = false;
    else
      printf("\n");
    int nowpos = 0;
    for (int i = 0; i < cnt; i++)
    {
      scanf("%s", bf[i]);
      pos[i] = nowpos;
      for(int j = 0, len = strlen(bf[i]); j < len; j++)
        s[nowpos++] = bf[i][j] - 'a' + 1;
      s[nowpos++] = i + 30;
    }

    if (cnt == 1)
    {
      printf("%s\n", bf[0]);
      continue;
    }

    n = nowpos;
    s[n] = 0;
    da(s, sa, n+1, 150);
    // cout << "hello" << endl;
    calheight(s, sa, n);


    // for (int i = 0; i <= n; i++)
    //   printf("\t%d", s[i]);
    // cout << endl;


    // for (int i = 0; i <= n; i++)
    //   printf("\t%d", height[i]);
    // cout << endl;

    // for (int i = 0; i <= n; i++)
    //   printf("\t%d ", sa[i]);
    // cout << endl;

    // for (int i = 0; i <= n; i++)
    //   printf("\t%d ", upper_bound(pos, pos+cnt, sa[i]) - pos);
    // cout << endl;


    //cout << check(3) << endl;


    solve();

    // printf("maxlen = %d\n", maxlen);
    // printf("n = %d\n", n);
    if (ans.size() == 0) printf("?\n");
    else
    {
      sort(ans.begin(), ans.end());
      for (int i = 0, len = ans.size(); i < len; i++)
        cout << ans[i] << endl;
    }
  }
  return 0;
}
