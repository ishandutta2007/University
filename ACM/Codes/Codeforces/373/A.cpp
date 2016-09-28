/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int oo = 1e9+7;
const int maxn = 1e4+20;

int a[maxn];
int n;


int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  if (a[n] == 0) {
    cout << "UP" << endl;
    return 0;
  }
  else if (a[n] == 15) {
    cout << "DOWN" << endl;
    return 0;
  }

  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (a[n] > a[n-1]) {
    cout << "UP" << endl;
  }
  else {
    cout << "DOWN" << endl;
  }
  return 0;
}

