#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;
int n, k;

int main()
{
  scanf("%d%d", &n,&k);
  
  int tmp;
  for (int i = 1; i <= k; i++)
  {
    scanf("%d", &tmp);
    mp[tmp] = i;
  }

  for (auto x : mp)
  {
    for (int tmp = x.first*2; tmp <= n; tmp += x.first)
    {
      if (mp.count(tmp))
      {
        printf("%d %d\n", x.second, mp[tmp]);
        return 0;
      }
    }
  }
  printf("0 0\n");
  return 0;
}
