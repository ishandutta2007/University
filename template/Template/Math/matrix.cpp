//poj 3233
//cal (A + A^2 + A^3 + ... + A^K) % Mod
#define maxn 30
typedef long long LL;
struct Matrix{
  LL m[maxn][maxn];
  Matrix(){memset(m, 0, sizeof(m));}
};
typedef Matrix matrix;
LL Mod;
int n;
matrix operator* (matrix A, matrix B)
{
  matrix C;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
      C.m[i][j] = 0LL;
      for(int k = 0; k < n; k++)
        C.m[i][j] += A.m[i][k]*B.m[k][j];
      C.m[i][j] %= Mod;
    }
  return C;
}
matrix operator+ (matrix A, matrix B)
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      A.m[i][j] = (A.m[i][j] + B.m[i][j]) % Mod;
  return A;
}
matrix operator% (matrix A, LL m)
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      A.m[i][j] %= m;
  return A;
}
matrix matrix_pow(int k, matrix M)
{
  if(k == 1) return M;
  matrix ans;
  memset(ans.m, 0, sizeof(ans.m));
  for(int i = 0; i < n; i++)
    ans.m[i][i] = 1LL;
  while(k)
  {
    if(k&1)
    {
      ans = ans * M;
      k--;
    }
    else
    {
      k /= 2;
      M = M * M;
    }
  }
  return ans;
}
matrix sum(matrix ma, int k)
{
  matrix ret;
  if(k == 1) return ma;
  if(k&1)
  {
    matrix tmp = sum(ma, k/2) % Mod, tmp1 = matrix_pow(k/2+1, ma) % Mod;
    ret = (tmp + tmp1 + tmp * tmp1) % Mod;
  }
  else
  {
    matrix tmp = sum(ma, k/2) % Mod, tmp1 = matrix_pow(k/2, ma) % Mod;
    ret = (tmp + tmp * tmp1) % Mod;
  }
  return ret;
}
int main()
{
  int k;
  matrix A;
  scanf("%d%d%lld", &n, &k, &Mod);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%lld", &A.m[i][j]);
  A = sum(A, k);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
      printf("%lld%c", A.m[i][j],(j == n-1)? '\n':' ');
    }
  return 0;
}
