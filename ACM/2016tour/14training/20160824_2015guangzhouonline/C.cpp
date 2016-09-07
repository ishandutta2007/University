#include <bits/stdc++.h>
#define right rightx
#define left leftx



using namespace std;

const int maxn = 120;

char mp[maxn][maxn];
int n;
int up[maxn][maxn];
int down[maxn][maxn];
int left[maxn][maxn];
int right[maxn][maxn];
int cnt1[maxn][maxn];
int cnt2[maxn][maxn];
int cnt3[maxn][maxn];
int cnt4[maxn][maxn];

void doleft()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      left[i][j] = mp[i][j] == '.'? 1:0;
      if (j-1 >= 0 && mp[i][j] == '.')
        left[i][j] += left[i][j-1];
    }
}
void doright()
{
  for (int i = 0; i < n; i++)
    for (int j = n-1; j >= 0; j--)
    {
      right[i][j] = mp[i][j] == '.'? 1:0;
      if (j+1 < n && mp[i][j] == '.')
        right[i][j] += right[i][j+1];
    }
}
void doup()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      up[i][j] = mp[i][j] == '.'? 1:0;
      if (i-1 >= 0 && mp[i][j] == '.')
        up[i][j] += up[i-1][j];
    }
}
void dodown()
{
  for (int i = n-1; i>=0; i--)
    for (int j = 0; j < n; j++)
    {
      down[i][j] = mp[i][j] == '.' ? 1:0;
      if (i+1 < n && mp[i][j] == '.')
        down[i][j] += down[i+1][j];
    }
}

void do1()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      cnt1[i][j] = mp[i][j] == '.'? 1:0;
      if (i-1>=0 && j-1>=0 && mp[i][j] == '.')
        cnt1[i][j] += cnt1[i-1][j-1];
    }
}
void do2()
{
  for (int i = 0; i < n; i++)
    for (int j = n-1; j >= 0; j--)
    {
      cnt2[i][j] = mp[i][j] == '.'? 1:0;
      if (i-1>=0 && j+1 < n && mp[i][j] == '.')
        cnt2[i][j] += cnt2[i-1][j+1];
    }
}
void do3()
{
  for (int i = n-1; i >= 0; i--)
    for (int j = 0; j < n; j++)
    {
      cnt3[i][j] = mp[i][j] == '.'? 1:0;
      if (i+1<n && j-1>=0 && mp[i][j] == '.')
        cnt3[i][j] += cnt3[i+1][j-1];
    }
}

void do4()
{
  for (int i = n-1; i>=0; i--)
    for (int j = n-1; j>=0; j--)
    {
      cnt4[i][j] = mp[i][j] == '.'? 1:0;
      if (i+1 < n && j+1 <n && mp[i][j] == '.')
        cnt4[i][j] += cnt4[i+1][j+1];
    }
}


int cal(int x, int y)
{
  int ret = 0;
  ret = max(ret, left[x][y]+up[x][y]);
  ret = max(ret, cnt1[x][y]+cnt2[x][y]);
  ret = max(ret, up[x][y]+right[x][y]);
  ret = max(ret, cnt2[x][y]+cnt4[x][y]);
  ret = max(ret, right[x][y]+down[x][y]);
  ret = max(ret, cnt4[x][y]+cnt3[x][y]);
  ret = max(ret, down[x][y]+left[x][y]);
  ret = max(ret, cnt1[x][y]+cnt3[x][y]);
  return ret-1;
}


int main()
{

  while(scanf("%d", &n)!=EOF)
  {
    if (n==0) break;
    for (int i = 0; i < n; i++)
      scanf("%s", mp[i]);
    doup();
    dodown();
    doleft();
    doright();
    do1();
    do2();
    do3();
    do4();
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) if (mp[i][j] == '.')
      {
        ans = max(ans, cal(i, j));
      }
    printf("%d\n", ans);
  }
  return 0;
}
