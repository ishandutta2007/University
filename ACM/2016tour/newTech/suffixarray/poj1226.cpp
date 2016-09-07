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

const int maxn = 1000020;
const int oo = 0x3f3f3f3f;

int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int n, sa[maxn], s[maxn], cnt, id[maxn], vis[200];
char bf[maxn];

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
  if (l == 0) return true;
  
  memset(vis, 0, sizeof(vis));
  
  for (int i = 0; i <= n; i++)
  {
    if (height[i] < l)
    {
      int j;
      for (j = 0; j < cnt; j++)
        if (vis[j] == 0) break;
      if (j == cnt) return true;
      
      memset(vis, 0, sizeof(vis));
      int tp = id[sa[i]];
      vis[tp] = 1;
    }
    else
    {
      vis[id[sa[i]]] = 1;
    }
  }
  return false;
}


int solve()
{
  int low = 0, high = 1200, mid;
  int ans = 0;
  while(low <= high)
  {
    mid = (low+high)/2;
    if (check(mid))
    {
      ans = max(ans, mid);
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return ans;
}


int main()
{
//  freopen("data.in", "r", stdin);


  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &cnt);
    
    if (cnt == 1)
    {
      scanf("%s", bf);
      printf("%d\n", strlen(bf));
      continue;
    }

    int nowpos = 0;
    int tt = 256;
    for (int i = 0; i < cnt; i++)
    {
      scanf("%s", bf);
      for(int j = 0, len = strlen(bf); j < len; j++)
      {
        id[nowpos] = i;
        s[nowpos++] = bf[j];
      }
      id[nowpos] = i;
      s[nowpos++] = tt++;
      for(int j = strlen(bf) - 1; j >= 0; j--)
      {
        id[nowpos] = i;
        s[nowpos++] = bf[j];
      }
      id[nowpos] = i;
      s[nowpos++] = tt++;
    }
    n = nowpos;
    s[n] = 0;
    da(s, sa, n+1, 400);
    calheight(s, sa, n);
   /*  
    for (int i = 0; i <= n; i++)
      printf("%d ", s[i]);
    printf("\n");


    for (int i = 0; i <= n; i++)
      printf("%d ", sa[i]);
    printf("\n");

 
    for (int i = 0; i <= n; i++)
      printf("%d ", id[i]);
    printf("\n");
    */

//    cout << check(2) << endl;



    printf("%d\n", solve());

  }
  return 0;
}
