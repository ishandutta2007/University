#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int n;

bool solve(int x)
{
  string s, sr;
  int tmp = n;
  while(tmp)
  {
    s.push_back(tmp%x);
    tmp /= x;
  }
  sr = s;
  reverse(s.begin(), s.end());
  return s == sr;
}



int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    ans.clear();
    for (int i = 2; i <= 16; i++)
    {
      if (solve(i))
        ans.push_back(i);
    }
    if (ans.size() == 0)
      printf("-1\n");
    else
      for (int i = 0, len = ans.size(); i < len; i++)
        printf("%d%c", ans[i], i == len-1? '\n':' ');
  }

  return 0;
}
