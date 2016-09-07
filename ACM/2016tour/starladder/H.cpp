#include <bits/stdc++.h>
#define first X
#define second Y


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;


int main()
{
  int n;
  cin >> n;
  n += 2;
  if (n > 7) n -= 7;

  cout << n << endl;
  return 0;
}
