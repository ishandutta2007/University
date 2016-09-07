#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 1e9+7;
const int maxn = 100020;



int main()
{
  int n;
  string str;
  int a, b;
  int flag = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> str >> a >> b;

    if (a >= 2400 && a < b)
      flag = 1;
  }

  printf("%s\n", flag? "YES":"NO");

  return 0;
}
