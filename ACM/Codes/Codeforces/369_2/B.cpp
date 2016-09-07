#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 10020;
const int oo = 1e9+7;
typedef pair<int,int> pii;
typedef long long ll;


char bf[maxn][10];


int main()
{
  #ifndef ONLINE_JUDGE
  //freopen("data.in", "r", stdin);
  #endif

  int n;
  scanf("%d", &n);
  bool flag = false;
  for (int i = 0; i < n; i++)
  {
    scanf("%s", bf[i]);
    if (bf[i][0]=='O' && bf[i][1] == 'O' && !flag)
    {
      flag = true;
      bf[i][0] = '+';
      bf[i][1] = '+';
    }
    if (bf[i][3]=='O' && bf[i][4] == 'O' && !flag)
    {
      flag = true;
      bf[i][3] = '+';
      bf[i][4] = '+';
    }

  }

  if (flag)
  {
    printf("YES\n");
    for (int i = 0; i < n; i++)
      printf("%s\n", bf[i]);
  }

  else
    printf("NO\n");


  return 0;
}
