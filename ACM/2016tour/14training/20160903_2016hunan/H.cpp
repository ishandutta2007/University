#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
vector<int> a[maxn];



void table(int n)
{
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      for (int s = 1; s < i; s++)
        a[s].push_back(s);
      for (int s = j+1; s <= n; s++)
        a[s].push_back(s);
      int cnt = j-i+1;
      for (int d = 0; d < cnt/2; d++)
        a[i+d].push_back()
    }
}




int main()
{
  for (int n = 1; n <= 10; n++)
  {
    for (int i = 1; i <= n; i++)
      a[i].clear();
    table(n);
  }
  return 0;
}
