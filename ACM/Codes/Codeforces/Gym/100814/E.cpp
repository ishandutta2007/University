#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


typedef long long LL;
typedef pair<int, int> PII;

PII dp2[120][120], dp3[120][120], dp6[120][120], ap[120][120];
int a[120][120];
int n, m;

PII operator + (PII a, PII b)
{
  return PII(a.first + b.first, a.second + b.second);
}

PII pmax(PII a, PII b)
{
  if (min(a.first, a.second) == min(b.first, b.second))
    return max(a.first, a.second) > max(b.first, b.second) ? a:b;
  return min(a.first, a.second) > min(b.first, b.second) ? a:b;
}

void update2(int i, int j)
{
  if(dp2[i-1][j].first > dp2[i][j-1].first)
    dp2[i][j] = dp2[i-1][j];
  else
    dp2[i][j] = dp2[i][j-1];
  dp2[i][j] = dp2[i][j] + ap[i][j];
}
void update3(int i, int j)
{
  if(dp3[i-1][j].second > dp3[i][j-1].second)
    dp3[i][j] = dp3[i-1][j];
  else
    dp3[i][j] = dp3[i][j-1];
  dp3[i][j] = dp3[i][j] + ap[i][j];
}

void update6(int i, int j)
{
  dp6[i][j] = pmax(dp6[i-1][j]+ap[i][j], dp6[i][j-1]+ap[i][j]);
  PII tmp1 = pmax(dp2[i-1][j]+ap[i][j], dp2[i][j-1]+ap[i][j]);
  PII tmp2 = pmax(dp3[i-1][j]+ap[i][j], dp3[i][j-1]+ap[i][j]);
  dp6[i][j] = pmax(dp6[i][j], pmax(tmp1, tmp2));
}


int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
      {
        ap[i][j] = dp6[i][j] = dp2[i][j] = dp3[i][j] = PII(0,0);
        scanf("%d", &a[i][j]);
        int tmp = a[i][j];
        if(tmp != 0)while(tmp % 2 == 0)
        {
          ap[i][j].first ++;
          tmp /= 2;
        }
        if(tmp != 0)while(tmp % 3 == 0)
        {
          ap[i][j].second ++;
          tmp /= 3;
        }
      }

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
      {
        update2(i, j);
        update3(i, j);
      }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
      {
        update6(i, j);
      }
    printf("%d\n", min(dp6[n][m].first, dp6[n][m].second));
  }
  return 0;
}