#include <bits/stdc++.h>
#define first X
#define second Y


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;

int ans[2];

int main()
{
  int n;
  cin >> n;
  int x;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    ans[x%2]++;
  }

  cout << ans[1] << " " << ans[0] << endl;

  return 0;
}
