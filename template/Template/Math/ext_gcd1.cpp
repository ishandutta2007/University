// 扩展欧几里得
// a , b 任意
void EXT_GCD(LL a, LL b, LL &d, LL &x, LL &y)
{
  if(!b) {d = a, x = 1, y = 0;}
  else {EXT_GCD(b, a % b, d, y, x), y -= x * (a / b);}
}
