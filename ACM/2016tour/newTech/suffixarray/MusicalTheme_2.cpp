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

const int maxn = 20020;
const int oo = 0x3f3f3f3f;

int tta[maxn],ttb[maxn],wv[maxn],tts[maxn];
int Rank[maxn],height[maxn];
int t[maxn];
int s[maxn];
int sa[maxn];
int n;
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


bool check(int x)
{
  int mmin = 0, mmax = 0;
  for (int i = 1; i <= n; i++)
  {
    if (height[i] >= x) 
    {
      mmin = min(mmin, sa[i]);
      mmax = max(mmax, sa[i]);
    }
    else
    {
      mmin = mmax = sa[i];
    }
    // cout << mmax << "   " << mmin << endl;
    if (mmax - mmin >= x + 1) return true;
  }
  return false;
}

int main()
{
  while(scanf("%d", &n) != EOF)
  {
    if (n == 0) break;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &t[i]);
      if (i > 0)
        s[i-1] = t[i] - t[i-1] + 89;
    }

    s[--n] = 0;
    da(s, sa, n+1, 200);
    calheight(s, sa, n);

    // build_sa(200);
    // getheight();
/*

    for (int i = 0; i <= n; i++)
      printf("%d ", s[i]);
    printf("\n");
    for (int i = 0; i <= n; i++)
      printf("%d %d\n", sa[i], height[i]);
*/

    int ans = 0;
    int l = 1, r = n+1;
    int mid;

    // cout << "hello" << endl;
    // cout << check(4) << endl;
    // cout << "hello" << endl;

    while (l <= r)
    {
      mid = (l + r)/2;
      if (check(mid))
      {
        ans = max(ans, mid);
        l = mid + 1;
      }
      else r = mid - 1;
    }

    // printf("[%d]\n", ans);
    if (ans < 4) printf("0\n");
    else printf("%d\n", ans + 1);
  }
  return 0;
}


/*

10 1 2 3 4 5 6 7 8 9 10

10
1 2 3 4 5 2 3 4 5 6

*/
