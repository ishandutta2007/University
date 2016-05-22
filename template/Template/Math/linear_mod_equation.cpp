// 线性方程求解
// ax = b (mod n)
vector<LL> linear_mod_equation(LL a, LL b, LL n)
{
  LL x, y, d;
  vector<LL> sol;
  sol.clear();
  EXT_GCD(a, n, d, x, y);
  if( b%d ) d = 0;
  else
  {
    sol.push_back(x * (b/d) % n);
    for (int i = 1; i < d; i++)
      sol.push_back((sol[i-1] + n/d + n) % n);
  }
  return sol;
}
