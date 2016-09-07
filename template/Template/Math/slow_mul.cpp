// 慢速乘
// a * b % p;
LL slow_mul(LL a, LL b, LL p)
{
  if (b < 0 && a >= 0) swap(a, b);
  else if (a < 0 && b < 0) {a = -a; b = -b;}
  LL ret = 0;  
  while(b) {  
    if(b & 1) ret = (ret + a) % p;  
    a = (a + a) % p;
    b >>= 1;  
  }  
  return ret % p;  
}
