// 扩展欧几里得
// a >= 0, b > 0
LL ext_gcd(LL a, LL b, LL& x, LL& y)
{
  LL x1=0LL, y1=1LL, x0=1LL, y0=0LL;
  LL r = (a%b + b) % b;
  LL q = (a-r) / b;
  x = 0LL,y = 1LL;  
  while(r)
  {
    x=x0-q*x1;y=y0-q*y1;
    x0=x1;y0=y1;
    x1=x;y1=y;
    a=b;b=r;
    r=a%b;
    q=(a-r)/b;
  }
  return b;
}
