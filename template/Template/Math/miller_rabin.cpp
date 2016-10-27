LL witness(LL a,LL b,LL c)
{
  if(b==0)return 1;
  LL x,y,t=0;
  while((b&1)==0)
    b>>=1,t++;
  // pow_mod() 可能需要慢速乘
  y=x=pow_mod(a,b,c);
  // 二次探测
  while(t--)
  {
    y=slow_mul(x,x,c);
    if(y==1 && x!=1 && x!=c-1)
      return false;
    x=y;
  }
  return y==1;
}
bool miller_rabin(LL n)
// ..质数为true, 非质数为false..
{
  if(n==2)return true;
  if(n<2 || (n&1)==0)return false;
  for(int i=0;i<3;i++)
    if(witness(rand()%(n-2)+2,n-1,n)!=1)
      return false;
  return true;
}
