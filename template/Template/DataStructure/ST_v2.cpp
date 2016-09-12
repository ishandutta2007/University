const int maxn = 1e5+20;
int low[maxn][30];
void init(int *d) {
  for (int i = 1; i <= n; i++)
    low[i] = d[i];
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++) if (i+(1<<j)-1 <= n)
      low[i][j] = min(low[i][j-1], low[i+(1<<(j-1))][j-1]);
}
int query(int s, int e) {
  int k = log2(e-s+1);
  return min(low[s][k], low[e-(1<<k)+1][k]);
}
