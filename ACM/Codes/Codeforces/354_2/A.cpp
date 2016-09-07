#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100002;
const ll oo = (int)1e9+7;

int a[maxn];


int main()
{
  int ans = 0;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
    if (a[i] == 1 || a[i] == n)
    {
      ans = max(ans, max(n - i, i - 1));
    }
  }

  
  cout << ans << endl;


  return 0;
}
