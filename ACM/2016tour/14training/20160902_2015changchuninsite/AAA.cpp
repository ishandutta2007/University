#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
const int p50 = 5, p500 = 8;
int v[15]={0,1,5,10,20,50,100,200,500,1000,2000};
int c[15]={0,1,5,10,20,100,200,1000,2000};
int cnt[15];
int re[15];
long long sum[15];

bool r50, r500;

int p;
int now[12],num[12];
int bf[12];

int x;
bool check(int r, int st)
{
  if (r < 0) return false;
  memset(bf, 0, sizeof(bf));
  int tmp = r;
  for (int i=st;i>=1;i--)
  {
    int x=min(cnt[i],tmp/c[i]);
    tmp=tmp-c[i]*x;
    bf[i] = x;
    if (tmp==0) break;
  }
  if (tmp == 0) return true;
  else return false;
}

int solve(int r)
{
  printf("solve (%d) :\n", r);
  if (r == 0) return 0;
  if (!check(r, 8)) return -1;
  for (int i = 1; i <= 8; i++)
  {
    re[i] = cnt[i] - bf[i];
  }
  printf("--------\n");
  for (int i = 1; i <= 8; i++)
    printf("%d %d,%d,%d\n", c[i], bf[i],re[i],cnt[i]);
  printf("--------\n");
  
  for (int i = 8; i >= 2; i--)
  {
    for (int j = 1; j < i; j++)
    {
      int cg = c[i]/c[j];
      int tmp = min(bf[i], re[j]/cg);
      bf[i] -= tmp;
      re[i] += tmp;
      bf[j] += tmp*cg;
      re[j] -= tmp*cg;
    }
  }
  for (int i = 1; i <= 8; i++)
  {
    printf("%d %d,%d,%d\n", c[i], bf[i],re[i],cnt[i]);
  }

  int ans = 0;
  for (int i = 1; i <= 8; i++)
  {
    if (c[i] == 100)
    {
      int tmp = min(bf[i]*2, num[p50]);
      bf[i] -= tmp/2;
      ans += bf[i] + tmp;
      printf("use50 = %d\n", tmp);
      int r1 = re[3], r2 = re[4];
      int tt = min(r2/2,min(tmp, r1));
      ans += tt*2;
    }
    else if (c[i] == 1000)
    {
      int tmp = min(bf[i]*2, num[p500]);
      bf[i] -= tmp/2;
      ans += bf[i] + tmp;
      printf("use500 = %d\n", tmp);
      int r1= re[6], r2= re[7];
      int tt =min(r2/2, min(tmp, r1));
      ans += tt*2;
    }
    else
      ans += bf[i];
  }
  return ans;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
	scanf("%d",&T);
  while(T--)
	{
		scanf("%d",&p);
		for (int i=1;i<=10;i++)
			scanf("%d",&num[i]);
    if (p == 0)
    {
      printf("0\n");
      continue;
    }
    int tp = 1;
    memset(cnt, 0, sizeof(cnt));
    for (int i=1;i<=10;i++)
    {
      if (v[i] != 50 && v[i] != 500)
        cnt[tp++] += num[i];
      else
        cnt[tp] += num[i]/2;
    }
    
    r50 = num[5]%2;
    r500 = num[8]%2;
    num[p50] -= r50;
    num[p500] -= r500;

    int ans = -1;
    for (int i = 0; i <= r50; i++)
      for (int j = 0; j <= r500; j++)
        if (p-i*50-j*500 >=0)
        {
          int tmp = solve(p-i*50-j*500);
          if (tmp != -1)
          {
            ans = max(ans, tmp+i+j);
          }
        }
    printf("%d\n", ans);
	}	
  return 0;
}

