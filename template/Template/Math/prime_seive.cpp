// 筛法求质数
// prime[] 储存质数。1-based index;
const int maxn = 100020;
bool isprime[maxn];
LL prime[maxn];
int doprime(LL N)
{
  int nprime = 0;
  memset(isprime, true, sizeof(isprime));
  isprime[1] = false;
  for(LL i = 2; i <= N; i++)
  {
    if(isprime[i])
    {
      prime[++nprime] = i;
      for(LL j = i*i; j <= N; j+=i)
        isprime[j] = false;
    }
  }
  return nprime;
}
