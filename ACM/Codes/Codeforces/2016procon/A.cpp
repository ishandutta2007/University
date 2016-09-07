#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a[3], w;

  cin >> a[0] >> a[1] >> a[2] >> w;
  
  sort(a, a + 3);

  if (w <= a[1] + a[2]) cout << "YES" << endl;
  else cout << "NO" << endl;


  return 0;
}
