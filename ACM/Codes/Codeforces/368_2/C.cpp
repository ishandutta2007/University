#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char bf[10];
ll a, b, x;


int main()
{
  cin >> x;

  if (x < 3)
  {
    printf("-1\n");
    return 0;
  }

  ll x2 = x*x;

  if (x % 2 == 1)
  {
    a = (x2+1) / 2;
    b = a - 1;
  }
  else
  {
    a = x2/4 + 1;
    b = a - 2;
  }
  
  cout << a << " " << b << endl;

  return 0;
}
