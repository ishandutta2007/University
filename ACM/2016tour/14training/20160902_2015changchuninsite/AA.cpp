#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
const int p50 = 5, p500 = 8;
int v[15]={0,1,5,10,20,50,100,200,500,1000,2000};
int c[15]={0,1,5,10,20,50,100,200,500,1000,2000};
ll cnt[15];
bool r50, r500;
int p;
ll num[12];
int use[12];

bool check(int r, int st)
{
  memset(use, 0, sizeof(use));
  if (r < 0) return false;
  int tmp = r, x;
  for (int i=st;i>=1;i--)
  {
    int x=min((int)cnt[i],tmp/c[i]);
    tmp=tmp-c[i]*x;
    use[i] = x;
    if (tmp==0) break;
  }
  if (tmp == 0) return true;
  else return false;
}

bool check1(int r)
{
  memset(use, 0, sizeof(use));
  if (r < 0) return false;
  
  int tmp = r, x;
  for (int i = 1; i <= 10; i++)
  {
    
  }

}

int solve(int r)
{
  if (!check(r, 10)) return -1;
  int ans = 0;
  for (int i = 10; i >= 2; i--)
  {
    int delta = cnt[i] - num[i];
    if (v[i] != 1000 && v[i] != 100)
    {
      if (use[i] > delta)
      {
        ans += use[i] - delta;
      }
      use[i-1] += min(delta, use[i]) * v[i]/v[i-1];
      cnt[i-1] += delta * v[i]/v[i-1];
    }
    else
    {
      if (use[i] > delta)
      {
        ans += use[i] - delta;
      }
      use[i-1] += min(delta, use[i]) * 2;
      use[i-2] += min(delta, use[i]) * 1;
      cnt[i-1] += delta * 2;
      cnt[i-2] += delta * 1;
    }
  }
  ans += use[1];
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
    {
			scanf("%d",&num[i]);
      cnt[i] = num[i];
    }

    /*
    for (int i = 1; i <= 10; i++)
    {
      printf("%d %lld\n", v[i], num[i]);
    }
    */
    for (int i=1;i<10;i++)
    {
      if (v[i] != 20 && v[i] != 200)
      {
        cnt[i+1] += cnt[i]/(v[i+1]/v[i]);
        cnt[i] = cnt[i]%(v[i+1]/v[i]);
      }
      else
      {
        if (cnt[i] >= 2 && cnt[i-1] >= 1)
        {
          cnt[i-1] -= 1;
          cnt[i] -=2;
          cnt[i+1] += 1;
        }
        cnt[i+2] += cnt[i]/(v[i+2]/v[i]);
        cnt[i] = cnt[i]%(v[i+2]/v[i]);
      }
    }

    for (int i = 1; i <= 10; i++)
    {
      printf("%d %lld\n", v[i], cnt[i]);
    }


    int ans = solve(p);
    printf("%d\n", ans);
	}	
  return 0;
}

