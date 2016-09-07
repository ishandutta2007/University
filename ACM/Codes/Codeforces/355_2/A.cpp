#include <bits/stdc++.h>
using namespace std;
const int maxn = 20002;
const int oo = (int)1e9 + 7;
typedef pair<int, int> pii;
typedef vector<int> vi;

int ans;

int main()
{
  int n, h;
  scanf("%d%d", &n, &h);
  ans = 0;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);

    if (tmp > h) ans += 2;
    else ans += 1;
  }
  
  cout << ans << endl;

  return 0;
}
