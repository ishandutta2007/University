// 递归求逆元
// p, x 互质
LL inv(LL x, LL m)
{
  if (x == 1) return x;
  return inv(m % x, m)*(m - m / x) % m;
}
