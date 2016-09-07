#include <bits/stdc++.h>
#define maxn 1200
#define X first
#define Y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
vector<pll> pot;

LL frac[1200000];
const LL oo=110119;
LL exp_mod(LL a, LL b, LL p)
{
  LL res = 1;
  while(b != 0) {
    if(b&1) res = (res * a) % p;
    a = (a*a) % p;
    b >>= 1;
  }
  return res;
}

LL Comb(LL a, LL b, LL p)
{
  if(a < b)   return 0;
  if(a == b)  return 1;
  if(b > a - b)   b = a - b;
  LL ans = frac[a]*exp_mod(frac[b], p-2, p)%p*exp_mod(frac[a-b], p-2, p)%p;
  return ans;
}

LL Lucas(LL n, LL m, LL p)
{
   LL ans = 1;
   while(n&&m&&ans) 
   {
      ans = (ans*Comb(n%p, m%p, p)) % p;
      n /= p;
      m /= p;
   }
   return ans;
}


LL get_ans(LL dx, LL dy)
{
  if (dx==0 && dy==0) return 1;
  if (dx<=0 || dy<=0) return 0;
  if (dx*2<dy || dy*2<dx) return 0;
  if ((dx*2-dy)%3 || (dy*2-dx)%3) return 0;
  LL x=(dx*2-dy)/3;
  LL y=(dy*2-dx)/3;
  return Lucas(x+y, y, oo);
}

LL f[maxn][maxn], ta[maxn];
LL n,m;
int p;
LL ans, arr[maxn];


int main()
{
  //freopen("data.in", "r", stdin);
  int o=0;
  frac[0]=1;
  for (int i=1;i<=oo;i++) frac[i]=frac[i-1]*i%oo;
  while (scanf("%I64d%I64d%d",&n,&m,&p)!=EOF)
  {
    LL tx, ty;
    ans = 0;
    pot.clear();
    for (int i=1;i<=p;i++)
    {
      scanf("%I64d%I64d",&tx,&ty);
      pot.push_back(pll(tx, ty));
    }
    /*
    pot.push_back(pll(1,1));
    pot.push_back(pll(n,m));
    p += 2;
    sort(pot.begin(), pot.end());
    for(int i = 0; i < p; i++)
      for (int j = i+1; j < p; j++)
        f[i][j] = get_ans(pot[j].X - pot[i].X, pot[j].Y - pot[i].Y);
    for (int i = 1; i < p; i++)
      arr[i] = f[0][i];
    for (int i = 1; i < p; i++)
      for (int j = i+1; j < p; j++)
        arr[j] = ((arr[j] - arr[i]*f[i][j])%oo+oo)%oo;
    printf("Case #%d: %I64d\n",++o,arr[p-1]);
    continue;
    */
    sort(pot.begin(), pot.end());
    for (int i = 0; i < p; i++)
    {
      ta[i] = get_ans(pot[i].X-1, pot[i].Y-1);
      for (int j = 0; j < i; j++)
      {
        if (pot[j].X <= pot[i].X && pot[j].Y <= pot[i].Y)
          ta[i] = ((ta[i] - ta[j]*get_ans(pot[i].X - pot[j].X, pot[i].Y - pot[j].Y)%oo)%oo + oo) % oo;
      }
      //printf("tmp = %I64d\n", tmp);
      ans = (ans + ta[i] * get_ans(n-pot[i].X, m - pot[i].Y)) % oo;
    }

    ans = ((get_ans(n-1, m-1) - ans)%oo + oo)%oo;

    printf("Case #%d: %I64d\n",++o,ans);
  }
  return 0;
}
