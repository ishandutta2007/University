// 用扩展欧几里得求逆元
// 要求 a, c 互质
// 如果没有逆元返回 -1
LL inv(LL a, LL c)
{
  LL d, x, y;
  EXT_GCD(a, c, d, x, y);
  return d == 1 ? (x + c) % c : -1;
}
