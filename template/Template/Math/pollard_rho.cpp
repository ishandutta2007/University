// ..随机返回一个 n 的约数..
LL ans = INF;
LL pollard_rho(LL n,LL c)
{
  if(n%2==0)return 2;
  LL i=1,k=2,x=rand()%n,y=x,d;
  while(1){
    i++;
    x=(slow_mul(x,x,n)+c)%n;
    d=gcd(y-x,n);
    if(d==n)return n;
    if(d!=n && d>1)return d;
    if(i==k) y=x,k<<=1;
  }
}
void calc(LL n,LL c=240)
// 寻找最小的约数..
{
  if(n==1)return;
  if(miller_rabin(n)){
    ans=min(ans,n);
    return;
  }
  LL k=n;
  while(k==n)k=pollard_rho(n,c--);
  calc(k,c),calc(n/k,c);
}
