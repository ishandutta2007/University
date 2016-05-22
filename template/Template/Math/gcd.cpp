// 非递归
LL gcd(LL a,LL b)
{
  if (a < b) swap(a, b);
  LL Rem;
  while(b > 0)
  {
    Rem = a % b;
    a = b;
    b = Rem;
  }
  return a;
}
