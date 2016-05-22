// 判断Mp = 2^p-1 是否为梅森素数
bool lucas_lehmer(int p)
{
  if(p == 2) return true;
  LL m = (1LL<<p)-1LL, tmp = 4LL;
  for(int i = 0; i < p-2; i++)
  {
    tmp = (slow_mul(tmp, tmp, m) - 2 + m) % m;
  }
  if(tmp == 0LL) return true;
  return false;
}
