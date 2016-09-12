#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+20;

long long a[maxn];
long long b[maxn];



int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++)
    b[i] = a[i]+a[i+1];
  
  for (int i = 1; i <= n; i++)
    cout << b[i] << " ";
  cout << endl;

}
