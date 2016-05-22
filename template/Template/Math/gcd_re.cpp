// 递归求gcd
LL GCD(LL a, LL b)
{
  if(a < b) swap(a, b);
  LL r = a % b;
  if(r == 0) return b;
  return GCD(b, r);
}
