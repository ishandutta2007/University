// 欧拉函数预处理
int phi[maxn];
void getpthi(int n)
{
  memset(phi, 0, sizeof(phi));
  phi[1] = 1;
  for(int i = 2; i <= n; i++)if(!phi[i])
  {
    for(int j = i; j <= n; j+=i)
    {
      if(!phi[j])
        phi[j] = j;
      phi[j] = phi[j]/i*(i-1);
    }
  }
}
