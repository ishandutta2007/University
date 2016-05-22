// 中国剩余定理
// x ≡ a[i] (mod m[i])
// m[i] is coprime
LL CRT(LL *a, LL *m, int n)
{
  LL M = 1, Mi, x0, y0, d, ret = 0;
  for(int i = 0; i < n; i++)
    M *= m[i];
  for(int i = 0; i < n; i++)
  {
    Mi = M/m[i];
    EXT_GCD(Mi, m[i], d, x0, y0);
    ret = (ret+Mi*x0*a[i]) % M;
  }
  if(ret < 0)
    ret += M;
  return ret;
}
