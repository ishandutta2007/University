// 把整数 n 拆分成几个数相加的形式， 问有多少种拆分方法
int dp[maxn];
void splitint()
{
  memset(dp, 0, sizeof(dp));
  dp[0]=1;
  for(int i = 1; i <= maxn; i++)
  {
    for(int j = 1, r = 1; i - (3*j*j-j)/2 >= 0; j++, r*=-1)
    {
      dp[i] += dp[i-(3*j*j-j)/2]*r;
      dp[i] %= MOD;
      dp[i] = (dp[i]+MOD)%MOD;
      if(i-(3*j*j+j)/2 >= 0)
      {
        dp[i] += dp[i-(3*j*j+j)/2] *r;
        dp[i] %= MOD;
        dp[i] = (dp[i] + MOD)%MOD;
      }
    }
  }
}
