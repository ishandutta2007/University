// 慢速乘
// a * b % p;
LL slow_mul(LL a, LL b, LL p)
{
  LL ret = 0;  
  while(b) {  
    if(b & 1) ret = (ret + a) % p;  
    a = (a + a) % p;
    b >>= 1;  
  }  
  return ret % p;  
}
