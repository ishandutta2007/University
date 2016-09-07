#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 1e9+7;
const int maxn = 100020;

ll x = 1234567, y = 123456, z = 1234;
ll n;

int main()
{
  cin >> n;

  for (int a = 0; a < 1000; a++)
    for (int b = 0; b < 10000; b++)
    {
      if (n - a*x - b*y >= 0 && (n-a*x-b*y)%z == 0)
      {
        printf("YES\n");
        return 0;
      }

    }

  printf("NO\n");

  return 0;
}
