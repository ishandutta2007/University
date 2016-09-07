#include <bits/stdc++.h>

using namespace std;


string a, ans;

void solve()
{
  ans.clear();
  for (char ch : a)
  {
    if (ans.length() == 0)
    {
      ans.push_back(ch);
      continue;
    }
    if (ans[0] <= ch)
      ans = ch + ans;
    else
      ans.push_back(ch);
  }
}


int main()
{
  int T;
  cin >> T;
  for (int ka = 1; ka <= T; ka++)
  {
    cin >> a;
    solve();
    
    cout << "Case #" << ka << ": " << ans << endl;

  }
  return 0;
}
