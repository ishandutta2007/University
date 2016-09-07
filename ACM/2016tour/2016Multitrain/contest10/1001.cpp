#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int maxn = 100020;

typedef pair<int,int> pii;

int cnta, cntb, cntsum, cntab;
int a[maxn];
int n, m, pos;
pii seg1, seg2, seg12;

double cal(int r)
{
  if (r <= cnta)
    return a[r+seg1.X-1]*1.0;
  else if (r <= cnta + cntab*2 && cntab > 0)
  {
    int tmp = (r-cnta-1)/2;
    return a[seg12.X + tmp]*1.0;
  }
  else
  {
    int tmp = r-cnta-cntab*2;
    return a[seg2.X + tmp-1];
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    while(m--)
    {
      scanf("%d%d%d%d", &seg1.X,&seg1.Y,&seg2.X,&seg2.Y);
      if (seg1 > seg2) swap(seg1, seg2);

      cnta = seg1.Y-seg1.X+1;
      cntb = seg2.Y-seg2.X+1;
      cntab = seg1.Y-seg2.X+1;
      cntsum = cnta + cntb;
      if (cntab <= 0)
      {
        cntab = 0;
      }
      else
      {
        seg12.X = seg2.X;
        seg12.Y = seg1.Y;
        seg2.X = seg12.Y+1;
        cnta -= cntab;
        cntb -= cntab;
      }
      double ans = 0;
      if (cntsum%2 == 0)
      {
        ans = cal(cntsum/2) + cal(cntsum/2+1);
      }
      else
        ans = 2*cal(cntsum/2+1);
      printf("%.1f\n", ans/2);
    }
  }
  return 0;
}
