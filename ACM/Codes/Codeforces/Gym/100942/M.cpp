#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxN = 1000020;
const int oo = 0x3f3f3f3f;
LL gcd(LL M,LL N)
//非递归
{
  if (M < N) swap(M, N);
  LL Rem;
  while(N > 0)
  {
    Rem = M % N;
    M = N;
    N = Rem;
  }
  return M;
}

LL lcm(LL M, LL N)
{
  return M*N / gcd(M, N);
}


LL a[10], b[10];


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
  }

  LL ansa = a[0], ansb = b[0];

  for (int i = 1; i < n; i++)
  {
    ansa = lcm(ansa, a[i]);
    ansb = gcd(ansb, b[i]);
  }

  cout << ansa << " " << ansb << endl;

  return 0;
}
