// 解 n 个一元线性同于方程组
// x ≡ r (mod a)
// 求x
LL mega_mod(int n)
{
  LL a1, a2, r1, r2, d, c, x, y, x0,s;
  bool flag = true;
  scanf("%lld%lld", &a1, &r1);
  for(int i = 1; i < n; i++)
  {
    scanf("%lld%lld", &a2, &r2);
    if(!flag) continue;
    c = r2 - r1;
    EXT_GCD(a1, a2, d, x, y);
    if(c%d!=0)
    {
      flag = false;
      continue;
    }
    x0 = x*c/d;
    s = a2/d;
    x0 = (x0%s+s)%s;
    r1=r1+x0*a1;
    a1=a1*a2/d;
  }
  if(flag) return r1;
  else return -1LL;
}
