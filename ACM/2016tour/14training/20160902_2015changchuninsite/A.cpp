#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
const int p50 = 5, p500 = 8;
int v[15]={0,1,5,10,20,50,100,200,500,1000,2000};
int c[15]={0,1,5,10,20,100,200,1000,2000};
int cnt[15];

long long sum[15];

bool r50, r500;

int p;
int now[12],num[12];
int bf[12];

int x;
bool check(int r, int st)
{
  if (r < 0) return false;
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

int bi(int r, int st)
{
  int ret = bf[st];
  int low = 0, high = bf[st], mid;
  //int ret = cnt[st];
  //int low = 0, high = cnt[st], mid;
  while(low <= high)
  {
    mid = (low + high)/2;
    if (check(r-mid*c[st], st-1))
    {
      ret = min(ret, mid);
      high = mid-1;
    }
    else
      low = mid+1;
  }
  return ret;
}

int solve(int r)
{
  if (!check(r, 8)) return -1;
  int ans = 0;
  int now;
  for (int i = 8; i >= 2; i--)
  {
    now = bi(r, i);
    //printf("%d : %d, %d\n", c[i] , now, r);
    r -= now*c[i];
    if (c[i] == 1000)
    {
      int tmp = min(now*2, num[p500]);
      now = now - tmp/2;
      ans += now + tmp;
    }
    if (c[i] == 100)
    {
      int tmp = min(now*2, num[p50]);
      now = now-tmp/2;
      ans += now+tmp;
    }
    else
      ans += now;
  }
  ans += r;
  return ans;
}
int solve1(int r)
{
  if (!check(r, 8)) return -1;
  
  for (int i = 1; i <= 8; i++)
  {
    printf("%d %d\n", c[i], bf[i]);
  }

  int ans = 0;
  ll now;
  for (int i = 8; i >= 2; i--)
  {
    now = bf[i];
    ll tmp = sum[i-1] / c[i];
    if (now > tmp)
    {
      ans += now -tmp;
      bf[i-1] += tmp * v[i]/v[i-1];
    }
    else
    {
      bf[i-1] += now * v[i]/v[i-1];
    }
  }
  ans += bf[1];
  ll tmp = min(bf[5]*2, num[p50]);
  bf[5] = bf[5]-tmp/2;
  ans += tmp/2;
  tmp = min(bf[7]*2, num[p500]);
  bf[7] = bf[7]-tmp/2;
  ans += tmp/2;
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
    
    sum[0] = 0;
    for (int i = 1; i <= 8; i++)
    {
      sum[i] = sum[i-1] + c[i]*cnt[i];
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
          int tmp = solve1(p-i*50-j*500);
          if (tmp != -1)
          {
            ans = max(ans, tmp+i+j);
          }
        }
    printf("%d\n", ans);
	}	
  return 0;
}

